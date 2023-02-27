#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "log_detector/log_detector.h"

class MockContext : public IContext<std::string, std::string> {
public:
    MOCK_METHOD(std::string, get, (std::string arg), (override));
};

class TestFixture : public ::testing::Test {
protected:
  LogDetector log_detector;

};

TEST_F(TestFixture, CannotDetectAnythingWithEmptyContext) {
    MockContext context; 
    EXPECT_EQ(0, log_detector.detect(context).getEventId());
}

TEST_F(TestFixture, SizeOfLogEventIs24Bytes) {
    MockContext context; 
    EXPECT_EQ(24, sizeof(log_detector.detect(context)));
}

TEST_F(TestFixture, GivenOneLineThatMatchesAPattern) {
    MockContext context; 
    EXPECT_EQ(1, log_detector.detect(context).getEventId());
    EXPECT_EQ(12, log_detector.detect(context).getLineNumber());
}
