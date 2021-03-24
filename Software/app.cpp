#include "Core\app_init.h"

int main(){
    AppController MotherController;
    MainWindow MainWin;
    AppModel PrimaryModel;
    MainWin.owner = &MotherController; // use only for signaling
    PrimaryModel.owner = &MotherController; // use only for signaling

    MotherController.getSettings();    // collect stable memory in .settings file
    MotherController.setModel(&PrimaryModel);  // giving control over model
    MotherController.setUI(&MainWin);  // giving control over window ui
    // MotherController.setChildrenControllers()  // Currently only one page
    MotherController.runApp();
    return 0;   // emits 0 on successful closure of application
}
