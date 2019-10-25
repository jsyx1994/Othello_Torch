//
// Created by mro on 2019/10/23.
//

#ifndef OTHELLO_TORCH_GAME_H
#define OTHELLO_TORCH_GAME_H

#include <string>
#include <vector>
#include "settings.h"

class Game {
public:
	Game();
	void LoadFromJson(BoardType &gridInfo, int &whitePieceCounts, int &blackPieceCounts);
	bool MoveStep(int &x, int &y, int Direction);
	bool ProcStep(BoardType &gridInfo,int &blackPieceCounts, int &whitePieceCounts, int xPos, int yPos, COLOR color, bool checkOnly = false);
	bool CheckIfHasValidMove(BoardType &gridInfo,int &blackPieceCounts, int &whitePieceCounts, const COLOR &color);
	
	bool ChangeColor(COLOR &color);
	COLOR Opponent(const COLOR &myColor);
	void PrintBoard(const BoardType &gridInfo) const;
	void OutputToJson(int x, int y);
	
	bool isGameEnded(BoardType &gridInfo, int whitePieces, int blackPieces);
	COLOR judgeWinner(const int whitePieces, const int blackPieces) const;
	
	COLOR getCurrBotColor() const;
	
	BoardType &getGridInfo();
	
	std::pair<int ,int> RandomPolicy(BoardType &girdInfo, int &blackPieceCounts, int &whitePieceCounts);
	
	int getBlackPieceCounts() const;
	
	void setBlackPieceCounts(int blackPieceCounts);
	
	int getWhitePieceCounts() const;
	
	void setWhitePieceCounts(int whitePieceCounts);
	
	void setCurrBotColor(COLOR currBotColor);

private:
	std::vector<std::vector<int>> effectivePoints;
	COLOR currBotColor;
//	BoardType gridInfo;
//	int blackPieceCounts;
//	int whitePieceCounts;
	
};


#endif //OTHELLO_TORCH_GAME_H
