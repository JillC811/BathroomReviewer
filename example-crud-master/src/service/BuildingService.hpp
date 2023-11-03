
#ifndef BuildingService_hpp
#define BuildingService_HPP

#include "db/AppDb.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BuildingService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<AppDb>, m_database); // Inject database component
public:

  oatpp::Object<BuildingDto> getBuilding(const oatpp::String& name, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection = nullptr);

};

#endif //CRUD_USERSERVICE_HPP
