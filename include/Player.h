////////////////////////////////////////////////////////////
// Project SimpleGame
// Copyright (c) 2022 sk-landry
////////////////////////////////////////////////////////////
#ifndef PLAYER_H
#define PLAYER_H

#include <Nero/gamelib.h>
#include <Nero/object/PhysicObject.h>
#include "Gamepad.h"

namespace ng
{
	class Player : public nero::PhysicActionObject
	{
	    public:
	                                	Player();
	        virtual                	   ~Player();

	        void                    	update(const sf::Time& timeStep);
	        void                    	setObject(Object::Ptr object);
	        //log
	        void                        setLog(std::function< void(const std::string &, int)> log);
	        void                        log(const std::string& message);
	        //control
	        void                        onJoystickButton(const ng::JSButton& jsButton, const bool& isPressed);
            void                        onJoystickAxis(const ng::JSAxis& jsAxis , const float& position);
            void                        handleKeyboardInput(const sf::Keyboard::Key& key, const bool& isPressed);
            //action
            void                        moveLeft();
            void                        moveRight();
            void                        moveNone();
            void                        jump();
            void                        resetJump();

	    private:
	        nero::PhysicObject::Ptr		                        mPhysic;
	        std::function< void(const std::string &, int)> 	    mLog;
            float                                               mMoveSpeed;
	        float                                               mJumpForce;
	        bool                                                mIsMovingLeft;
	        bool                                                mIsMovingRight;
	        bool                                                mIsJumping;
	};
}

#endif // PLAYER_H
