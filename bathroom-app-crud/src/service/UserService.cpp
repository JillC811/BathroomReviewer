
#include "UserService.hpp"


/**
 * @brief User Service
 * 
 * Contains user CRUD logic.
*/


/**
 * @brief createUser method
 * 
 * Runs SQLite query to create user in database
 * 
 * @param dto: UserDTO, User DTO to be added to database
 * 
 * @return user added to db
*/
oatpp::Object<UserDto> UserService::createUser(const oatpp::Object<UserDto>& dto) {

  auto dbResult = m_database->createUser(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto userId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  return getUserById((v_int32) userId);
}

/**
 * @brief signIn method
 * 
 * Runs SQLite query to sign in user
 * 
 * @param dto signinDTO, user's credentials
 * 
 * @return statusDTO whether signin was sucessful
*/

oatpp::Object<UserDto> UserService::signIn(const oatpp::Object<signInDto>& dto) {
  auto dbResult = m_database->signIn(dto->userName, dto->password);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  return result[0];
}

/**
 * @brief getAllUsers method
 * 
 * Runs SQLite query to fetch all users of the app
 * 
 * @param offset Int, query offset
 * @param limit Int,  results limit
 * 
 * @return users
*/
oatpp::Object<PageDto<oatpp::Object<UserDto>>> UserService::getAllUsers(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

  oatpp::UInt32 countToFetch = limit;

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
 * @brief getUserById method
 * 
 * Runs SQLite query to fetch a specific user by id.
 * 
 * @param id Int, ID of requested user
 * 
 * @return dto of requested user or status if not found
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
 * @brief updateUser method
 * 
 * Runs SQLite query to update a given user
 * 
 * @param dto UserDTO to be updated in database
 * 
 * @return updated user in db
*/
oatpp::Object<UserDto> UserService::updateUser(const oatpp::Object<UserDto>& dto) {

  auto dbResult = m_database->updateUser(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getUserById(dto->id);

}

/**
 * @brief deleteUserById method
 * 
 * Runs SQLite query to delete a given user
 * 
 * @param userId Int,ID of user to be deleted from database
 * 
 * @return status of deletion 
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