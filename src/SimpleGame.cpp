////////////////////////////////////////////////////////////
// Project SimpleGame
// Copyright (c) 2022 sk-landry
////////////////////////////////////////////////////////////
#include "SimpleGame.h"
#include "ConstantPool.h"
#include <Nero/scene/CollisionRule.h>

namespace ng
{
	SimpleGame::SimpleGame(nero::Scene::Context context): nero::Scene(context)
		,mPlayer()
	{
		//ctr
	}

	SimpleGame::~SimpleGame()
	{
	    //dtr
	}

	void SimpleGame::checkSceneObject()
    {
    	log("checking Scene Objects ...");

    	log("checking World Objects ...");
	    getObjectManager()->checkWorldObject(
	    {
            //list of objects here
	    });

	    log("checking Screen Objects ...");
	    getObjectManager()->checkScreenObject(
	    
	       ScreenPool.startScreen,

	       {
                //list of objects here
	       }
	    );
    }

	sf::Vector2f SimpleGame::getSceneResolution()
	{
        log("Setting up Resolution ...");

	    return sf::Vector2f(800.f, 600.f);
	}

	void SimpleGame::init()
	{
	    log("SimpleGame Scene v0.1");

	    log("Setting up Collision rules ...");
	    nero::CollisionRule collisionRule;
	    collisionRule.canCollide(CategoryPool.player, CategoryPool.ground);
	    collisionRule.apply(getWorld());

	    log("Setting up the player ...");
    	mPlayer.setObject(getObjectManager()->findObject(ObjectPool.player));
	}
}
