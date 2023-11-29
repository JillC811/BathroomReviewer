
#ifndef signInDto_hpp
#define signInDto_hpp

#include "UserDto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * @brief Sign in DTO class, holds sign in data
 * 
 * @param userName: entered username
 * @param password: entered password
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
**/

class signInDto : public oatpp::DTO {
  
  /**initialize sign in dto*/
  DTO_INIT(signInDto, DTO);

  /** declare Username field*/
  DTO_FIELD(String, userName, "username");

  /** declare password field*/
  DTO_FIELD(String, password, "password");

};

#include OATPP_CODEGEN_END(DTO)

#endif //CRUD_signInDto_HPP
