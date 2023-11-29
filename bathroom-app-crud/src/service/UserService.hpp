
#ifndef CRUD_USERSERVICE_HPP
#define CRUD_USERSERVICE_HPP

#include "db/AppDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"
#include "dto/SignInDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"


/**
 * @brief User Service class
 * 
 * Contains user CRUD database operations
*/

class UserService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
/**
 * Injects database component
 */ 
  OATPP_COMPONENT(std::shared_ptr<AppDb>, m_database);
public:

  oatpp::Object<UserDto> createUser(const oatpp::Object<UserDto>& dto);
  oatpp::Object<UserDto> signIn(const oatpp::Object<signInDto>& dto);
  
  oatpp::Object<PageDto<oatpp::Object<UserDto>>> getAllUsers(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<UserDto> getUserById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection = nullptr);
  oatpp::Object<UserDto> updateUser(const oatpp::Object<UserDto>& dto);
  oatpp::Object<StatusDto> deleteUserById(const oatpp::Int32& id);

};

#endif //CRUD_USERSERVICE_HPP
