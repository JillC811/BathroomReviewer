
#include "BathroomService.hpp"

/**
 * Bathroom Service
 * 
 * Contains bathroom CRUD logic.
*/


/**
 * createBathroom method
 * 
 * Runs SQLite query to create bathroom in database
 * 
 * dto: Bathroom DTO to be added to database
*/
oatpp::Object<RatingDto> RatingService::createRating(const oatpp::Object<RatingDto>& dto) {

  auto dbResult = m_database->createRating(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto ratingId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  return getRatingById((v_int32) ratingId);

}

/**
 * getAllBathrooms method
 * 
 * Runs SQLite query to fetch all bathrooms logged in app
 * 
 * offset: query offset
 * limit: results limit
*/
oatpp::Object<PageDto<oatpp::Object<BathroomDto>>> BathroomService::getAllRatings(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

  oatpp::UInt32 countToFetch = limit;

  if(limit > 10) {
    countToFetch = 10;
  }

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
 * getBathroomById method
 * 
 * Runs SQLite query to fetch a specific bathroom by id.
 * 
 * id: ID of requested bathroom
*/
oatpp::Object<BathroomDto> BathroomService::getBathroomById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {

  auto dbResult = m_database->getBathroomById(id, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Bathroom not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BathroomDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];

}

/**
 * getRatingByBathroom method
 * 
 * Runs SQLite query to fetch all bathrooms in a given building
 * 
 * buildingName: name of building to be searched
*/
oatpp::Object<PageDto<oatpp::Object<BathroomDto>>> BathroomService::getRatingByBathroom(const oatpp::String& buildingName) {


  auto dbResult = m_database->getRatingByBathroom(bathroomId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<RatingDto>>>();

  auto page = PageDto<oatpp::Object<BathroomDto>>::createShared();
  page->offset = 1;
  page->limit = 20;
  page->count = items->size();
  page->items = items;

  return page;

}

/**
 * updateBathroom method
 * 
 * Runs SQLite query to update a given bathroom
 * 
 * dto: Bathroom DTO to be updated in database
*/
oatpp::Object<BathroomDto> BathroomService::updateRating(const oatpp::Object<RatingDto>& dto) {

  auto dbResult = m_database->updateRating(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getRatingById(dto->id);

}

/**
 * deleteBathroom method
 * 
 * Runs SQLite query to delete a given bathroom
 * 
 * bathroomId: ID of bathroom to be deleted from database
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
