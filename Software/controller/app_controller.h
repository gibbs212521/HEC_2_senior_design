#ifndef __APP_CONTROLLER_H__
#define __APP_CONTROLLER_H__

#include "..\model\base_model.h"
#include "..\ui\Windows\base_window.h"

class AppController{
    int test_var;

    public:
        void getSettings();
        void setFileDir(char * file_directory_name);
        void setFile(char * file_name);
        void setUI();
        void setModel();
        void setChildrenControllers();
        void runApp(){
            initModel()
            initUI()
            initChildrenControllers()
        }

    protected:
        int size;
        int compression_ratio;
        void initModel();
        void initUI();
        void initChildrenControllers();
    //    int shape[2] = [&length, &width];

    private:
        char * file_name;
        char * file_directory_name;
};

#endif
