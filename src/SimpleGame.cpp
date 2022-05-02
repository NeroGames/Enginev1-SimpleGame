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

	    //Init gamepad
	    //setup game controller
        mGamepadOne.setId(ng::Gamepad::ONE);
        mGamepadOne.setButtonMapping(ng::JSPs4ButtonMapping);
        mGamepadOne.setAxisMapping(ng::JSPs4AxisMapping);

	    log("Setting up Collision rules ...");
	    nero::CollisionRule collisionRule;
	    collisionRule.canCollide(CategoryPool.player, CategoryPool.ground);
	    collisionRule.apply(getWorld());

	    log("Setting up the player ...");
    	mPlayer.setObject(getObjectManager()->findObject(ObjectPool.player));
    	mPlayer.setLog(getLog());
    	setCameraTarget(getObjectManager()->findObject(ObjectPool.player));
	}

	void SimpleGame::handleEvent(const sf::Event& event)
    {
        Scene::handleEvent(event);

        switch(event.type)
        {
            //Joystick
            case sf::Event::JoystickConnected:
                onJoystickConnection(event.joystickConnect.joystickId, true); break;
            case sf::Event::JoystickDisconnected:
                onJoystickConnection(event.joystickConnect.joystickId, false); break;
            case sf::Event::JoystickButtonPressed:
                onJoystickButton(event.joystickButton.joystickId, event.joystickButton.button, true); break;
            case sf::Event::JoystickButtonReleased:
                onJoystickButton(event.joystickButton.joystickId, event.joystickButton.button, false); break;
            case sf::Event::JoystickMoved:
                onJoystickAxis(event.joystickMove.joystickId, event.joystickMove.axis, event.joystickMove.position); break;
        }
    }

    void SimpleGame::onJoystickConnection(const unsigned int& joystickId, const bool& connected)
    {
        if(mGamepadOne.getId() == joystickId)
        {
            //
        }
    }

    void SimpleGame::onJoystickButton(const unsigned int& joystickId, const unsigned int& button, const bool& isPressed)
    {
        if(mGamepadOne.getId() == joystickId)
        {
            ng::JSButton jsButton = mGamepadOne.getButton(button);
            mPlayer.onJoystickButton(jsButton, isPressed);
        }
    }

    void SimpleGame::onJoystickAxis(const unsigned int& joystickId, const sf::Joystick::Axis& axis, const float& position)
    {
        if(mGamepadOne.getId() == joystickId)
        {
            ng::JSAxis jsAxis = mGamepadOne.getAxis(axis);
            mPlayer.onJoystickAxis(jsAxis, position);
        }
    }

    void SimpleGame::handleKeyboardInput(const sf::Keyboard::Key& key, const bool& isPressed)
    {
        mPlayer.handleKeyboardInput(key, isPressed);
    }

    void SimpleGame::update(const sf::Time& timeStep)
    {
        nero::Scene::update(timeStep);

        mPlayer.update(timeStep);
    }
}
