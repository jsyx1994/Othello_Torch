//
// Created by mro on 2019/10/23.
//

#ifndef OTHELLO_TORCH_TREENODE_H
#define OTHELLO_TORCH_TREENODE_H

#include <vector>

#include "settings.h"


using boardType = std::vector<std::vector<COLOR>> ;

class TreeNode {
public:
	
	TreeNode();
	
	COLOR getSideColor() const;
	
	void setSideColor(COLOR sideColor);
	
	int getBlackPieceCounts() const;
	
	void setBlackPieceCounts(int blackPieceCounts);
	
	int getWhitePieceCounts() const;
	
	void setWhitePieceCounts(int whitePieceCounts);
	
	long long int getVisits() const;
	
	void setVisits(long long int visits);
	
	double getReturns() const;
	
	void setReturns(double returns);
	
	const boardType &getBoard() const;
	
	void setBoard(const boardType &board);

private:
	COLOR sideColor;
	boardType board;
	
	int blackPieceCounts;
	int whitePieceCounts;
	
	long long visits;
	double returns;
};


#endif //OTHELLO_TORCH_TREENODE_H
