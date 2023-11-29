
#include "RatingService.hpp"

/**
 * Rating Service
 * 
 * Contains rating CRUD logic.
*/


/**
 * createRating method
 * 
 * Runs SQLite query to create rating in database
 * 
 * @param dto: Rating DTO to be added to database
 * 
 * @return rating added to db
*/
oatpp::Object<RatingDto> RatingService::createRating(const oatpp::Object<RatingDto>& dto) {

  auto dbResult = m_database->createRating(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto ratingId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  return getRatingById((v_int32) ratingId);

}

/**
 * getAllRatings method
 * 
 * Runs SQLite query to fetch all ratings logged in app
 * 
 * @offset: query offset
 * @limit: results limit
 * 
 * @return page dto of ratings
*/
oatpp::Object<PageDto<oatpp::Object<RatingDto>>> RatingService::getAllRatings(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

  oatpp::UInt32 countToFetch = limit;

  auto dbResult = m_database->getAllRatings(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<RatingDto>>>();

  auto page = PageDto<oatpp::Object<RatingDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;

  return page;

}

/**
 * getRatingById method
 * 
 * Runs SQLite query to fetch a specific rating by id.
 * 
 * @param id: ID of requested rating
 * 
 * @return rating dto
*/
oatpp::Object<RatingDto> RatingService::getRatingById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {

  auto dbResult = m_database->getRatingById(id, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Rating not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<RatingDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];

}

/**
 * getRatingByBathroom method
 * 
 * Runs SQLite query to fetch all ratings in a given building
 * 
 * @param bathroomId: id of bathroom to be searched
 * 
 * @return page dto containing rating dtos
*/
oatpp::Object<PageDto<oatpp::Object<RatingDto>>> RatingService::getRatingByBathroom(const int bathroomId) {


  auto dbResult = m_database->getRatingByBathroom(bathroomId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<RatingDto>>>();

  auto page = PageDto<oatpp::Object<RatingDto>>::createShared();
  page->offset = 1;
  page->limit = 20;
  page->count = items->size();
  page->items = items;

  return page;

}

/**
 * updateRating method
 * 
 * Runs SQLite query to update a given rating
 * 
 * @param dto: rating DTO to be updated in database
 * 
 * @return rating dto 
*/
oatpp::Object<RatingDto> RatingService::updateRating(const oatpp::Object<RatingDto>& dto) {

  auto dbResult = m_database->updateRating(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getRatingById(dto->id);

}

/**
 * deleteRating method
 * 
 * Runs SQLite query to delete a given bathroom
 * 
 * @param ratingId: ID of rating to be deleted from database
 * 
 * @return status dto, whether operation owas successful
*/
oatpp::Object<StatusDto> RatingService::deleteRating(const oatpp::Int32& ratingId) {
  auto dbResult = m_database->deleteRating(ratingId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Rating was successfully deleted";
  return status;
}
