//
// Created by andre on 07.09.2024.
//
#include "library.h"
#include "gtest/gtest.h"
class FooTest : public ::testing::Test {
protected:
    FooTest() {
        // You can do set-up work for each test here.
    }
    void SetUp() override {
        // code here will execute just before the test ensues
    }

    void TearDown() override {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

};
TEST_F(FooTest, PointGetterSetterTest)
{
    EXPECT_TRUE(hello());
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}