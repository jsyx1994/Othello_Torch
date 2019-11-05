#include <iostream>
#include <ctime>
#include <random>

#include "TreeNode.h"
#include "Game.h"
#include "MCTS.h"
using dem = std::map<std::pair<int ,int>, int>;
void demo(){
	BoardType myBoard(BoardSizeY, std::vector<COLOR> (BoardSizeX, COLOR::Null));
	Game *game = new Game;
	game->LoadFromJson();
	game->PrintBoard();
	std::pair<int, int> ss;
	ss = game->RandomPolicy();
	game->ProcStep(ss.first, ss.second, game->getSideColor());
	game->PrintBoard();
	
//	MCTS *mcts = new MCTS(myBoard, game->getCurrBotColor(), bp, wp);
//
}
void randomDemo(){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(.0, 1.0);
	std::uniform_int_distribution<int> dist_(0,9);
	for (int i=0; i<100; ++i)
	std::cout << dist_(mt) << "\n";
}
int main() {
	Game game;
	game.LoadFromJson();
	game.PrintBoard();
//	for (auto a:game.getValidSteps()){
//		std::cout << a.first << " " << a.second << std::endl;
//	}
	MCTS *mcts = new MCTS(game);
//	dem s;
//	s[{1,1}] = 1;
//	std::map<std::string, int> ss;
//	ss["sfad"] = 113;
//	std::cout << s.size();
//	demo();
}