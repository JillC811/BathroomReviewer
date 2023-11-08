#ifndef BuildingDto_hpp
#define BuildingDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Building DTO class: contains information on buildings
 * 
 * name: name of building
 * location: longitude and latitude coordinates of building
*/
class BuildingDto : public oatpp::DTO {
  
  DTO_INIT(BuildingDto, DTO)

  DTO_FIELD(String, name);
  DTO_FIELD(String, location);

};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
