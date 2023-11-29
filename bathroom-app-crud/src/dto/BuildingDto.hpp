#ifndef BuildingDto_hpp
#define BuildingDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @brief Building DTO class
 * DTO object to transfer data about buildings from database
 * @author Joey
 * 
 * 
 * @param name randomly assigned integer for bathroom
 * @param latitude name of building bathroom is in
 * @param longitude floor number bathroom is on
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
