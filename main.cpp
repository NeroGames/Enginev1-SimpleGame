////////////////////////////////////////////////////////////
// Project SimpleGame
// Copyright (c) 2022 sk-landry
////////////////////////////////////////////////////////////

// The Macro NERO_RENDER_ENGINE allows you to run the Editor when CodeBlocks is in Debug Mode
// and the Render Engine CodeBlocks is in Release Mode

#ifndef NERO_RENDER_ENGINE

    #include <Nero/engine/Editor.h>
    #include "SimpleGame.h"


    int main()
    {
        nero::Editor editor(1900);
            editor.addScene<ng::SimpleGame>("SimpleGame");
        editor.run();

        return 0;
    }

#else

    #include <Nero/engine/RenderEngine.h>
    #include "SimpleGame.h"
    #include "LoadingScreen.h"

    int main()
    {
        nero::RenderEngine engine;
            engine.setScene<ng::SimpleGame>("SimpleGame");
        engine.run();

        return 0;
    }

#endif // NERO_RENDER_ENGINE

