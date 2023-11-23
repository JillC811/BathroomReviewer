#include "BuildingControllerTest.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"

#include "controller/BuildingController.hpp"

#include "app/TestBuildingClient.hpp"
#include "app/TestComponent.hpp"

#include <cstdio>
#include <iostream>



void BuildingControllerTest::onRun() {

  /* Remove test database file before running the test */
  OATPP_LOGI(TAG, "DB-File='%s'", TESTDATABASE_FILE);
  std::remove(TESTDATABASE_FILE);

  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Add UserController endpoints to the router of the test server */
  runner.addController(std::make_shared<BuildingController>());

  /* Run test */
  runner.run([this, &runner] {

    /* Get client connection provider for Api Client */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, clientConnectionProvider);

    /* Get object mapper component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);

    /* Create http request executor for Api Client */
    auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(clientConnectionProvider);

    /* Create Test API client */
    auto client = TestBuildingClient::createShared(requestExecutor, objectMapper);

    auto buildingDto1 = BuildingDto::createShared();
    auto buildingDto2 = BuildingDto::createShared();

    buildingDto1->name = "Test_Building_1";
    // buildingDto1->longitude = "111";
    // buildingDto1->latitude = "222";

    buildingDto2->name ="Test_Building_2";
    // buildingDto2->longitude = "333";
    // buildingDto2->latitude = "444";
   
    /* Call server API */
    auto createdBuildingResponse1 = client->createBuilding(buildingDto1);
    auto createdBuildingResponse2 = client->createBuilding(buildingDto2);


    /* Assert that server responds with 200 */
    OATPP_ASSERT(createdBuildingResponse1->getStatusCode() == 200);
    OATPP_ASSERT(createdBuildingResponse2->getStatusCode() == 200);


    /* Read response body as MessageDto */
    auto createdBuildingDto1 = createdBuildingResponse1->readBodyToDto<oatpp::Object<BuildingDto>>(objectMapper.get());
    auto createdBuildingDto2 = createdBuildingResponse2->readBodyToDto<oatpp::Object<BuildingDto>>(objectMapper.get());

    auto createdBuildingName1 = createdBuildingDto1->name;
    auto createdBuildingName2 = createdBuildingDto2->name;

    /* Assert that building has been added */
    auto newBuildingResponse1 = client->getBuildingByName(createdBuildingName1);
    auto newBuildingResponse2 = client->getBuildingByName(createdBuildingName2);

    auto newBuildingDto1 = newBuildingResponse1->readBodyToDto<oatpp::Object<BuildingDto>>(objectMapper.get());
    auto newBuildingDto2 = newBuildingResponse2->readBodyToDto<oatpp::Object<BuildingDto>>(objectMapper.get());

    /* Assert successful status code and proper building details */
    OATPP_ASSERT(newBuildingResponse1->getStatusCode() == 200);
    OATPP_ASSERT(newBuildingDto1->name == "Test_Building_1");
    // OATPP_ASSERT(newBuildingDto1->longitude == "111");
    // OATPP_ASSERT(newBuildingDto-> latitude == "222");

    OATPP_ASSERT(newBuildingResponse2->getStatusCode() == 200);
    OATPP_ASSERT(newBuildingDto2->name == "Test_Building_2");
    // OATPP_ASSERT(newBuildingDto2->longitude == "333");
    // OATPP_ASSERT(newBuildingDto2->latitude == "444");

    /* Test the getAllBuildings endpoint */
    // auto getAllBuildingsResponse = client->getAllBuildings(0, 99);

    // OATPP_ASSERT(getAllBuildingsResponse->getStatusCode() == 200);

    // auto allBuildingsDto = getAllBuildingsResponse->readBodyToDto<oatpp::Object<PageDto<oatpp::Object<BuildingDto>>>>(objectMapper.get());

    /* This testing code is not yet complete */

    /* Assert that getBathroomsByBuilding endpoint gets both added buildings */

    // OATPP_ASSERT(allBuildingsDto->count == 2);

    // auto extractedBuildingDto1 = allBuildingsDto->items[0];
    // auto extractedBuildingDto2 = allBuildingsDto->items[1];

    // /* Assert the valeus of each of the Bathroom DTOs to make sure the endpoints fetched the right object */
    // OATPP_ASSERT(extractedBuildingDto1->name == "Test_Building_1");
    // OATPP_ASSERT(extractedBuildingDto1->location == "111, 222");

    // OATPP_ASSERT(extractedBuildingDto2->name == "Test_Building_2");
    // OATPP_ASSERT(extractedBuildingDto2->location == "222, 333");

    /* Test the updateBuilding endpoint */
    // buildingDto1->name = "Test_Building_3";
    // auto updateBuildingResponse = client->updateBuilding("Test_Building_1", buildingDto1);

    // OATPP_ASSERT(updateBuildingResponse->getStatusCode() == 200);

    // auto updatedBuildingDto = updateBuildingResponse->readBodyToDto<oatpp::Object<BuildingDto>>(objectMapper.get());

    // /* Assert that the Bathroom DTO reflects new values after being updated */
    // OATPP_ASSERT(updatedBuildingDto->name == "Test_Building_3");
    // OATPP_ASSERT(updatedBuildingDto->location == "111, 222");


  }, std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));

  /* stop db connection pool */
  OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider);
  dbConnectionProvider->stop();

}