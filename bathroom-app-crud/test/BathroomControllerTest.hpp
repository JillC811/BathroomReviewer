#ifndef BathroomControllerTest_hpp
#define BathroomControllerTest_hpp

#include "oatpp-test/UnitTest.hpp"

class BathroomControllerTest : public oatpp::test::UnitTest {
public:
    BathroomControllerTest() : oatpp::test::UnitTest("TEST[BathroomControllerTest]")
    {}

    void onRun() override;
};

#endif // BathroomControllerTest_hpp