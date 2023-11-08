
#ifndef CRUD_APPDB_HPP
#define CRUD_APPDB_HPP

#include "dto/UserDto.hpp"
#include "dto/BathroomDto.hpp"
#include "dto/BuildingDto.hpp"
#include "oatpp-sqlite/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * AppDb client definitions.
 */
class AppDb : public oatpp::orm::DbClient {
public:

  AppDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

    oatpp::orm::SchemaMigration migration(executor);
    migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/001_init.sql");
    // TODO - Add more migrations here.
    migration.migrate(); // <-- run migrations. This guy will throw on error.

    auto version = executor->getSchemaVersion();
    OATPP_LOGD("AppDb", "Migration - OK. Version=%lld.", version);

  }

  QUERY(signIn,
      "SELECT * FROM AppUser WHERE username=:username AND password=:password;",
      PARAM(oatpp::String, username),
      PARAM(oatpp::String, password)
  )

  QUERY(createUser,
        "INSERT INTO AppUser"
        "(username, email, password, role) VALUES "
        "(:user.username, :user.email, :user.password, :user.role);",
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(updateUser,
        "UPDATE AppUser "
        "SET "
        " username=:user.username, "
        " email=:user.email, "
        " password=:user.password, "
        " role=:user.role "
        "WHERE "
        " id=:user.id;",
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(getUserById,
        "SELECT * FROM AppUser WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(getAllUsers,
        "SELECT * FROM AppUser LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteUserById,
        "DELETE FROM AppUser WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(getBathroomByID, 
      "SELECT * FROM bathroom WHERE id=:id;", 
      PARAM(oatpp::Int32, id))

  QUERY(getBuilding, 
      "SELECT * FROM Building WHERE name=:name;", 
      PARAM(oatpp::String, name))  

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //CRUD_APPDB_HPP
