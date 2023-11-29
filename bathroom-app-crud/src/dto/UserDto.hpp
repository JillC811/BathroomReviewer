#ifndef UserDto_hpp
#define UserDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"


#include OATPP_CODEGEN_BEGIN(DTO)

// ENUM(Role, v_int32,
//      VALUE(GUEST, 0, "ROLE_GUEST"),
//      VALUE(ADMIN, 1, "ROLE_ADMIN")
// )

/**
 * @brief User DTO class: Info for a user of the app
 * 
 * @param id: user identifier
 * @param userName: user's username
 * @param email: user's email
 * @param password: user's password
 * @param role: user's role (Admin or general)
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
*/
class UserDto : public oatpp::DTO {

  /** initialize user dto*/
  DTO_INIT(UserDto, DTO)
  
  /** declare id field*/
  DTO_FIELD(Int32, id);
  /** declare username field*/
  DTO_FIELD(String, userName, "username");
  /** declare email field*/
  DTO_FIELD(String, email, "email");
  /** declare password field*/
  DTO_FIELD(String, password, "password");
  /** declare role field*/
  DTO_FIELD(String, role, "role");
};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
