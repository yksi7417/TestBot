#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "log_detector/log_detector.h"

class MockContext : public IContext<std::string, std::string> {
public:
    MOCK_METHOD(std::string, get, (std::string arg), (override));
};


TEST(TestLogDetectorCase, CannotDetectAnythingWithEmptyContext) {
    LogDetector log_detector; 
    MockContext context; 
    EXPECT_EQ(0, log_detector.detect(context).getEventId());
}

TEST(TestLogDetectorCase, SizeOfLogEventIs24Bytes) {
    LogDetector log_detector; 
    MockContext context; 
    EXPECT_EQ(24, sizeof(log_detector.detect(context)));
}

