#include <Poco/MD5Engine.h>
#include <Poco/DigestStream.h>

#include "md5_plugin/md5.h"

std::string Md5Plugin::getResult(const std::string& input) const
{
        Poco::MD5Engine md5;
        Poco::DigestOutputStream ds(md5);
        ds << input.c_str();
        ds.close();
        return Poco::DigestEngine::digestToHex(md5.digest());
}
