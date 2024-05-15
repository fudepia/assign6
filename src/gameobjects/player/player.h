#ifndef PLAYER_H
#define PLAYER_H

#include "../../gamecore/gamestate.h"
#include "../gameobject.h"
#include "playerstate.h"

using namespace PlayerState;

class Player:public GameObject {
    int healPower = 8;
public:
    Player(Position initialPosition);
    ~Player();

    //orig
    //MoveState move();
    MoveState move(GameState::InputState s);
    MoveState moveRel(Position ds);
    
    void render();
};

#endif
