
#ifndef BUILDINGSERVICE_HPP
#define BUILDINGSERVICE_HPP

#include "db/AppDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BuildingService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<AppDb>, m_database); // Inject database component
public:

  oatpp::Object<BuildingDto> createBuilding(const oatpp::Object<BuildingDto>& dto);
  oatpp::Object<PageDto<oatpp::Object<BuildingDto>>> getAllBuildings(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<BuildingDto> getBuildingByName(const oatpp::String& buildingName, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection = nullptr);
  oatpp::Object<BuildingDto> updateBuilding(const oatpp::Object<BuildingDto>& dto);
  oatpp::Object<StatusDto> deleteBuilding(const oatpp::String& buildingName);

};

#endif
