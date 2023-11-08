
#ifndef signInDto_hpp
#define signInDto_hpp

#include "UserDto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class signInDto : public oatpp::DTO {
  
  DTO_INIT(signInDto, DTO);

  DTO_FIELD(String, userName, "username");
  DTO_FIELD(String, password, "password");

};

#include OATPP_CODEGEN_END(DTO)

#endif //CRUD_signInDto_HPP