#include <iostream>
#include <ctime>
#include <random>

#include "TreeNode.h"
#include "Game.h"
#include "MCTS.h"
void demo(){
	BoardType myBoard(BoardSizeY, std::vector<COLOR> (BoardSizeX, COLOR::Null));
	int bp, wp;
	Game *game = new Game;
	game->LoadFromJson(myBoard,wp, bp);
	game->PrintBoard(myBoard);
	std::cout << bp << " "  << wp<<std::endl;
	std::pair<int, int> ss;
	ss = game->RandomPolicy(myBoard,bp,wp);
	game->ProcStep(myBoard,bp,wp, ss.first, ss.second, game->getCurrBotColor());
	game->PrintBoard(myBoard);
	std::cout << bp << " "  << wp << std::endl;
	
	MCTS *mcts = new MCTS(myBoard, game->getCurrBotColor(), bp, wp);
	
}
void randomDemo(){
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(.0, 1.0);
		
		for (int i=0; i<16; ++i)
		std::cout << dist(mt) << "\n";
}
int main() {
	
    return 0;
}