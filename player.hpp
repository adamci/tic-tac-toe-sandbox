//
//	player.hpp
//
//
#define BOARD_SIZE 9
#include <vector>


#ifndef _PLAYER_H
#define _PLAYER_H



// ======================================== //
//        Player class definition           //
// ======================================== //
class player
{
public:
    bool validMove(int i, std::vector<char> board);
};

#endif