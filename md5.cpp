#include <Poco/MD5Engine.h>
#include <Poco/DigestStream.h>
#include <Poco/Logger.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>

#include <Poco/AutoPtr.h>
#include <Poco/Util/IniFileConfiguration.h>
#include <Poco/Util/LoggingConfigurator.h>

#include <iostream>

int main(int argc, char** argv){
    Poco::Logger& logger = Poco::Logger::get("Logger");
    Poco::AutoPtr<Poco::ConsoleChannel> pChannel(new Poco::ConsoleChannel);
    Poco::AutoPtr<Poco::PatternFormatter> pPF(new Poco::PatternFormatter);
    pPF->setProperty("pattern", "%Y-%m-%d %H:%M:%S.%i [%s] [%p] %t");
    Poco::AutoPtr<Poco::FormattingChannel> pFC(new Poco::FormattingChannel(pPF, pChannel));
    logger.setChannel(pFC);

    Poco::AutoPtr<Poco::Util::IniFileConfiguration> pConfig = new Poco::Util::IniFileConfiguration("logging.ini");
    Poco::Util::LoggingConfigurator configurator;
    configurator.configure(pConfig);


    Poco::MD5Engine md5;
    Poco::DigestOutputStream ds(md5);
    ds << "abcdefghijklmnopqrstuvwxyz";
    ds.close();
    std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;

    logger.information("Hello, POCO!");
    return 0;
}
