#include "app/viewer.h"
#include "app/viewer_window.h"
#include "app/viewer_ui.h"

#include "core/settings.h"

#include <memory>

const size_t WIDTH = 1000;
const size_t HEIGHT = 800;


int main(int argc,char * argv[]) {

    std::unique_ptr<Viewer> app;

    if (argc != 2) {
        app = std::make_unique<Viewer>("basic.vs","basic.fs");
    }
    else {
        app = std::make_unique<Viewer>("basic.vs", argv[2]);
    }



    //Create a window for rendering the app
    ViewerWindow window{ *app,WIDTH,HEIGHT };

    //Init the app with graphics resources
    app->init();

    //Create a ui if you want it, might need access to app state if its a custom ui
    //Ui object by default displays imgui's demo window
    ViewerUi ui{window,*app};


    while (!window.closed()) {


        //Check for any input events
        window.pollEvents();

        //Start new ui frame
        ui.newFrame();

        //Update window
        window.update(*app);

        //Update app state 
        app->update();
        //Render app state
        app->render();

     
        //Update ui state
        ui.update();
        //Render ui state
        ui.render();

        //Swap back-buffer to screen
        window.swapBuffers();
    }

   ui.shutdown();

   return 0;
}

