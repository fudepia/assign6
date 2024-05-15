#include <iostream>

#include "controller.h"
#include "../gameobjects/room/roomdata.h"
#include "../functions/position/position.h"
#include "../functions/AnsiPrint/AnsiPrint.h"

Controller::Controller() {
    const int defaultRoomIndex = 0;
    RoomData roomData = ROOM_DATA[defaultRoomIndex];

    // initialize class
    auto rPtr = new Room(roomData);
    rooms.insert({defaultRoomIndex, rPtr});
    currentRoomIndex=defaultRoomIndex;

    state=PROCESS_MOVEMENT; //?
    player=new Player(Position{16,10});

    
}

RunningState Controller::run(InputState action) {

    switch (state) {
    case PROCESS_MOVEMENT: {
        
        // add your code to implement the enemy movement

        break;
    }

    default:
        break;
    }

    this->render();

    return PLAY;
}

// Add your code to implement the Controller class here.




Controller::~Controller() {
	free(player);
	for(const auto&[i,p]:rooms) free(p);
}

// Add your code to implement the Controller class here.



RunningState Controller::run(InputState s) {
    switch(s) {
	case ACTION_NONE: {}break;
	case ACTION_UP:
	case ACTION_DOWN:
	case ACTION_LEFT:
	case ACTION_RIGHT: {
			       auto orig=player->getPosition();
			       player->move(s);
			       auto newPosi=player->getPosition();
			       if(!rooms[currentRoomIndex]->walkable(newPosi))
				   player->setPosition(Position(orig));
			   }break;
	case ACTION_CONFIRN: {
			     }break;
	case ACTION_PAUSE: {
			   }break;
	case ACTION_EXIT: { return EXIT;
			  }break;
	case ACTION_INIT: {
			  }break;
    }
    render();
    return PLAY;
}







// render
void Controller::render() {
    switch (state) {
    case PROCESS_MOVEMENT:{
        for (int y = 0; y < GAME_WINDOW_SIZE_Y; y++) {
            for (int x = 0; x < GAME_WINDOW_SIZE_X; x++) {
                if(player->getPosition() == Position(x, y)) {
                    player->render();
                    continue;
                }
                bool flag = false;
                for(auto enemy : rooms[currentRoomIndex]->getEnemies()) {
                    if(enemy->getPosition() == Position(x, y)) {
                        enemy->render();
                        flag = true;
                        continue;
                    }
                }
                if(flag) continue;
                rooms[currentRoomIndex]->render(Position(x, y));
            }
            AnsiPrint("\n", nochange, nochange);
        }
        break;
    }
    
    default:
        break;
    }
    output();
}
