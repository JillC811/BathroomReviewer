
#ifndef BathroomController_hpp
#define BathroomController_hpp

#include "service/BathroomService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * User REST controller.
 */
class BathroomController : public oatpp::web::server::api::ApiController {
public:
  BathroomController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  BathroomService m_bathroomService; // Create user service.
public:

  static std::shared_ptr<BathroomController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<BathroomController>(objectMapper);
  }
  
  
  
  ENDPOINT_INFO(getBathroomById) {
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
  

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* UserController_hpp */
