
#include "BuildingService.hpp"

oatpp::Object<BuildingDto> BuildingService::getBuilding(const oatpp::String& name, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {

  auto dbResult = m_database->getBuilding(name, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Building not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BuildingDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];

}
