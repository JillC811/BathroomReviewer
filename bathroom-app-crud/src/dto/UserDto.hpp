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
 * @brief user dto class
 * DTO object to transfer data about user from database
 * @author Justin
 * 
 * 
 * @param id id of user in database
 * @param username username of user in database
 * @param email email of user in database
 * @param password password of user in database
 * @param role whether user is an admin or regular user
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
