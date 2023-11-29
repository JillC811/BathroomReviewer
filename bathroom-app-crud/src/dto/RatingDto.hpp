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

  DTO_FIELD(Int32, id); 
  DTO_FIELD(String, uploader); 
  DTO_FIELD(Int32, bathroomId);
  DTO_FIELD(Int32, overallRating);
  DTO_FIELD(Int32, cleanlinessRating);
  DTO_FIELD(String, textReview);

}; 

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
