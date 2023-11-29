
#ifndef CRUD_STATUSDTO_HPP
#define CRUD_STATUSDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Status Dto to return status of API call
 * 
**/
class StatusDto : public oatpp::DTO {
  /**initialize statusDTO */
  DTO_INIT(StatusDto, DTO)

  /**status field info */
  DTO_FIELD_INFO(status) {
    info->description = "Short status text";
  }
  /**add status field*/
  DTO_FIELD(String, status);

  /**add code field*/
  DTO_FIELD_INFO(code) {
    info->description = "Status code";
  }
  DTO_FIELD(Int32, code);

  DTO_FIELD_INFO(message) {
    info->description = "Verbose message";
  }
  DTO_FIELD(String, message);

};

#include OATPP_CODEGEN_END(DTO)

#endif //CRUD_STATUSDTO_HPP
