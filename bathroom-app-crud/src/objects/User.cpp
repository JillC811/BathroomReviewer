/**
 * User.cpp -- User object
 * 
*/
#include "User.hpp"

/**
 * Default user constructor
 * 
 * id: id assigned to user
 * username: username chosen by user
 * email: user's email
 * role: whether user is an admin or not
 * 
**/

User::User() {
    id = 0;
    username = "";
    email = "";
    role = "";
}
/**
 * User constructor
 * 
 * creates user object using UserDTO
**/
User::User(oatpp::Object<UserDto> dto) {
    id = dto->id;
    username = dto->userName;
    email = dto->email;
    role = dto->role;
}

/**
 * convertToDTO method
 * 
 * converts a user object into a dto object
 * 
**/
oatpp::Object<UserDto> User::convertToDto() {
    auto dto = UserDto::createShared();

    dto->id = id;
    dto->userName = username.c_str();
    dto->email = email.c_str();
    dto->role = role.c_str();
    return dto;
}