
#include "BuildingService.hpp"

oatpp::Object<BuildingDto> BuildingService::createBuilding(const oatpp::Object<BuildingDto>& dto) {

  auto dbResult = m_database->createBuilding(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  return getBuildingByName(dto->name);

}

oatpp::Object<PageDto<oatpp::Object<BuildingDto>>> BuildingService::getAllBuildings(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

  oatpp::UInt32 countToFetch = limit;

  if(limit > 10) {
    countToFetch = 10;
  }

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

oatpp::Object<BuildingDto> BuildingService::getBuildingByName(const oatpp::String& buildingName, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {

  auto dbResult = m_database->getBuildingByName(buildingName, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Building not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BuildingDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];

}

oatpp::Object<BuildingDto> BuildingService::updateBuilding(const oatpp::Object<BuildingDto>& dto) {

  auto dbResult = m_database->updateBuilding(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getBuildingByName(dto->name);

}

oatpp::Object<StatusDto> BuildingService::deleteBuilding(const oatpp::String& buildingName) {
  auto dbResult = m_database->deleteBuilding(buildingName);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Building was successfully deleted";
  return status;
}

