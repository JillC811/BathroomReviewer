#ifndef BathroomController_hpp
#define BathroomController_hpp

#include "service/BathroomService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * @brief Bathroom REST controller 
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
 * 
*/
class BathroomController : public oatpp::web::server::api::ApiController
{
public:
  BathroomController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
      : oatpp::web::server::api::ApiController(objectMapper)
  {
  }

private:
  BathroomService m_bathroomService; // Create user service.
public:
  static std::shared_ptr<BathroomController> createShared(
      OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  )
  {
    return std::make_shared<BathroomController>(objectMapper);
  }

  ////////////////////////////
  ///// Create
  /////////////////

  /**
   * Endpoint information for creating bathroom into database
   * 
   */
  ENDPOINT_INFO(createBathroom)
  {
    info->summary = "Create new bathroom";

    info->addConsumes<Object<BathroomDto>>("application/json");

    info->addResponse<Object<BathroomDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<BathroomDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<BathroomDto>>(Status::CODE_500, "application/json");
  }
  /**
 * Endpoint for creating bathroom into database
 */
  ENDPOINT("POST", "bathrooms", createBathroom,
           BODY_DTO(Object<BathroomDto>, bathroomDto))
  {
    return createDtoResponse(Status::CODE_200, m_bathroomService.createBathroom(bathroomDto));
  }

  ////////////////////////////
  ///// Read
  /////////////////
  
  ENDPOINT_INFO(getAllBathrooms)
  {
    info->summary = "Get all bathrooms";

    info->addResponse<oatpp::Object<BathroomsPageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ADD_CORS(getAllBathrooms);
  ENDPOINT("GET", "bathrooms/offset/{offset}/limit/{limit}", getAllBathrooms,
           PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_bathroomService.getAllBathrooms(offset, limit));
  }

  ENDPOINT_INFO(getBathroomById)
  {
    info->summary = "Get one Bathroom by Id";

    info->addResponse<Object<BathroomDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["bathroomId"].description = "Bathroom Identifier";
  }
  ENDPOINT("GET", "bathrooms/{bathroomId}", getBathroomById,
           PATH(Int32, bathroomId))
  {
    return createDtoResponse(Status::CODE_200, m_bathroomService.getBathroomById(bathroomId));
  }

  ENDPOINT_INFO(getBathroomByBuilding)
  {
    info->summary = "Get all bathrooms by building name";

    info->addResponse<Object<BathroomDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["building"].description = "Building Name Identifier";
  }
  ENDPOINT("GET", "bathrooms/building/{building}", getBathroomByBuilding,
           PATH(String, building))
  {
    return createDtoResponse(Status::CODE_200, m_bathroomService.getBathroomByBuilding(building));
  }

  ////////////////////////////
  ///// Update
  /////////////////

  ENDPOINT_INFO(updateBathroom)
  {
    info->summary = "Update Bathroom by Bathroomid";

    info->addConsumes<Object<UserDto>>("application/json");

    info->addResponse<Object<BathroomDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["bathroomId"].description = "Bathroom Identifier";
  }
  ENDPOINT("PUT", "bathrooms/{bathroomId}", updateBathroom,
           PATH(Int32, bathroomId),
           BODY_DTO(Object<BathroomDto>, bathroomDto))
  {
    bathroomDto->id = bathroomId;
    return createDtoResponse(Status::CODE_200, m_bathroomService.updateBathroom(bathroomDto));
  }

  ////////////////////////////
  ///// Delete
  /////////////////

  ENDPOINT_INFO(deleteBathroom)
  {
    info->summary = "Delete Bathroom by id";

    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["bathroomId"].description = "Bathroom Identifier";
  }
  ENDPOINT("DELETE", "bathrooms/{bathroomId}", deleteBathroom,
           PATH(Int32, bathroomId))
  {
    return createDtoResponse(Status::CODE_200, m_bathroomService.deleteBathroom(bathroomId));
  }
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif
