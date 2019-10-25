//
// Created by mro on 2019/10/23.
//

#ifndef OTHELLO_TORCH_SETTINGS_H
#define OTHELLO_TORCH_SETTINGS_H


//define board constant
const int BoardSizeX = 8;
const int BoardSizeY = 8;
enum class COLOR { White = -1, Black = 1, Null = 0 };
using BoardType = std::vector<std::vector<COLOR>> ;
using CoordinateType = std::pair<int ,int>;

#endif //OTHELLO_TORCH_SETTINGS_H
