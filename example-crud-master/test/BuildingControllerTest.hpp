#ifndef BuildingControllerTest_hpp
#define BuildingControllerTest_hpp

#include "oatpp-test/UnitTest.hpp"

class BuildingControllerTest : public oatpp::test::UnitTest {
public:
    BuildingControllerTest() : oatpp::test::UnitTest("TEST[BuildingControllerTest]")
    {}

    void onRun() override;
};

#endif // BuildingControllerTest_hpp