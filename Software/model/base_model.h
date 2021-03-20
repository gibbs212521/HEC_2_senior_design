#ifndef __APP_MODEL_H__
#define __APP_MODEL_H__
#include "..\..\..\controller\app_controller.h"

class AppModel{

    

    public:
        void setOwner(AppController * window_owner);
        void setFileDir(char * file_directory_name);
        void setFile(char * file_name);

    protected:
        int size;
        int compression_ratio;
    //    int shape[2] = [&length, &width];

    private:
        AppController * owner;
        char * file_name;
        char * file_directory_name;
};

#endif
