//
// Created by mro on 2019/10/23.
//

#include "TreeNode.h"

COLOR TreeNode::getSideColor() const {
	return sideColor;
}

void TreeNode::setSideColor(COLOR sideColor) {
	TreeNode::sideColor = sideColor;
}

int TreeNode::getBlackPieceCounts() const {
	return blackPieceCounts;
}

void TreeNode::setBlackPieceCounts(int blackPieceCounts) {
	TreeNode::blackPieceCounts = blackPieceCounts;
}

int TreeNode::getWhitePieceCounts() const {
	return whitePieceCounts;
}

void TreeNode::setWhitePieceCounts(int whitePieceCounts) {
	TreeNode::whitePieceCounts = whitePieceCounts;
}

long long int TreeNode::getVisits() const {
	return visits;
}

void TreeNode::setVisits(long long int visits) {
	TreeNode::visits = visits;
}

const BoardType &TreeNode::getBoard() const {
	return board;
}

void TreeNode::setBoard(const BoardType &board) {
	TreeNode::board = board;
}

TreeNode::TreeNode():
		sideColor(COLOR::Null),
		board(BoardSizeY, std::vector<COLOR> (BoardSizeX, COLOR::Null)),
		children({}),
		blackPieceCounts(0),
		whitePieceCounts(0),
		visits(0),
		_Q(.0f),
		weights(.0f){}

const CoordinateType &TreeNode::getLastPlayerAction() const {
	return lastPlayerAction;
}

void TreeNode::setLastPlayerAction(const CoordinateType &lastPlayerAction) {
	TreeNode::lastPlayerAction = lastPlayerAction;
}

TreeNode::TreeNode(BoardType gridInfo):board(gridInfo) {
}

double TreeNode::getQ() const {
	return _Q;
}

void TreeNode::setQ(double q) {
	_Q = q;
}
