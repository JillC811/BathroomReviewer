#ifndef User_hpp
#define User_hpp
#include <string>
#include "../dto/UserDto.hpp"


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