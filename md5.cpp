#include <Poco/MD5Engine.h>
#include <Poco/DigestStream.h>
#include <Poco/Util/Application.h>
#include <Poco/Logger.h>
#include <iostream>

class MyApplication : public Poco::Util::Application
{
public:
    int main(const std::vector<std::string>& args)
    {
        Poco::MD5Engine md5;
        Poco::DigestOutputStream ds(md5);
        ds << "abcdefghijklmnopqrstuvwxyz";
        ds.close();

        poco_information(logger(), Poco::DigestEngine::digestToHex(md5.digest()) );
        poco_information(logger(), "hello simplier !" );

        return Application::EXIT_OK;
    }
};

int main(int argc, char** argv)
{
    MyApplication app;
    return app.run();
}
