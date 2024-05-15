#include "player.h"
#include<cassert>
#include "../../controller/enviroment.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"

using namespace PlayerState;

// Add your code to implement the Player class here.

static constexpr int Preset_maxHealth=10;
static constexpr int Preset_attack=10;
Player::Player(Position iP): GameObject(iP, Preset_maxHealth, Preset_attack, "Player") {}
Player::~Player() = default;

MoveState Player::move(GameState::InputState s) {
	using namespace GameState;
	switch(s) {
		case ACTION_UP: {
					position.decrY();
				}break;
		case ACTION_DOWN: {
					  position.incrY();
				  }break;
		case ACTION_LEFT: {
					  position.decrX();
				  }break;
		case ACTION_RIGHT: {
					   position.incrX();
				   }break;
		default: break;
	}
	return MOVE;
}

// render
void Player::render() {
    AnsiPrint("PL", green, blue);
}

//MoveState Player::moveRel(Position ds) {
//	this->position+=ds;
//}
