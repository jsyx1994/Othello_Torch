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

double TreeNode::getReturns() const {
	return returns;
}

void TreeNode::setReturns(double returns) {
	TreeNode::returns = returns;
}

const BoardType &TreeNode::getBoard() const {
	return board;
}

void TreeNode::setBoard(const BoardType &board) {
	TreeNode::board = board;
}

TreeNode::TreeNode():
		sideColor(COLOR::Null),
		board(BoardSizeX, std::vector<COLOR> (BoardSizeY, COLOR::Null)),
		blackPieceCounts(0),
		whitePieceCounts(0),
		visits(0),
		returns(.0f) {}