//
// Created by mro on 2019/10/23.
//
#include <iostream>
#include <vector>
#include <string>

#include "Game.h"
#include "jsoncpp/json.h"

static int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
static int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
static std::vector<std::vector<int>> effectivePoints(std::max(BoardSizeX, BoardSizeY), std::vector<int> (2));
/**
 * BotZone style of init
 * example input 1:   {"requests":[{"x":-1,"y":-1}],"responses":[]}
 * example input 2:   {"requests":[{"x":-1,"y":-1},{"x":2,"y":2},{"x":1,"y":3},{"x":3,"y":1},{"x":0,"y":2}],"responses":[{"x":2,"y":3},{"x":2,"y":1},{"x":1,"y":2},{"x":1,"y":4}]}
 **/
Game::Game():gridInfo(BoardSizeY,std::vector<COLOR> (BoardSizeX, COLOR::Null)) {
}


void Game::LoadFromJson() {
	int x, y;
	whitePieceCounts = 2;
	blackPieceCounts = 2;
	// 初始化棋盘
	gridInfo[3][4] = gridInfo[4][3] = COLOR::Black; //|白|黑|
	gridInfo[3][3] = gridInfo[4][4] = COLOR::White; //|黑|白|
	
	// 读入JSON
	std::string str;
	getline(std::cin, str);
	Json::Reader reader;
	Json::Value input;
	reader.parse(str, input);
	
	// 分析自己收到的输入和自己过往的输出，并恢复状态
	int turnID = input["responses"].size();
	sideColor = input["requests"][(Json::Value::UInt) 0]["x"].asInt() < 0 ? COLOR::Black : COLOR::White;//-1,-1 black
	COLOR opponentColor = Opponent(sideColor);
	
	for (int i = 0; i < turnID; i++) {
		// 根据这些输入输出逐渐恢复状态到当前回合
		x = input["requests"][i]["x"].asInt();
		y = input["requests"][i]["y"].asInt();
		if (x >= 0)
			ProcStep(x, y, opponentColor); // 模拟对方落子
		x = input["responses"][i]["x"].asInt();
		y = input["responses"][i]["y"].asInt();
		if (x >= 0)
			ProcStep(x, y, sideColor); // 模拟己方落子
	}
	
	// 看看自己本回合输入
	x = input["requests"][turnID]["x"].asInt();
	y = input["requests"][turnID]["y"].asInt();
	if (x >= 0)
		ProcStep(x, y, opponentColor); // 模拟对方落子
}

bool Game::MoveStep(int &x, int &y, int Direction) {
	x += dx[Direction], y += dy[Direction];
	if (x < 0 || x > 7 || y < 0 || y > 7)
		return false;
	return true;
}

bool Game::ProcStep(int xPos, int yPos, COLOR color, bool checkOnly) {
	
	int dir, x, y, currCount;
	bool isValidMove = false;
	if (gridInfo[xPos][yPos] != COLOR::Null)
		return false;
	for (dir = 0; dir < 8; dir++) {
		x = xPos;
		y = yPos;
		currCount = 0;
		while (1) {
			if (!MoveStep(x, y, dir)) {
				currCount = 0;
				break;
			}
			if (gridInfo[x][y] == COLOR::Null) {
				currCount = 0;
				break;
			} else if (gridInfo[x][y] != color) //enemy
			{
				currCount++;
				effectivePoints[currCount][0] = x;
				effectivePoints[currCount][1] = y;
			} else {
				break;
			}
		}
		if (currCount != 0) {
			isValidMove = true;
			if (checkOnly)
				return true;
			if (color == COLOR::Black) {
				blackPieceCounts += currCount;
				whitePieceCounts -= currCount;
			} else {
				whitePieceCounts += currCount;
				blackPieceCounts -= currCount;
			}
			while (currCount > 0) {
				x = effectivePoints[currCount][0];
				y = effectivePoints[currCount][1];
				ChangeColor(gridInfo[x][y]);
				currCount--;
			}
		}
	}
	if (isValidMove) {
		gridInfo[xPos][yPos] = color;
		if (color == COLOR::Black)
			blackPieceCounts++;
		else
			whitePieceCounts++;
		return true;
	} else
		return false;
}

bool Game::CheckIfHasValidMove(const COLOR &color) {
	int x, y;
	for (y = 0; y < 8; y++)
		for (x = 0; x < 8; x++)
			if (ProcStep(x, y, color, true))
				return true;
	return false;
}

bool Game::ChangeColor(COLOR &color) {
	if (color == COLOR::Null) {
		//there's no color for the position or piece, can not change color;
		return false;
	}
	color = color == COLOR::Black ? COLOR::White : COLOR::Black;
	return true;
}

COLOR Game::Opponent(const COLOR &myColor) {
	return myColor == COLOR::Black ? COLOR::White : COLOR::Black;
}

void Game::PrintBoard() const{
	std::cout << "Y X";
	for (int i = 0; i < 8; ++i) {
		std::cout << i << "  ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 8; ++i) {
		std::cout << i << "  ";
		for (int j = 0; j < 8; ++j) {
			if (gridInfo[j][i] == COLOR::White) {
				std::cout << "●  ";
			} else if (gridInfo[j][i] == COLOR::Black) {
				std::cout << "○  ";
			} else
				std::cout << "·  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::pair<int, int> Game::RandomPolicy() {
	auto actions = getValidSteps();
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, actions.size()-1);
	int resultX, resultY;
	if (!actions.empty()) {
		int choice = dist(mt);
		resultX = actions[choice].first;
		resultY = actions[choice].second;
	} else {
		resultX = -1;
		resultY = -1;
	}
	OutputToJson(resultX, resultY);
	return std::make_pair(resultX, resultY);
}

void Game::OutputToJson(int resultX, int resultY) {
	Json::Value ret;
	ret["response"]["x"] = resultX;
	ret["response"]["y"] = resultY;
	Json::FastWriter writer;
	std::cout << writer.write(ret) << std::endl;
}

COLOR Game::getSideColor() const {
	return sideColor;
}

bool Game::isGameEnded() {
	return (whitePieceCounts + blackPieceCounts >= BoardSizeX * BoardSizeY) ||
	       ((!CheckIfHasValidMove(COLOR::White)) && (!CheckIfHasValidMove(COLOR::Black)));
}

COLOR Game::judgeWinner() const {
	return whitePieceCounts == blackPieceCounts ? COLOR::Null : whitePieceCounts > blackPieceCounts ? COLOR::White : COLOR::Black;
}

void Game::setSideColor(COLOR color) {
	Game::sideColor = color;
}

void Game::exchange() {
	setSideColor(sideColor == COLOR::Black ? COLOR::White : COLOR::Black);
}

std::vector<std::pair<int, int>> Game::getValidSteps() {
	std::vector<std::pair<int ,int>> validSteps;
	for (int x = 0; x < BoardSizeX; ++x) {
		for (int y = 0; y < BoardSizeY; ++y) {
			if (ProcStep(x, y, sideColor, true))
				validSteps.push_back(std::make_pair(x, y));
		}
	}
	return validSteps;
}







