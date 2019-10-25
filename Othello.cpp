#include <iostream>
#include <ctime>

#include "TreeNode.h"
#include "Game.h"
int main() {
	TreeNode x;
	Game game;
	game.LoadFromJson();
 	auto pair = game.RandomPolicy();
	game.PrintBoard();
	game.ProcStep(game.getGridInfo(), pair.first, pair.second, game.getCurrBotColor());
	game.PrintBoard();
	int y = 1;
	COLOR color = COLOR ::Black;
	double st = std::clock();
	for (int i = 0; i < 1000000; ++i) {
		y *= -1;
	}
	std::cout << (clock() - st) * 1000.0f / CLOCKS_PER_SEC << std::endl;
	st = std::clock();
	for (int j = 0; j < 1000000; ++j) {
		color = color == COLOR::Black ? COLOR::White : COLOR::Black;
	}
	std::cout << (clock() - st) * 1000.0f / CLOCKS_PER_SEC << std::endl;
	
	
	std::cout << x.getBoard()[0].size() << std::endl;
	auto a(x);
	std::cout << a.getBoard()[0].size() << std::endl;
	
	std::cout << int(COLOR ::White) << std::endl;
    return 0;
}