
#ifndef CRUD_PAGEDTO_HPP
#define CRUD_PAGEDTO_HPP

#include "UserDto.hpp"
#include "BathroomDto.hpp"
#include "RatingDto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

template<class T>
class PageDto : public oatpp::DTO {

  DTO_INIT(PageDto, DTO)

  DTO_FIELD(UInt32, offset);
  DTO_FIELD(UInt32, limit);
  DTO_FIELD(UInt32, count);
  DTO_FIELD(Vector<T>, items);

};

class UsersPageDto : public PageDto<oatpp::Object<UserDto>> {

  DTO_INIT(UsersPageDto, PageDto<oatpp::Object<UserDto>>)

};

class BathroomsPageDto : public PageDto<oatpp::Object<BathroomDto>> {

  DTO_INIT(BathroomsPageDto, PageDto<oatpp::Object<BathroomDto>>)

};

class BuildingsPageDto : public PageDto<oatpp::Object<BuildingDto>> {

  DTO_INIT(BuildingsPageDto, PageDto<oatpp::Object<BuildingDto>>)

};

class RatingPageDto : public PageDto<oatpp::Object<RatingDto>> {

  DTO_INIT(RatingPageDto, PageDto<oatpp::Object<RatingDto>>)

};

#include OATPP_CODEGEN_END(DTO)

#endif //CRUD_PAGEDTO_HPP
