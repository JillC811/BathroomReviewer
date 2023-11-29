#ifndef BathroomDto_hpp
#define BathroomDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @brief Bathroom DTO class: contains information on bathroom
 * 
 * @param id: bathroom identifier
 * @param building: name of building bathroom is in
 * @param floor: floor bathroom is on
 * @param location: latitude and longitude coordinates of bathroom
 * @param gender: Char, M for male, F for female, B for both
 * @param stallCount: # of stalls in bathroom
 * @param urinalCount: # of urinals in bathroom
 * @param ratings: rating out of 5, averaged between users ratings
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
*/
class BathroomDto : public oatpp::DTO {
  
  /** intialize bathroomdto*/
  DTO_INIT(BathroomDto, DTO)

   /**declare id field */
  DTO_FIELD(Int32, id);
  /**declare building field */
  DTO_FIELD(String, building);
  /**declare flood field */
  DTO_FIELD(Int32, floor);
  /**declare longitude field */
  DTO_FIELD(String, longitude);
  /**declare latitude field */
  DTO_FIELD(String, latitude);
  /**declare gender field */
  DTO_FIELD(String, gender);
  /**declare stallCount field */
  DTO_FIELD(Int32, stallCount);
  /**declare urinalCount field */
  DTO_FIELD(Int32, urinalCount);
  /**declare ratings field */
  DTO_FIELD(String, ratings);   

};

#include OATPP_CODEGEN_END(DTO)

#endif /* BathroomDto_hpp */
