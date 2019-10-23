//
// Created by mro on 2019/10/23.
//

#ifndef OTHELLO_TORCH_GAME_H
#define OTHELLO_TORCH_GAME_H

#include <string>
#include "settings.h"

class Game {
public:
	Game();
	
	void LoadFromJson();
	
	bool MoveStep(int &x, int &y, int Direction);
	bool ProcStep(BoardType &gridInfo, int xPos, int yPos, COLOR color, bool checkOnly = false);
	bool CheckIfHasValidMove(BoardType &gridInfo,const COLOR &color);
	bool ChangeColor(COLOR &color);
	COLOR Opponent(const COLOR &myColor);
	void PrintBoard();
	std::pair<int ,int> RandomPolicy();
	void OutputToJson(int x, int y);
private:
	std::vector<std::vector<int>> effectivePoints;
	COLOR currBotColor;
	BoardType gridInfo;
	int blackPieceCounts = 2, whitePieceCounts = 2;
	
};


#endif //OTHELLO_TORCH_GAME_H
