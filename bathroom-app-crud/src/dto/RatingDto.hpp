#ifndef RatingDto_hpp
#define RatingDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @brief Bathroom Rating DTO class
 * DTO object to transfer data about buildings from database
 * @author Jill
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

  /**declare id field */
  DTO_FIELD(Int32, id); 
   /**declare uploader field */
  DTO_FIELD(String, uploader); 
   /**declare bathroomid field */
  DTO_FIELD(Int32, bathroomId);
   /**declare overallRating field */
  DTO_FIELD(Int32, overallRating);
   /**declare cleanlinessRating field */
  DTO_FIELD(Int32, cleanlinessRating);
   /**declare textReview field */
  DTO_FIELD(String, textReview);

}; 

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
