#ifndef BathroomDto_hpp
#define BathroomDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "RatingDto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class BathroomDto : public oatpp::DTO {
  
  DTO_INIT(BathroomDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(String, building);
  DTO_FIELD(Int32, floor);
  DTO_FIELD(String, location);
  DTO_FIELD(String, gender);
  DTO_FIELD(Int32, stallCount);
  DTO_FIELD(Int32, urinalCount);
  DTO_FIELD(List<Object<RatingDto>>, rating);

};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
