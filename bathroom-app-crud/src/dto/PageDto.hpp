
#ifndef CRUD_PAGEDTO_HPP
#define CRUD_PAGEDTO_HPP

#include "UserDto.hpp"
#include "BathroomDto.hpp"
#include "RatingDto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * @brief Page DTO class: one page of data based on the specified offset and limit
 * 
 * @param offset: query offset
 * @param limit: results limit
 * @param count: number of returned results
 * @param items: returned result
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
*/

template<class T>

/**
 * @brief page DTO class
 * DTO object to transfer multiple dtos from database onto one page
 * @author Justin
 * 
 * 
 * @param offset database place to start at
 * @param limit spot of last item to be pulled
 * @param count number of items pulled
 * @param items dtos pulled from database
*/
class PageDto : public oatpp::DTO {

  /**initialize page dto*/
  DTO_INIT(PageDto, DTO)
  /**declare offset field*/
  DTO_FIELD(UInt32, offset);
  /**declare limit field*/
  DTO_FIELD(UInt32, limit);
  /**declare count field*/
  DTO_FIELD(UInt32, count);
  /**declare items field*/
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
