#include <Poco/Util/Application.h>
#include <Poco/Logger.h>
#include <iostream>
#include "md5_plugin/md5.h"

class MyApplication : public Poco::Util::Application
{
public:
    int main(const std::vector<std::string>& args)
    {
        Md5Plugin md5_plugin; 
        poco_information(logger(), md5_plugin.getResult("abcdefghijklmnopqrstuvwxyz") );
        poco_information(logger(), "hello simplier !" );

        return Application::EXIT_OK;
    }
};

int main(int argc, char** argv)
{
    MyApplication app;
    return app.run();
}
