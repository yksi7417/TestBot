#include <Poco/MD5Engine.h>
#include <Poco/DigestStream.h>
#include <Poco/Logger.h>

#include <Poco/AutoPtr.h>
#include <Poco/Util/IniFileConfiguration.h>
#include <Poco/Util/LoggingConfigurator.h>

#include <iostream>

int configureLogger() {
    try {
        Poco::AutoPtr<Poco::Util::IniFileConfiguration> pConfig = new Poco::Util::IniFileConfiguration("logging.ini");
        Poco::Util::LoggingConfigurator configurator;
        configurator.configure(pConfig);
    }
    catch (std::exception& ex) {
        // handle specific exceptions
        std::cerr << __FILE__ << ":" << __FUNCTION__  << " Exception caught: " << ex.what() << std::endl;
        return -1; 
    }
    catch (...) {
        // catch all other exceptions
        std::cerr << __FILE__ << ":" << __FUNCTION__  << " Unknown exception caught" << std::endl;
        return -1; 
    }

    std::cout << __FILE__ << ":" << __FUNCTION__ << " Successful!!" << std::endl;
    return 0; 
}

int main(int argc, char** argv){
    Poco::Logger& logger = Poco::Logger::get("MyLogger");
    Poco::AutoPtr<Poco::Util::IniFileConfiguration> pConfig = new Poco::Util::IniFileConfiguration("logging.ini");
    Poco::Util::LoggingConfigurator configurator;
    configurator.configure(pConfig);
    logger.setLevel("information");
    logger.error("Hello, POCO!");

    configureLogger();

    Poco::MD5Engine md5;
    Poco::DigestOutputStream ds(md5);
    ds << "abcdefghijklmnopqrstuvwxyz";
    ds.close();
    std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;

    logger.warning("Hello, POCO!");
    return 0;
}
