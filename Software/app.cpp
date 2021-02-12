#include "Core\app_init.h"

int main(){
    AppController MotherController;
    MainWindow MainWin;
    MainWin.owner = &MotherController;

    return 0;
}
