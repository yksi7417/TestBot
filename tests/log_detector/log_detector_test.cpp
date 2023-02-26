#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "log_detector/log_detector.h"

class MockContext : public IContext<std::string, std::string> {
public:
    MOCK_METHOD(std::string, get, (std::string arg), (override));
};


TEST(TestMd5Case, CannotDetectAnythingWithEmptyContext) {
    LogDetector log_detector; 
    MockContext context; 
    EXPECT_FALSE(log_detector.detect(context));
}
