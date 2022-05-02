////////////////////////////////////////////////////////////
// Project SimpleGame
// Copyright (c) 2022 sk-landry
////////////////////////////////////////////////////////////
#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include <Nero/scene/Scene.h>
#include "Player.h"

namespace ng
{
	class SimpleGame : public nero::Scene
	{
	    public:
	                            SimpleGame(nero::Scene::Context context);
	        virtual            ~SimpleGame();

	    protected:
	        void                init();
			void                checkSceneObject();
			sf::Vector2f		getSceneResolution();

	    private:
        	Player		mPlayer;
	};
}


#endif // SIMPLEGAME_H
