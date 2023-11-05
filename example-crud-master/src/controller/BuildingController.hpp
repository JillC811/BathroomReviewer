
#ifndef BuildingController_hpp
#define BuildingController_hpp

#include "service/BuildingService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Building REST controller.
 */
class BuildingController : public oatpp::web::server::api::ApiController
{
public:
  BuildingController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
      : oatpp::web::server::api::ApiController(objectMapper)
  {
  }

private:
  BuildingService m_buildingService; // Create user service.
public:
  static std::shared_ptr<BuildingController> createShared(
      OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  )
  {
    return std::make_shared<BuildingController>(objectMapper);
  }

  ////////////////////////////
  ///// Create
  /////////////////

  ENDPOINT_INFO(createBuilding)
  {
    info->summary = "Create a new building";

    info->addConsumes<Object<BuildingDto>>("application/json");

    info->addResponse<Object<BuildingDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<BuildingDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<BuildingDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "buildings", createBuilding,
           BODY_DTO(Object<BuildingDto>, buildingDto))
  {
    return createDtoResponse(Status::CODE_200, m_buildingService.createBuilding(buildingDto));
  }

  ////////////////////////////
  ///// Read
  /////////////////

  ENDPOINT_INFO(getAllBuildings)
  {
    info->summary = "Get all buildings";

    info->addResponse<oatpp::Object<BuildingsPageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "buildings/offset/{offset}/limit/{limit}", getAllBuildings,
            PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_buildingService.getAllBuildings(offset, limit));
  }

  ENDPOINT_INFO(getBuildingByName)
  {
    info->summary = "Get a building by name";

    info->addResponse<Object<BuildingDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["buildingName"].description = "Building Identifier";
  }
  ENDPOINT("GET", "buildings/{buildingName}", getBuildingByName,
           PATH(String, buildingName))
  {
    return createDtoResponse(Status::CODE_200, m_buildingService.getBuildingByName(buildingName));
  }

  ////////////////////////////
  ///// Update
  /////////////////

  ENDPOINT_INFO(updateBuilding)
  {
    info->summary = "Update Building by name";

    info->addConsumes<Object<BuildingDto>>("application/json");

    info->addResponse<Object<BuildingDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["buildingName"].description = "Building Name";
  }
  ENDPOINT("PUT", "buildings/{buildingName}", updateBuilding,
           PATH(String, buildingName),
           BODY_DTO(Object<BuildingDto>, buildingDto))
  {
    buildingDto->name = buildingName;
    return createDtoResponse(Status::CODE_200, m_buildingService.updateBuilding(buildingDto));
  }

  ////////////////////////////
  ///// Delete
  /////////////////

  ENDPOINT_INFO(deleteBuilding)
  {
    info->summary = "Delete building by name";

    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["buildingName"].description = "Building Name";
  }
  ENDPOINT("DELETE", "buildings/{buildingName}", deleteBuilding,
           PATH(String, buildingName))
  {
    return createDtoResponse(Status::CODE_200, m_buildingService.deleteBuilding(buildingName));
  }
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif
