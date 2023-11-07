
#include "BathroomService.hpp"

oatpp::Object<BathroomDto> BathroomService::createBathroom(const oatpp::Object<BathroomDto>& dto) {

  auto dbResult = m_database->createBathroom(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto bathroomId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  return getBathroomById((v_int32) bathroomId);

}

oatpp::Object<PageDto<oatpp::Object<BathroomDto>>> BathroomService::getAllBathrooms(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

  oatpp::UInt32 countToFetch = limit;

  if(limit > 10) {
    countToFetch = 10;
  }

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

oatpp::Object<BathroomDto> BathroomService::getBathroomById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {

  auto dbResult = m_database->getBathroomById(id, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Bathroom not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BathroomDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];

}

oatpp::Object<PageDto<oatpp::Object<BathroomDto>>> BathroomService::getBathroomsByBuilding(const oatpp::String& buildingName) {


  auto dbResult = m_database->getBathroomsByBuilding(buildingName);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<BathroomDto>>>();

  auto page = PageDto<oatpp::Object<BathroomDto>>::createShared();
  page->offset = 1;
  page->limit = 20;
  page->count = items->size();
  page->items = items;

  return page;

}

oatpp::Object<BathroomDto> BathroomService::updateBathroom(const oatpp::Object<BathroomDto>& dto) {

  auto dbResult = m_database->updateBathroom(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getBathroomById(dto->id);

}

oatpp::Object<StatusDto> BathroomService::deleteBathroom(const oatpp::Int32& bathroomId) {
  auto dbResult = m_database->deleteBathroom(bathroomId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Bathroom was successfully deleted";
  return status;
}
