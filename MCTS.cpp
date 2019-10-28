//
// Created by mro on 2019/10/24.
//

#include "MCTS.h"
#include <cmath>
#include <algorithm>

MCTS::MCTS(BoardType gridInfo, COLOR color, int blackPieceCounts, int whitePieceCounts) : position(gridInfo),
                                                                                          sideColor(color) {
	srand(time(NULL));
	
	rootPos = new TreeNode(gridInfo);
	rootPos->setSideColor(color);
	rootPos->setBlackPieceCounts(blackPieceCounts);
	rootPos->setWhitePieceCounts(whitePieceCounts);
	rootPos->setLastPlayerAction(std::make_pair(-1, -1));
	
	
	auto leaf = TreePolicy();
}

double MCTS::CalcUCB1(TreeNode *node, long long n) {
	double n_j = node->getVisits();
	if (n_j == 0) return Inf;
	double Q = node->getQ();
	double U = C * std::sqrt(std::log(n) / n_j);
	node->setWeights(Q + U);
	return Q + U;
//	return node->getQ() + node->
}

TreeNode *MCTS::chooseBestChild(TreeNode *father) {
	auto children = father->getChildren();
	return *std::max_element(children.begin(), children.end(),
	                         [](TreeNode *x, TreeNode *y) { return x->getWeights() < y->getWeights(); });
}

TreeNode *MCTS::TreePolicy() {
	TreeNode *pawn = rootPos;
	long long fatherVisits = pawn->getVisits();
	while (pawn->HasChild()) {
		pawn = chooseBestChild(pawn);
	}
	return pawn;
}

void MCTS::Expandition(TreeNode *leaf) {

}




