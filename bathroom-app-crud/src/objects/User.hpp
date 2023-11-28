#ifndef User_hpp
#define User_hpp
#include <string>
#include "../dto/UserDto.hpp"

/**
 * Default user constructor
 * 
 * @param id: id assigned to user
 * @param username: username chosen by user
 * @param email: user's email
 * @param role: whether user is an admin or not
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
**/
class User {
    public:
        User();
        oatpp::Int32 id;
        std::string username;
        std::string email;
        std::string role;

        User(oatpp::Object<UserDto> dto);

        oatpp::Object<UserDto> convertToDto();
};

#endif //User_hpp