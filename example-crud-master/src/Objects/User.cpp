/**
 * User.cpp -- User object
 * 
*/
#include "User.hpp"

User::User() {
    id = 0;
    username = "";
    email = "";
    firstName = "";
    lastName = "";
    role = "";
}

User::User(oatpp::Object<UserDto> dto) {
    id = dto->id;
    username = dto->userName;
    email = dto->email;
    firstName = dto->firstName;
    lastName = dto->lastName;
    role = dto->role;
}

oatpp::Object<UserDto> User::convertToDto() {
    auto dto = UserDto::createShared();

    dto->id = id;
    dto->userName = username.c_str();
    dto->email = email.c_str();
    dto->role = role.c_str();
    return dto;
}