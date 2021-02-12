#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__
#include "..\..\..\controller\app_controller.h"

class MainWindow{
    public:
        void setOwner(AppController * window_owner);
        int width;

    protected:
        int length;
        int width;
    //    int shape[2] = [&length, &width];

    private:
        AppController * owner;
};

#endif
