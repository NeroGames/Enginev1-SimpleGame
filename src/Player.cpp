////////////////////////////////////////////////////////////
// Project SimpleGame
// Copyright (c) 2022 sk-landry
////////////////////////////////////////////////////////////
#include "Player.h"
#include "ConstantPool.h"
#include <Nero/utility/Utility.h>

namespace ng
{
	Player::Player(): PhysicActionObject()
	{
	    registerAction<nero::MoveAction>(PlayerActionPool.move_left, nero::getMoveLeftAction(100.f));
	    registerAction<nero::MoveAction>(PlayerActionPool.move_right, nero::getMoveRightAction(100.f));
	    registerAction<nero::MoveAction>(PlayerActionPool.move_none, nero::getMoveNoneXAction());
	}

	Player::~Player()
	{
	    //dtor
	}

	void Player::setObject(Object::Ptr object)
	{
	    nero::PhysicActionObject::setObject(object);

	    mPhysic     = nero::PhysicObject::Cast(getObject());
	}


	void Player::update(const sf::Time& timeStep)
	{
	    //update parent
	    nero::PhysicActionObject::update(timeStep);
	}

	void Player::onJoystickButton(const ng::JSButton& jsButton, const bool& isPressed)
	{
        log(ng::JString(jsButton) + " " + _se(isPressed));
	}

    void Player::onJoystickAxis(const ng::JSAxis& jsAxis , const float& position)
    {
        if(abs(position) > 10.f)
            log(ng::JString(jsAxis) + " " + _se(position));
    }

    void Player::setLog(std::function< void(const std::string &, int)> log)
    {
        mLog = log;
    }

    void Player::log(const std::string& message)
    {
        mLog(message, nero::Log::Info);
    }

    void Player::handleKeyboardInput(const sf::Keyboard::Key& key, const bool& isPressed)
    {

    }
}



