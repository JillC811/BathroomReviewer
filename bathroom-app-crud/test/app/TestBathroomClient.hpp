#ifndef TestBathroomClient_hpp
#define TestBathroomClient_hpp

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "dto/BathroomDto.hpp"
#include "dto/RatingDto.hpp"

/* Begin Api Client code generation */
#include OATPP_CODEGEN_BEGIN(ApiClient)

/**
 * Test API client.
 * Use this client to call application APIs.
 */
class TestBathroomClient : public oatpp::web::client::ApiClient {

  API_CLIENT_INIT(TestBathroomClient)

  /*****************************************************************
   * BathroomController
   *****************************************************************/

  API_CALL("POST", "/bathrooms", createBathroom, BODY_DTO(Object<BathroomDto>, BathroomDto))

  API_CALL("GET", "/bathrooms/offset/{offset}/limit/{limit}", getAllBathrooms, PATH(UInt32, offset), PATH(UInt32, limit))
  API_CALL("GET", "/bathrooms/{bathroomId}", getBathroomById, PATH(Int32, bathroomId))
  API_CALL("GET", "/bathrooms/building/{buildingName}", getBathroomsByBuilding, PATH(String, buildingName))

  API_CALL("PUT", "/bathrooms/{bathroomId}", updateBathroom, PATH(Int32, bathroomId), BODY_DTO(Object<BathroomDto>, bathroomDto))

  API_CALL("DELETE", "/bathrooms/{bathroomId}", deleteBathroom, PATH(Int32, bathroomId))

  /*****************************************************************/
};

/* End Api Client code generation */
#include OATPP_CODEGEN_END(ApiClient)

#endif //TestBathroomClient_hpp