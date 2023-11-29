
#ifndef signInDto_hpp
#define signInDto_hpp

#include "UserDto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * DTO for sign in procedure
**/

class signInDto : public oatpp::DTO {
  
  /**initialize sign in dto*/
  DTO_INIT(signInDto, DTO);

  /** Add Username field*/
  DTO_FIELD(String, userName, "username");
  
  /** Add password field*/
  DTO_FIELD(String, password, "password");

};

#include OATPP_CODEGEN_END(DTO)

#endif //CRUD_signInDto_HPP
