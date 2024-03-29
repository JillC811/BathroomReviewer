/**
 * @brief runs each of the tests defined
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
 * 
*/

#include "oatpp-test/UnitTest.hpp"
#include "oatpp/core/base/Environment.hpp"
#include "UserControllerTest.hpp"
#include "BathroomControllerTest.hpp"
#include "BuildingControllerTest.hpp"

#include <iostream>

namespace {

void runTests() {

  OATPP_RUN_TEST(UserControllerTest);
  OATPP_RUN_TEST(BathroomControllerTest);
  OATPP_RUN_TEST(BuildingControllerTest);
}

}

int main() {

  oatpp::base::Environment::init();

  runTests();

  /* Print how much objects were created during app running, and what have left-probably leaked */
  /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";

  OATPP_ASSERT(oatpp::base::Environment::getObjectsCount() == 0);

  oatpp::base::Environment::destroy();

  return 0;
}
