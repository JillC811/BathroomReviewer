
#ifndef CRUD_BATHROOMSERVICE_HPP
#define CRUD_BATHROOMSERVICE_HPP

#include "db/AppDb.hpp"
// #include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BathroomService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<AppDb>, m_database); // Inject database component
public:

  oatpp::Object<BathroomDto> getBathroomById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection = nullptr);

};

#endif //CRUD_USERSERVICE_HPP
