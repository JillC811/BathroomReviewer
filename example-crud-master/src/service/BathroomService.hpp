
#ifndef CRUD_BATHROOMSERVICE_HPP
#define CRUD_BATHROOMSERVICE_HPP

#include "db/AppDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BathroomService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<AppDb>, m_database); // Inject database component
public:

  oatpp::Object<BathroomDto> createBathroom(const oatpp::Object<BathroomDto>& dto);
  oatpp::Object<PageDto<oatpp::Object<BathroomDto>>> getAllBathrooms(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<BathroomDto> getBathroomById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection = nullptr);
  oatpp::Object<BathroomDto> updateBathroom(const oatpp::Object<BathroomDto>& dto);
  oatpp::Object<StatusDto> deleteBathroom(const oatpp::Int32& id);

};

#endif
