#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "log_detector/log_detector.h"

class LogContext::Impl{};
class LogDetector::Impl{};

class MockContext : public LogContext {
public:
    MockContext() : LogContext("somefilename.txt") {}
    // MOCK_METHOD(std::string, get, (std::string arg), (override));
};

class TestFixture : public ::testing::Test {
protected:
  LogDetector log_detector = LogDetector("build/bin/log_pattern_config.csv");

};

TEST_F(TestFixture, CannotDetectAnythingWithEmptyContext) {
    MockContext context; 
    EXPECT_EQ(0, log_detector.detect(context).getEventId());
}

TEST_F(TestFixture, SizeOfLogEventIs24Bytes) {
    MockContext context; 
    EXPECT_EQ(24, sizeof(log_detector.detect(context)));
    LogEvent logEvent; 
    EXPECT_EQ(24, sizeof(LogEvent));
    EXPECT_EQ(0, logEvent.getEventId());
    EXPECT_EQ(0, logEvent.getLineNumber());
    EXPECT_EQ(0, logEvent.getTimestamp_HHMMSSsss_utc());
}

TEST_F(TestFixture, GivenOneLineThatMatchesAPattern) {
    MockContext context; 
    EXPECT_EQ(1, log_detector.detect(context).getEventId());
    EXPECT_EQ(3, log_detector.detect(context).getLineNumber());
}
