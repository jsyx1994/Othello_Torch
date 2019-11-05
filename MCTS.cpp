//
// Created by mro on 2019/10/24.
//

#include "MCTS.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <tcl.h>

using Position = Game;

MCTS::MCTS(Game startSit) {
	root = new TreeNode(startSit);
	auto leaf = TreePolicy();
	Expandition(leaf);
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
	Children children = father->getChildren();
	std::cout << typeid(children.begin()).name();
	return *std::max_element(children.begin(),children.end(),[](TreeNode *a, TreeNode *b){
		return a->getWeights() < b->getWeights();
	});
//	return nullptr;
//	return  std::max_element(children.begin()->second, children.end()->second,
//	                           [](TreeNode &x, TreeNode &y) {
//		                           return x.getWeights() < y.getWeights();
//	                           });
	
}

TreeNode *MCTS::TreePolicy() {
	TreeNode *pawn = root;
	long long fatherVisits = pawn->getVisits();
	while (pawn->HasChild()) {
		pawn = chooseBestChild(pawn);
	}
	return pawn;
}

void MCTS::Expandition(TreeNode *leaf) {
	Position pos = leaf->getSituation();
	auto actions = pos.getValidSteps();
	for (auto action : actions) {
		int xPos = action.first, yPos = action.second;
		std::cout << action.first << ' ' << action.second;
		Position newPos(pos);
		newPos.ProcStep(action.first, action.second, pos.getSideColor());
		newPos.exchange();  //enemies' turn
		TreeNode *childNode = new TreeNode(newPos, xPos, yPos);
		leaf->addChild(childNode);
	}
	
	
}
