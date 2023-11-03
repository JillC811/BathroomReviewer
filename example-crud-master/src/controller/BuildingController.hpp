
#ifndef BuildingController_hpp
#define BuildingController_hpp

#include "service/BuildingService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * User REST controller.
 */
class BuildingController : public oatpp::web::server::api::ApiController {
public:
  BuildingController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  BuildingService m_buildingService; // Create user service.
public:

  static std::shared_ptr<BuildingController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<BuildingController>(objectMapper);
  }
  
  
  
  ENDPOINT_INFO(getBuilding) {
    info->summary = "Get a building by name";

    info->addResponse<Object<BuildingDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["buildingName"].description = "Building Identifier";
  }
  ENDPOINT("GET", "buildings/{name}", getBuilding,
           PATH(String, name))
  {
    return createDtoResponse(Status::CODE_200, m_buildingService.getBuilding(name));
  }
  

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* UserController_hpp */
