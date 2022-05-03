////////////////////////////////////////////////////////////
// Project SimpleGame
// Copyright (c) 2022 sk-landry
////////////////////////////////////////////////////////////
#ifndef CONSTANTPOOL_H
#define CONSTANTPOOL_H

namespace ng
{
	struct _ObjectPool
	{
		//Player
	    const std::string player			    = "player";
	    const std::string key			        = "door_key";
	    const std::string door			        = "treasure_door";
	    const std::string treasure			    = "treasure";
	};

	struct _CategoryPool
	{
	    const std::string player                = "player";
	    const std::string ground                = "ground";
	    const std::string wall                  = "wall";
	    const std::string power                 = "power";
	    const std::string platform              = "platform";
	    const std::string door                  = "door";
	    const std::string collectible           = "collectible";
	};

	struct _SoundPool
	{
	    const std::string sound01			= "sound01";
	};

	struct _MusicPool
	{
	    const std::string music01			= "music01";
	};

	struct _ScreenPool
	{
	    const std::string startScreen      	= "Start Screen";
	};

	struct _PlayerActionPool
	{
	    const std::string move_left          = "move_left";
	    const std::string move_right         = "move_right";
	    const std::string move_none          = "move_none";
	    const std::string jump               = "jump";
	};


	const _ObjectPool           ObjectPool;
	const _CategoryPool         CategoryPool;
	const _SoundPool     		SoundPool;
	const _MusicPool   			MusicPool;
	const _ScreenPool           ScreenPool;
	const _PlayerActionPool		PlayerActionPool;
}

#endif // CONSTANTPOOL_H
