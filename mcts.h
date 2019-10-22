//
// Created by toby on 2019/10/22.
//

#ifndef OTHELLO_TORCH_MCTS_H
#define OTHELLO_TORCH_MCTS_H

#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include "jsoncpp/json.h"

enum class COLOR{White = -1, Black = 1, Empty = 0};
const double timeLimit = 1;

class MCTSNode{
public:
    MCTSNode();
    ~MCTSNode();
    MCTSNode(COLOR color);
    bool setColor(COLOR color);
    COLOR getColor(COLOR color);

private:
    COLOR myColor = COLOR ::Empty;
    int visitTime = 0;
    double returns = 0;

    int blackPieceCounts = 0;
    int whiltPieceCounts = 0;
};


#endif //OTHELLO_TORCH_MCTS_H
