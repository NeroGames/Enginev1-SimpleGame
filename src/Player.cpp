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
        ,mMoveSpeed(100.f)
	    ,mJumpForce(700.f)
	    ,mIsMovingLeft(false)
	    ,mIsMovingRight(false)
	    ,mIsJumping(false)
	    ,mPhysic(nullptr)
	{
	    registerAction<nero::MoveAction>(PlayerActionPool.move_left, nero::getMoveLeftAction(mMoveSpeed));
	    registerAction<nero::MoveAction>(PlayerActionPool.move_right, nero::getMoveRightAction(mMoveSpeed));
	    registerAction<nero::MoveAction>(PlayerActionPool.move_none, nero::getMoveNoneXAction());
        registerAction<nero::JumpAction>(PlayerActionPool.jump, nero::getJumpAction(mJumpForce));
	}

	Player::~Player()
	{
	    //dtor
	}

	void Player::setObject(Object::Ptr object)
	{
	    nero::PhysicActionObject::setObject(object);

	    mPhysic = nero::PhysicObject::Cast(getObject());
	}


	void Player::update(const sf::Time& timeStep)
	{
	    //update parent
	    nero::PhysicActionObject::update(timeStep);

	    //log(nero::toString(mPhysic->getLinearVelocity().x));

        //Move Action
	    if(mIsMovingLeft && std::abs(mPhysic->getLinearVelocity().x) < 90.f)
	    {
           //log("moving left");
	       callAction(PlayerActionPool.move_left);
	    }
	    else if(mIsMovingRight && std::abs(mPhysic->getLinearVelocity().x) < 90.f)
	    {
	        //log("moving right");
	        callAction(PlayerActionPool.move_right);
	    }
	}

	void Player::onJoystickButton(const ng::JSButton& jsButton, const bool& isPressed)
	{
        log(ng::JString(jsButton) + " " + _se(isPressed));

        if(isPressed)
        {
            if(jsButton == ng::JSButton::Cross)
            {
                jump();
            }
        }
	}

    void Player::onJoystickAxis(const ng::JSAxis& jsAxis , const float& position)
    {
        /*if(abs(position) > 90.f)
            log(ng::JString(jsAxis) + " " + _se(position));*/

        if(jsAxis == ng::JSAxis::LeftAnalogX)
        {
            if(position < -90.f)
            {
                moveLeft();
            }
            else if (position > 90.f)
            {
                moveRight();
            }
            else
            {
                moveNone();
            }
        }

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
        if(isPressed)
	    {
	        if(key == sf::Keyboard::Left)
	        {
	            moveLeft();
	        }
	        else if(key == sf::Keyboard::Right)
	        {
	            moveRight();
	        }

	        if(key == sf::Keyboard::C)
	        {
	            jump();
	        }

	    }
	    else // not isPressed
	    {
	         if(key == sf::Keyboard::Left || key == sf::Keyboard::Right)
	         {
	             moveNone();
	         }
	    }
    }

    void Player::moveLeft()
	{
	    mIsMovingLeft = true;
	}

	void Player::moveRight()
	{
	    mIsMovingRight = true;
	}

	void Player::moveNone()
	{
	    mIsMovingLeft = false;
	    mIsMovingRight = false;

	    callAction(PlayerActionPool.move_none);
	}

	void Player::jump()
	{
	    if(!mIsJumping)
	    {
	        mPhysic->clearVerticalVelocity();
	        callAction(PlayerActionPool.jump);
	        mIsJumping = false;
	    }
	}

	void Player::resetJump()
	{
	    //The player is falling down
	    if(mPhysic->getLinearVelocity().y > 0.f)
	    {
	        mIsJumping = false;
	        mPhysic->clearVelocity();
	    }
	}
}



