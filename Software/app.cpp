#include "Core\app_init.h"

int main(){
    AppController MotherController;
    MainWindow MainWin;
    AppModel PrimaryModel;
    MainWin.owner = &MotherController; // use only for signaling
    PrimaryModel.owner = &MotherController; // use only for signaling

    AppController.getSettings();    // collect stable memory in .settings file
    AppController.setModel(&PrimaryModel);  // giving control over model
    AppController.setUI(&MainWin);  // giving control over window ui
    // AppController.setChildrenControllers()  // Currently only one page
    AppController.runApp();
    return 0;   // emits 0 on successful closure of application
}
