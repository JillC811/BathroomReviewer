#ifndef TestBuildingClient_hpp
#define TestBuildingClient_hpp

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "dto/BuildingDto.hpp"

/* Begin Api Client code generation */
#include OATPP_CODEGEN_BEGIN(ApiClient)

/**
 * Test API client.
 * Use this client to call application APIs.
 */
class TestBuildingClient : public oatpp::web::client::ApiClient {

  API_CLIENT_INIT(TestBuildingClient)

  /*****************************************************************
   * BuildingController
   *****************************************************************/

  API_CALL("POST", "/buildings", createBuilding, BODY_DTO(Object<BuildingDto>, buildingDto))

  API_CALL("GET", "/buildings/offset/{offset}/limit/{limit}", getAllBuildings, PATH(UInt32, offset), PATH(UInt32, limit))
  API_CALL("GET", "/buildings/{buildingName}", getBuildingByName, PATH(String, buildingName))

  API_CALL("PUT", "/buildings/{buildingName}", updateBuilding, PATH(String, buildingName), BODY_DTO(Object<BuildingDto>, buildingDto))

  API_CALL("DELETE", "/buildings/{buildingName}", deleteBuilding, PATH(String, buildingName))

  /*****************************************************************/

  // TODO - add more client API calls here

};

/* End Api Client code generation */
#include OATPP_CODEGEN_END(ApiClient)

#endif //TestBuildingClient_hpp