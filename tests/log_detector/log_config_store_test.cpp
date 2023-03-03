#include <string>
#include "gtest/gtest.h"
#include "log_detector/log_config_store.h"

class LogConfigStoreTestFixture : public ::testing::Test {
protected:
  LogConfigStore logConfigStore = LogConfigStore("build/bin/log_pattern_config.csv");

};

TEST_F(LogConfigStoreTestFixture, Detected3ItemsInTestConfigFile) {
    EXPECT_EQ(3, logConfigStore.getConfig()->size());
};

