
#include "BathroomService.hpp"

oatpp::Object<BathroomDto> BathroomService::getBathroomById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {

  auto dbResult = m_database->getBathroomByID(id, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Bathroom not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BathroomDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];

}

// oatpp::Vector<oatpp::Object<BathroomDto>> BathroomService::getAllBathrooms(const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {
//   auto dbResult = m_database->getAllBathrooms(id, connection);
//   OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
//   OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "No bathrooms");

//   auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BathroomDto>>>();
//   OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

//   return result;

// }