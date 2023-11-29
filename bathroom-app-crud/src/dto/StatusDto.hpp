
#ifndef CRUD_STATUSDTO_HPP
#define CRUD_STATUSDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @brief Status DTO class: return status of API call
 * 
 * @param status: status text
 * @param code: status code
 * @param message: status message
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
*/
class StatusDto : public oatpp::DTO {
  /**initialize statusDTO */
  DTO_INIT(StatusDto, DTO)

  /**status field info */
  DTO_FIELD_INFO(status) {
    info->description = "Short status text";
  }
  /**declare status field*/
  DTO_FIELD(String, status);

  /**code field info */
  DTO_FIELD_INFO(code) {
    info->description = "Status code";
  }
  /** declare code field*/
  DTO_FIELD(Int32, code);

  /** message field info*/
  DTO_FIELD_INFO(message) {
    info->description = "Verbose message";
  }
  /** declare message field*/
  DTO_FIELD(String, message);

};

#include OATPP_CODEGEN_END(DTO)

#endif //CRUD_STATUSDTO_HPP
