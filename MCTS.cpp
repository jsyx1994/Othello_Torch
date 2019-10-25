//
// Created by mro on 2019/10/24.
//

#include "MCTS.h"

MCTS::MCTS(BoardType gridInfo, COLOR color, int blackPieceCounts, int whitePieceCounts):position(gridInfo),sideColor(color){
	rootPos = new TreeNode(gridInfo);
	rootPos->setSideColor(color);
	rootPos->setBlackPieceCounts(blackPieceCounts);
	rootPos->setWhitePieceCounts(whitePieceCounts);
}
