#include "gtest/gtest.h"
#include "md5_plugin/md5.h"

TEST(TestMd5Case, GetResult) {
    Md5Plugin md5_plugin; 
    EXPECT_EQ("c3fcd3d76192e4007dfb496cca67e13b", md5_plugin.getResult("abcdefghijklmnopqrstuvwxyz"));
}
