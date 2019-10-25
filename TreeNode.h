//
// Created by mro on 2019/10/23.
//

#ifndef OTHELLO_TORCH_TREENODE_H
#define OTHELLO_TORCH_TREENODE_H

#include <vector>
#include <algorithm>

#include "settings.h"
class TreeNode {
public:
	
	TreeNode();
	TreeNode(BoardType gridInfo);
	
	COLOR getSideColor() const;
	
	void setSideColor(COLOR sideColor);
	
	int getBlackPieceCounts() const;
	
	void setBlackPieceCounts(int blackPieceCounts);
	
	int getWhitePieceCounts() const;
	
	void setWhitePieceCounts(int whitePieceCounts);
	
	const CoordinateType &getLastPlayerAction() const;
	
	void setLastPlayerAction(const CoordinateType &lastPlayerAction);
	
	long long int getVisits() const;
	
	void setVisits(long long int visits);
	
	const BoardType &getBoard() const;
	
	void setBoard(const BoardType &board);
	
	double getQ() const;
	
	void setQ(double q);


private:
	COLOR sideColor;
	BoardType board;
	CoordinateType lastPlayerAction;
	std::vector<TreeNode*> children;
	
	int blackPieceCounts;
	int whitePieceCounts;
	
	long long visits;
	double _Q;
	
	double weights;
};


#endif //OTHELLO_TORCH_TREENODE_H
