#ifndef RatingDto_hpp
#define RatingDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Bathroom Rating DTO class
 * 
 * @param id: review id 
 * @param uploader: username of rating author
 * @param overallRating: Overall rating of bathroom from user
 * @param cleanlinessRating: Rating of how clean bathroom from user
 * @param textReview: Review of bathroom written by user, limited to number of characters
**/
class RatingDto : public oatpp::DTO {
  
  /**initialize rating */
  DTO_INIT(RatingDto, DTO)

  /**add id field */
  DTO_FIELD(Int32, id); 
   /**add uploader field */
  DTO_FIELD(String, uploader); 
   /**add bathroomid field */
  DTO_FIELD(Int32, bathroomId);
   /**add overallRating field */
  DTO_FIELD(Int32, overallRating);
   /**add cleanlinessRating field */
  DTO_FIELD(Int32, cleanlinessRating);
   /**add textReview field */
  DTO_FIELD(String, textReview);

}; 

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
