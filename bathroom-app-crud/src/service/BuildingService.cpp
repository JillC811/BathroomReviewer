
#include "BuildingService.hpp"


/**
 * @brief Building Service
 * 
 * Contains Building CRUD logic.
*/

/**
 * @brief createBuilding method
 * 
 * Runs SQLite query to create building in database
 * 
 * @param dto BuildingDTO to be added to database
 * 
 * @return dto of requested building
*/
oatpp::Object<BuildingDto> BuildingService::createBuilding(const oatpp::Object<BuildingDto>& dto) {

  auto dbResult = m_database->createBuilding(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  return getBuildingByName(dto->name);

}

/**
 * @brief getAllBuildings method
 * 
 * Runs SQLite fetch all buildings logged in app
 * 
 * @param offset Int, query offset
 * @param limit Int, results limit
 * 
 * @return PageDTO containing buildingDTO
*/
oatpp::Object<PageDto<oatpp::Object<BuildingDto>>> BuildingService::getAllBuildings(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

  oatpp::UInt32 countToFetch = limit;

  auto dbResult = m_database->getAllBuildings(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<BuildingDto>>>();

  auto page = PageDto<oatpp::Object<BuildingDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;

  return page;

}

/**
 * @brief getBuildingByName method
 * 
 * Runs SQLite query to fetch a specific building by name.
 * 
 * @param buildingName String, name of requested building
 * 
 * @return requested buildingDTO
*/
oatpp::Object<BuildingDto> BuildingService::getBuildingByName(const oatpp::String& buildingName, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {

  auto dbResult = m_database->getBuildingByName(buildingName, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Building not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BuildingDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];

}

/**
 * @brief updateBuilding method
 * 
 * Runs SQLite query to update a given building
 * 
 * @param dto: Building DTO to be updated in database
 * 
 * @return dto of updated building in database
*/
oatpp::Object<BuildingDto> BuildingService::updateBuilding(const oatpp::Object<BuildingDto>& dto) {

  auto dbResult = m_database->updateBuilding(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getBuildingByName(dto->name);

}

/**
 * @brief deleteBuilding method
 * 
 * Runs SQLite query to delete a given building
 * 
 * @param buildingName: Name of building to be deleted from database
 * 
 * @return status of deletion
*/
oatpp::Object<StatusDto> BuildingService::deleteBuilding(const oatpp::String& buildingName) {
  auto dbResult = m_database->deleteBuilding(buildingName);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Building was successfully deleted";
  return status;
}

