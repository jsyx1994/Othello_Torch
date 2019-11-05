//
// Created by mro on 2019/10/23.
//

#include "TreeNode.h"

TreeNode::TreeNode(const Game &situation, int xPos, int yPos) : situation(
		situation), lastPlayerAction(std::make_pair(xPos, yPos)), children({}), visits(0), _Q(.0f), weights(0.0f) {}

long long int TreeNode::getVisits() const {
	return visits;
}

void TreeNode::setVisits(long long int visits) {
	TreeNode::visits = visits;
}


const CoordinateType &TreeNode::getLastPlayerAction() const {
	return lastPlayerAction;
}

void TreeNode::setLastPlayerAction(const CoordinateType &lastPlayerAction) {
	TreeNode::lastPlayerAction = lastPlayerAction;
}


const double& TreeNode::getQ() const {
	return _Q;
}

void TreeNode::setQ(double q) {
	_Q = q;
}

const Children &TreeNode::getChildren() const {
	return children;
}


double TreeNode::getWeights() const {
	return weights;
}

void TreeNode::setWeights(double weights) {
	TreeNode::weights = weights;
}

Game & TreeNode::getSituation() {
	return situation;
}

void TreeNode::addChild(TreeNode *child) {
	this->children.push_back(child);
}


