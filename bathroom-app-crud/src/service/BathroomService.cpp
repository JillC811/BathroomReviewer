
#include "BathroomService.hpp"

/**
 * @brief Bathroom Service
 * @author colton
 * 
 * Contains bathroom CRUD logic. functions to interact with and update database
 * @brief Bathroom Service. Contains bathroom CRUD logic.
*/


/**
 * @brief createBathroom method
 * 
 * Runs SQLite query to create bathroom in database
 * 
 * @param dto BathroomDTO to be added to database
 * 
 * @return bathroom inserted into db
*/
oatpp::Object<BathroomDto> BathroomService::createBathroom(const oatpp::Object<BathroomDto>& dto) {

  auto dbResult = m_database->createBathroom(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto bathroomId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  return getBathroomById((v_int32) bathroomId);

}

/**
 * @brief getAllBathrooms method
 * 
 * Runs SQLite query to fetch all bathrooms logged in app
 * 
 * @param offset: Int, query offset
 * @param limit: Int, results limit
 * 
 * @return page dto of bathrooms in building
*/
oatpp::Object<PageDto<oatpp::Object<BathroomDto>>> BathroomService::getAllBathrooms(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

  oatpp::UInt32 countToFetch = limit;


  auto dbResult = m_database->getAllBathrooms(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<BathroomDto>>>();

  auto page = PageDto<oatpp::Object<BathroomDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;

  return page;

}

/**
 * @brief getBathroomById method
 * 
 * Runs SQLite query to fetch a specific bathroom by id.
 * 
 * @param id: Int, ID of requested bathroom
 * 
 * @return bathroomDTO of requested bathroom 
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
 * @brief getBathroomByBuilding method
 * 
 * Runs SQLite query to fetch all bathrooms in a given building
 * 
 * @param buildingName: String,name of building to be searched
*/
oatpp::Object<PageDto<oatpp::Object<BathroomDto>>> BathroomService::getBathroomByBuilding(const oatpp::String& buildingName) {


  auto dbResult = m_database->getBathroomByBuilding(buildingName);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<BathroomDto>>>();

  auto page = PageDto<oatpp::Object<BathroomDto>>::createShared();
  page->offset = 1;
  page->limit = 20;
  page->count = items->size();
  page->items = items;

  return page;

}

/**
 * @brief updateBathroom method
 * 
 * Runs SQLite query to update a given bathroom
 * 
 * @param dto: BathroomDTO to be updated in database
 * 
 * @return dto of updated bathroom
*/
oatpp::Object<BathroomDto> BathroomService::updateBathroom(const oatpp::Object<BathroomDto>& dto) {

  auto dbResult = m_database->updateBathroom(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getBathroomById(dto->id);

}

/**
 * @brief deleteBathroom method
 * 
 * Runs SQLite query to delete a given bathroom
 * 
 * @param bathroomId Int, ID of bathroom to be deleted from database
 * 
 * @return status of operation
*/
oatpp::Object<StatusDto> BathroomService::deleteBathroom(const oatpp::Int32& bathroomId) {
  auto dbResult = m_database->deleteBathroom(bathroomId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Bathroom was successfully deleted";
  return status;
}
