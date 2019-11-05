//
// Created by mro on 2019/10/23.
//

#ifndef OTHELLO_TORCH_TREENODE_H
#define OTHELLO_TORCH_TREENODE_H

#include <vector>
#include <map>
#include <algorithm>

#include "settings.h"
#include "Game.h"
class TreeNode;
using Children = std::vector<TreeNode *>;

class TreeNode {
public:
	
	TreeNode() = default;
	TreeNode(const Game &situation, int xPos = -1, int yPos = -1);
	
	const CoordinateType &getLastPlayerAction() const;
	
	void setLastPlayerAction(const CoordinateType &lastPlayerAction);
	
	long long int getVisits() const;
	
	void setVisits(long long int visits);
	
	const BoardType &getBoard() const;
	
	void setBoard(const BoardType &board);
	
	const double& getQ() const;
	
	void setQ(double q);
	
	bool HasChild(){
		return !children.empty();
	}
	
	const Children &getChildren() const;
	
	double getWeights() const;
	
	void setWeights(double weights);
	
	Game & getSituation();
	
	void addChild(TreeNode *child);

private:
	Game situation;
	CoordinateType lastPlayerAction;
	Children children;
	long long visits;
	double _Q;
	double weights;
};


#endif //OTHELLO_TORCH_TREENODE_H
