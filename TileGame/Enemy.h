//
//  Enemy.h
//  TileGame
//
//  Created by athenaeum on 2014/11/18.
//
//

#ifndef __TileGame__Enemy__
#define __TileGame__Enemy__

#include <iostream>
#include "GameObject.h"

class Enemy : public GameObject
{
public:
        virtual void stateUpdate();
    
};


#endif /* defined(__TileGame__Enemy__) */
