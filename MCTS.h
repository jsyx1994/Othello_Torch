//
// Created by mro on 2019/10/24.
//

#ifndef OTHELLO_TORCH_MCTS_H
#define OTHELLO_TORCH_MCTS_H

#include "Game.h"
#include "TreeNode.h"

const double C = .5f;
const double TimeLimit = 1.00f;
const double Inf = 10e8f;
/* **
 * Given the position and color, build root state and search from it
 * **/
class MCTS {
public:
	MCTS() = default;
	MCTS(BoardType gridInfo, COLOR color, int blackPieceCounts, int whitePieceCounts);
	~MCTS();
	TreeNode* TreePolicy();
	void Expandition(TreeNode *leaf);
	void DefaultPolicy();
	void BackPropagation();
	void exec();
	double CalcUCB1(TreeNode *node, long long n);
	TreeNode *chooseBestChild(TreeNode *father);
private:
	COLOR sideColor;
	BoardType position;
	TreeNode *rootPos = nullptr;
};


#endif //OTHELLO_TORCH_MCTS_H
