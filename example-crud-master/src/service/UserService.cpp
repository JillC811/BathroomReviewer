
#include "UserService.hpp"


oatpp::Object<UserDto> UserService::createUser(const oatpp::Object<UserDto>& dto) {

  auto dbResult = m_database->createUser(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  
  auto userId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  return getUserById((v_int32) userId);

}

oatpp::Object<UserDto> UserService::signIn(const oatpp::Object<signInDto>& dto) {
  auto dbResult = m_database->signIn(dto->userName, dto->password);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  return result[0];
}

User UserService::getUserObjectById(const oatpp::Int32& id) {

  auto dbResult = m_database->getUserById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "User not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  return User(result[0]);
}

oatpp::Object<UserDto> UserService::getUserById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {

  auto dbResult = m_database->getUserById(id, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "User not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  
  return result[0];

}

oatpp::Object<StatusDto> UserService::deleteUserById(const oatpp::Int32& userId) {
  auto dbResult = m_database->deleteUserById(userId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "User was successfully deleted";
  return status;
}