
#include "UserService.hpp"


/**
 * User Service
 * 
 * Contains user CRUD logic.
*/


/**
 * createUser method
 * 
 * Runs SQLite query to create user in database
 * 
 * dto: User DTO to be added to database
*/
oatpp::Object<UserDto> UserService::createUser(const oatpp::Object<UserDto>& dto) {

  auto dbResult = m_database->createUser(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto userId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  return getUserById((v_int32) userId);
}

/**
 * signIn method
 * 
 * Runs SQLite query to sign in user
 * 
 * dto: User login credentials
*/

oatpp::Object<UserDto> UserService::signIn(const oatpp::Object<signInDto>& dto) {
  auto dbResult = m_database->signIn(dto->userName, dto->password);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  return result[0];
}

/**
 * getAllUsers method
 * 
 * Runs SQLite query to fetch all users of the app
 * 
 * offset: query offset
 * limit: results limit
*/
oatpp::Object<PageDto<oatpp::Object<UserDto>>> UserService::getAllUsers(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

  oatpp::UInt32 countToFetch = limit;

  if(limit > 10) {
    countToFetch = 10;
  }

  auto dbResult = m_database->getAllUsers(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();

  auto page = PageDto<oatpp::Object<UserDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;

  return page;

}

/**
 * getUserById method
 * 
 * Runs SQLite query to fetch a specific user by id.
 * 
 * id: ID of requested user
*/
oatpp::Object<UserDto> UserService::getUserById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {

  auto dbResult = m_database->getUserById(id, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "User not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];

}

/**
 * updateUser method
 * 
 * Runs SQLite query to update a given user
 * 
 * dto: User DTO to be updated in database
*/
oatpp::Object<UserDto> UserService::updateUser(const oatpp::Object<UserDto>& dto) {

  auto dbResult = m_database->updateUser(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getUserById(dto->id);

}

/**
 * deleteUserById method
 * 
 * Runs SQLite query to delete a given user
 * 
 * userId: ID of user to be deleted from database
*/
oatpp::Object<StatusDto> UserService::deleteUserById(const oatpp::Int32& userId) {
  auto dbResult = m_database->deleteUserById(userId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "User was successfully deleted";
  return status;
}