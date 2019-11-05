//
// Created by mro on 2019/10/23.
//

#ifndef OTHELLO_TORCH_GAME_H
#define OTHELLO_TORCH_GAME_H

#include <string>
#include <vector>
#include <random>

#include "settings.h"
class Game {
public:
	Game();
	static bool MoveStep(int &x, int &y, int Direction);
	bool CheckIfHasValidMove(const COLOR &color);
	
	void LoadFromJson();
	bool ProcStep(int xPos, int yPos, COLOR color, bool checkOnly = false);
	
	
	bool ChangeColor(COLOR &color);// change the color of the stone
	
	void exchange();//change the side color
	
	COLOR Opponent(const COLOR &myColor);
	
	void PrintBoard() const;
	void OutputToJson(int x, int y);
	
	bool isGameEnded();
	COLOR judgeWinner() const;
	
	COLOR getSideColor() const;
	
	BoardType &getGridInfo();
	
	std::pair<int ,int> RandomPolicy();
	
	int getBlackPieceCounts() const;
	
	void setBlackPieceCounts(int blackPieceCounts);
	
	int getWhitePieceCounts() const;
	
	void setWhitePieceCounts(int whitePieceCounts);
	
	void setSideColor(COLOR color);
	
	std::vector<std::pair<int ,int>> getValidSteps();
	
	void smartRandom();
	
private:
	COLOR sideColor;
	BoardType gridInfo;
	int blackPieceCounts = 2;
	int whitePieceCounts = 2;
};


#endif //OTHELLO_TORCH_GAME_H
