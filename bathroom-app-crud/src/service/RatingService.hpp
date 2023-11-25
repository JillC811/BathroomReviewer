#ifndef RATINGSERVICE_HPP
#define RATINGSERVICE_HPP

#include "db/AppDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class RatingService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<AppDb>, m_database); // Inject database component
public:

  oatpp::Object<RatingDto> createRating(const oatpp::Object<RatingDto>& dto);
  oatpp::Object<PageDto<oatpp::Object<RatingDto>>> getAllRatings(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<RatingDto> getRatingById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection = nullptr);
  oatpp::Object<PageDto<oatpp::Object<RatingDto>>> getRatingByBathroom(const int bathroomId);
  oatpp::Object<RatingDto> updateRating(const oatpp::Object<RatingDto>& dto);
  oatpp::Object<StatusDto> deleteRating(const oatpp::Int32& id);

};

#endif