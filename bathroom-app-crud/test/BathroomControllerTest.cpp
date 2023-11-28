#include "BathroomControllerTest.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"

#include "controller/BathroomController.hpp"

#include "app/TestBathroomClient.hpp"
#include "app/TestComponent.hpp"

#include <cstdio>
#include <iostream>

void BathroomControllerTest::onRun() {

  /* Remove test database file before running the test */
  OATPP_LOGI(TAG, "DB-File='%s'", TESTDATABASE_FILE);
  std::remove(TESTDATABASE_FILE);

  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Add UserController endpoints to the router of the test server */
  runner.addController(std::make_shared<BathroomController>());

  /* Run test */
  runner.run([this, &runner] {

    /* Get client connection provider for Api Client */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, clientConnectionProvider);

    /* Get object mapper component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);

    /* Create http request executor for Api Client */
    auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(clientConnectionProvider);

    /* Create Test API client */
    auto client = TestBathroomClient::createShared(requestExecutor, objectMapper);

    auto bathroomDto1 = BathroomDto::createShared();
    auto bathroomDto2 = BathroomDto::createShared();

    bathroomDto1->id = 1;
    bathroomDto1->building = "Test_Building";
    bathroomDto1->floor = 1;
    bathroomDto1->location = "99, -99";
    bathroomDto1->gender = "m";
    bathroomDto1->stallCount = 99;
    bathroomDto1->urinalCount = 88;
    bathroomDto1->ratings = "";

    bathroomDto2->id = 2;
    bathroomDto2->building = "Test_Building";
    bathroomDto2->floor = 2;
    bathroomDto2->location = "100, -100";
    bathroomDto2->gender = "f";
    bathroomDto2->stallCount = 999;
    bathroomDto2->urinalCount = 0;
    bathroomDto2->ratings = "";
   

    /* Call server API */
    auto createdBathroomResponse1 = client->createBathroom(bathroomDto1);
    auto createdBathroomResponse2 = client->createBathroom(bathroomDto2);

    /* Assert that server responds with 200 */
    OATPP_ASSERT(createdBathroomResponse1->getStatusCode() == 200);

    /* Read response body as MessageDto */
    auto createdBathroomDto = createdBathroomResponse1->readBodyToDto<oatpp::Object<BathroomDto>>(objectMapper.get());
    
    int createdBathroomId = createdBathroomDto->id;

    /* Assert that user has been added */
    auto newBathroomResponse = client->getBathroomById(createdBathroomId);
    OATPP_ASSERT(newBathroomResponse->getStatusCode() == 200);


    /* Test the getBathroomsByBuilding endpoint */
    auto getBathroomsByBuildingResponse = client->getBathroomsByBuilding("Test_Building");

    OATPP_ASSERT(getBathroomsByBuildingResponse->getStatusCode() == 200);
    auto allBathroomsDto = getBathroomsByBuildingResponse->readBodyToDto<oatpp::Object<PageDto<oatpp::Object<BathroomDto>>>>(objectMapper.get());

    /* Assert that getBathroomsByBuilding endpoint gets both added buildings */
    OATPP_ASSERT(allBathroomsDto->count == 2); 

    auto extractedBathroomDto1 = allBathroomsDto->items[0];
    auto extractedBathroomDto2 = allBathroomsDto->items[1];

    /* Assert the valeus of each of the Bathroom DTOs to make sure the endpoints fetched the right object */

    // std::cout << "Building: " << extractedBathroomDto1->building->c_str() << std::endl;
    // std::cout << "id: " << extractedBathroomDto1->id << std::endl;
    // std::cout << "floor: " << extractedBathroomDto1->floor << std::endl;
    // std::cout << "location: " << extractedBathroomDto1->location->c_str() << std::endl;
    // std::cout << "gender: " << extractedBathroomDto1->gender->c_str() << std::endl;   
    // std::cout << "Stall count: " << extractedBathroomDto1->stallCount << std::endl;
    // std::cout << "Urinal count: " << extractedBathroomDto1->urinalCount << std::endl;
    // std::cout << "ratings: " << extractedBathroomDto1->ratings->c_str() << std::endl;

    OATPP_ASSERT(extractedBathroomDto1->building == "Test_Building");
    OATPP_ASSERT(extractedBathroomDto1->floor == 1);
    OATPP_ASSERT(extractedBathroomDto1->location == "99, -99");
    OATPP_ASSERT(extractedBathroomDto1->gender == "m");
    OATPP_ASSERT(extractedBathroomDto1->stallCount == 99);
    OATPP_ASSERT(extractedBathroomDto1->urinalCount == 88);

    OATPP_ASSERT(extractedBathroomDto2->building == "Test_Building");
    OATPP_ASSERT(extractedBathroomDto2->floor == 2);
    OATPP_ASSERT(extractedBathroomDto2->location == "100, -100");
    OATPP_ASSERT(extractedBathroomDto2->gender == "f");
    OATPP_ASSERT(extractedBathroomDto2->stallCount == 999);
    OATPP_ASSERT(extractedBathroomDto2->urinalCount == 0);


    /* Test the updateBathrooms endpoint */
    //bathroomDto1->gender = "b";
    //auto updateBathroomResponse = client->updateBathroom(1, bathroomDto1);
    
    //OATPP_ASSERT(updateBathroomResponse->getStatusCode() == 200);

    //auto updatedBathroomDto = updateBathroomResponse->readBodyToDto<oatpp::Object<BathroomDto>>(objectMapper.get());

    /* Assert that the Bathroom DTO reflects new values after being updated */
    // OATPP_ASSERT(updatedBathroomDto->building == "Test_Building");
    // OATPP_ASSERT(updatedBathroomDto->id == 1);
    // OATPP_ASSERT(updatedBathroomDto->floor == 1);
    // OATPP_ASSERT(updatedBathroomDto->location == "99, -99");
    // OATPP_ASSERT(updatedBathroomDto->gender == "b");
    // OATPP_ASSERT(updatedBathroomDto->stallCount == 99);
    // OATPP_ASSERT(updatedBathroomDto->urinalCount == 88);
    // OATPP_ASSERT(updatedBathroomDto->ratings == "");

  }, std::chrono::minutes(10) /* test timeout */);

  /* wait all server threads finished */
  std::this_thread::sleep_for(std::chrono::seconds(1));

  /* stop db connection pool */
  OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider);
  dbConnectionProvider->stop();

}