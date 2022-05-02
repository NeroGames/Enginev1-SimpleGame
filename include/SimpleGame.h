////////////////////////////////////////////////////////////
// Project SimpleGame
// Copyright (c) 2022 sk-landry
////////////////////////////////////////////////////////////
#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include <Nero/scene/Scene.h>
#include "Player.h"
#include "Gamepad.h"

namespace ng
{
	class SimpleGame : public nero::Scene
	{
	    public:
                                        SimpleGame(nero::Scene::Context context);
	        virtual                    ~SimpleGame();
	        virtual void                handleEvent(const sf::Event& event);


        private:
                //joystick
            virtual void                onJoystickConnection(const unsigned int& joystickId, const bool& connected);
            virtual void                onJoystickButton(const unsigned int& joystickId, const unsigned int& button, const bool& isPressed);
            virtual void                onJoystickAxis(const unsigned int& joystickId, const sf::Joystick::Axis& axis, const float& position);

	    protected:
	        void                        init();
			void                        checkSceneObject();
			sf::Vector2f		        getSceneResolution();

	    private:
        	Player		                mPlayer;
        	Gamepad                     mGamepadOne;
	};
}


#endif // SIMPLEGAME_H
