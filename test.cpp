#include <gtest/gtest.h>
#include "create_json.cpp"
#include <string>

TEST(Firsttest, NoNullValue)
{
    string result = rand_MIL();
    ASSERT_NE(&result, nullptr);
}
TEST(Secondtest, NoNullValue)
{
    int result = DistanceWithMIL();
    ASSERT_NE(&result, nullptr);
}
TEST(Thirdtest, NoNullValue)
{
    string result = IgnitionType();
    ASSERT_NE(&result, nullptr);
}
TEST(Fourthtest, NoNullValue)
{
    string result = FuelStatus();
    ASSERT_NE(&result, nullptr);
}
TEST(Fifthtest, NoNullValue)
{
    int result = EngineLoad();
    ASSERT_NE(&result, nullptr);
}