
#ifndef RatingController_hpp
#define RatingController_hpp

#include "service/RatingService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Rating REST controller.
 */
class RatingController : public oatpp::web::server::api::ApiController
{
public:
  RatingController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
      : oatpp::web::server::api::ApiController(objectMapper)
  {
  }

private:
  ratingService m_ratingService; // Create user service.
public:
  static std::shared_ptr<RatingController> createShared(
      OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  )
  {
    return std::make_shared<RatingController>(objectMapper);
  }

  ////////////////////////////
  ///// Create
  /////////////////

  ENDPOINT_INFO(createRating)
  {
    info->summary = "Create a new rating";

    info->addConsumes<Object<RatingDto>>("application/json");

    info->addResponse<Object<RatingDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<RatingDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<RatingDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "ratings", createRating,
           BODY_DTO(Object<RatingDto>, ratingDto))
  {
    return createDtoResponse(Status::CODE_200, m_ratingService.createRating(ratingDto));
  }

  ////////////////////////////
  ///// Read
  /////////////////

  ENDPOINT_INFO(getAllRatings)
  {
    info->summary = "Get all ratings";

    info->addResponse<oatpp::Object<RatingsPageDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "ratings/offset/{offset}/limit/{limit}", getAllRatings,
            PATH(UInt32, offset),
           PATH(UInt32, limit))
  {
    return createDtoResponse(Status::CODE_200, m_ratingService.getAllRatings(offset, limit));
  }

  ENDPOINT_INFO(getRatingById)
  {
    info->summary = "Get a rating by id";

    info->addResponse<Object<RatingDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["ratingId"].description = "Rating Identifier";
  }
  ENDPOINT("GET", "ratings/{ratingId}", getRatingById,
           PATH(Int32, ratingId))
  {
    return createDtoResponse(Status::CODE_200, m_ratingService.getRatingById(ratingId));
  }

    ENDPOINT_INFO(getRatingByBathroom)
  {
    info->summary = "Get all ratings by bathroom id";

    info->addResponse<Object<BathroomDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["Bathroom"].description = "Bathroom Id Identifier";
  }
  ENDPOINT("GET", "rating/bathroom/{bathroomid}", getRatingByBathroom,
           PATH(Int, bathroom))
  {
    return createDtoResponse(Status::CODE_200, m_bathroomService.getBathroomByBuilding(building));
  }

  ////////////////////////////
  ///// Update
  /////////////////

  ENDPOINT_INFO(updateRating)
  {
    info->summary = "Update Rating by id";

    info->addConsumes<Object<RatingDto>>("application/json");

    info->addResponse<Object<RatingDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["ratingid"].description = "Rating id";
  }
  ENDPOINT("PUT", "ratings/{ratingName}", updateRating,
           PATH(Int32, ratingId),
           BODY_DTO(Object<ratingDto>, ratingDto))
  {
    ratingDto->name = ratingId;
    return createDtoResponse(Status::CODE_200, m_ratingService.updateRating(ratingDto));
  }

  ////////////////////////////
  ///// Delete
  /////////////////

  ENDPOINT_INFO(deleteRating)
  {
    info->summary = "Delete rating by id";

    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["ratingId"].description = "Rating id";
  }
  ENDPOINT("DELETE", "ratings/{ratingId}", deleteRating,
           PATH(Int32, ratingId))
  {
    return createDtoResponse(Status::CODE_200, m_ratingService.deleteRating(ratingId));
  }
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif
