#ifndef BathroomDto_hpp
#define BathroomDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Bathroom DTO class, contains information about specific bathrooms
*/
class BathroomDto : public oatpp::DTO {
  
  DTO_INIT(BathroomDto, DTO)

  /**DTO fields
  *
  * id: randomly assigned integer for bathroom
  * building: name of building bathroom is in
  * floor: floor number bathroom is on
  * location: latitude and longitude coordinates of bathroom
  * gender: Char, M for male, F for female, B for both
  * stallCount: # of stalls in bathroom
  * urinalCount: # of urinals in bathroom
  * ratings: rating out of 5, averaged between users ratings
  * 
  * 
  **/
  DTO_FIELD(Int32, id);
  DTO_FIELD(String, building);
  DTO_FIELD(Int32, floor);
  DTO_FIELD(String, location);
  DTO_FIELD(String, gender);
  DTO_FIELD(Int32, stallCount);
  DTO_FIELD(Int32, urinalCount);
  DTO_FIELD(String, ratings);   //need to convert from string to vector of ints, look into oatpp enabled interpretations

};

#include OATPP_CODEGEN_END(DTO)

#endif /* BathroomDto_hpp */
