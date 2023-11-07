#ifndef RatingDto_hpp
#define RatingDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class RatingDto : public oatpp::DTO {
  
  DTO_INIT(RatingDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(Int32, overallRating);
  DTO_FIELD(Int32, cleanlinessRating);
  DTO_FIELD(String, textReview);

};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
