//
// Created by mro on 2019/10/24.
//

#ifndef OTHELLO_TORCH_MCTS_H
#define OTHELLO_TORCH_MCTS_H

#include "Game.h"
#include "TreeNode.h"

const double C = .5f;

class MCTS {
public:
	MCTS();
	~MCTS();
	void TreePolicy();
	void Expandition();
	void DefaultPolicy();
	void BackPropagation();
private:
	BoardType position;
	TreeNode *rootPos;
};


#endif //OTHELLO_TORCH_MCTS_H
