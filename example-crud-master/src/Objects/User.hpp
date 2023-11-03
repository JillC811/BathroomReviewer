#ifndef User_hpp
#define User_hpp
#include <string>
#include "../dto/UserDto.hpp"


class User {
    public:
        User();
        std::string username;
        std::string email;
        std::string firstName;
        std::string lastName;

        User(oatpp::Object<UserDto> dto);

        oatpp::Object<UserDto> convertToDto();
};

#endif //User_hpp