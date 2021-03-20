#ifndef __APP_CONTROLLER_H__
#define __APP_CONTROLLER_H__

class BaseController{
    int test_var;

    public:
        int setSomething(){
            return 0;
        }

    protected:
        int size;
        int compression_ratio;
    //    int shape[2] = [&length, &width];

    private:
        BaseController * owner;
        char * file_name;
        char * file_directory_name;
};

#endif
