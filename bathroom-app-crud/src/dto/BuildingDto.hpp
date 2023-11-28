#ifndef BuildingDto_hpp
#define BuildingDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @brief Building DTO class: contains information on buildings
 * 
 * @param name: name of building
 * @param longitude: longitude of building
 * @param latitude: latitude of building
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
*/
class BuildingDto : public oatpp::DTO {
  /**iinitialize buildingdto */
  DTO_INIT(BuildingDto, DTO)

  /**declare name field */
  DTO_FIELD(String, name);
  /**declare longitude field */
  DTO_FIELD(String, longitude);
  /**declare latitude field */
  DTO_FIELD(String, latitude);

};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
