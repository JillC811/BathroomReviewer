
#ifndef CRUD_APPDB_HPP
#define CRUD_APPDB_HPP

#include "dto/UserDto.hpp"
#include "dto/BathroomDto.hpp"
#include "dto/BuildingDto.hpp"
#include "dto/RatingDto.hpp"
#include "oatpp-sqlite/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * AppDb client definitions.
 */
class AppDb : public oatpp::orm::DbClient
{
public:
      AppDb(const std::shared_ptr<oatpp::orm::Executor> &executor)
          : oatpp::orm::DbClient(executor)
      {
            // initialize db with schema
            oatpp::orm::SchemaMigration migration(executor);
            migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/001_init.sql");
            // TODO - Add more migrations here.
            migration.migrate(); // <-- run migrations. This guy will throw on error.

            auto version = executor->getSchemaVersion();
            OATPP_LOGD("AppDb", "Migration - OK. Version=%ld.", version);
      }

      ////////////////////////////
      ///// Users
      /////////////////

      QUERY(createUser,
            "INSERT INTO AppUser"
            "(username, email, password, role) VALUES "
            "(:user.username, :user.email, :user.password, :user.role);",
            PARAM(oatpp::Object<UserDto>, user))
      QUERY(signIn,
            "SELECT * FROM AppUser WHERE username=:username AND password=:password;",
            PARAM(oatpp::String, username),
            PARAM(oatpp::String, password)
      )
      QUERY(getAllUsers,
            "SELECT * FROM AppUser LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit))
            
      QUERY(getUserById,
            "SELECT * FROM AppUser WHERE id=:id;",
            PARAM(oatpp::Int32, id))

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

      QUERY(deleteUserById,
            "DELETE FROM AppUser WHERE id=:id;",
            PARAM(oatpp::Int32, id))


      ////////////////////////////
      ///// Bathrooms
      /////////////////

      //this create bathroom method does not add a rating meaning trying to get a rating doesnt work after creating a bathroom :bathroom.ratings
      QUERY(createBathroom,
            "INSERT INTO Bathroom"
            "(building, floor, latitude, longitude, gender, stallCount, urinalCount) VALUES "
            "(:bathroom.building, :bathroom.floor, :bathroom.latitude, :bathroom.longitude, :bathroom.gender, :bathroom.stallCount, :bathroom.urinalCount);",
            PARAM(oatpp::Object<BathroomDto>, bathroom))

      QUERY(getAllBathrooms,
            "SELECT * FROM Bathroom LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit))

      QUERY(getBathroomById,
            "SELECT * FROM Bathroom WHERE id=:id;",
            PARAM(oatpp::Int32, id))

      QUERY(getBathroomByBuilding,
            "SELECT * FROM Bathroom WHERE building=:building;",
            PARAM(oatpp::String, building))
      
      QUERY(updateBathroom,
            "UPDATE Bathroom "
            "SET "
            " building=:bathroom.building, "
            " floor=:bathroom.floor, "
            " latitude=:bathroom.latitude, "
            " longitude=:bathroom.longitude, "
            " gender=:bathroom.gender "
            " stallCount=:bathroom.stallCount "
            " urinalCount=:bathroom.urinalCount "
            " ratings=:bathroom.ratings "
            "WHERE "
            " id=:bathroom.id;",
            PARAM(oatpp::Object<BathroomDto>, bathroom))

      QUERY(deleteBathroom,
            "DELETE FROM Bathroom WHERE id=:id;",
            PARAM(oatpp::Int32, id))

      ////////////////////////////
      ///// Buildings
      /////////////////

      QUERY(createBuilding,
            "INSERT INTO Building"
            "(name, latitude, longitude) VALUES "
            "(:building.name, :building.latitude, :building.longitude);",
            PARAM(oatpp::Object<BuildingDto>, building))

      QUERY(getAllBuildings,
            "SELECT * FROM Building LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit))

      QUERY(getBuildingByName,
            "SELECT * FROM Building WHERE name=:name;",
            PARAM(oatpp::String, name))

      // NOTE:
      // Update Building currently updating by name, not by id. Consider if we want this or not.
      QUERY(updateBuilding,
            "UPDATE Building "
            "SET "
            " name=:building.name, "
            " latitude=:bathroom.latitude, "
            " longitude=:bathroom.longitude, "
            "WHERE "
            " name=:building.name;",
            PARAM(oatpp::Object<BuildingDto>, building))

      // NOTE:
      // Delete Building currently deleting by name, not by id. Consider if we want this or not.
      QUERY(deleteBuilding,
            "DELETE FROM Building WHERE name=:name;",
            PARAM(oatpp::String, name))
      
      ////////////////////////////
      ///// Ratings
      /////////////////

      QUERY(createRating,
            "INSERT INTO Rating"
            "(bathroomId, uploader, overallRating, cleanlinessRating, textReview) VALUES "
            "(:rating.bathroomId, :rating.uploader, :rating.overallRating, :rating.cleanlinessRating, :rating.textReview);",
            PARAM(oatpp::Object<RatingDto>, rating))

      QUERY(getAllRatings,
            "SELECT * FROM Rating LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit))

      QUERY(getRatingById,
            "SELECT * FROM Rating WHERE id=:id;",
            PARAM(oatpp::Int32, id))

      QUERY(getRatingByUser,
            "SELECT * FROM Rating WHERE uploader=:uploader;",
            PARAM(oatpp::String, uploader))

      QUERY(getRatingByBathroom,
            "SELECT * FROM Rating WHERE bathroomId=:bathroomId;",
            PARAM(oatpp::Int32, bathroomId))
      
      QUERY(updateRating,
            "UPDATE Rating"
            "SET "
            " uploader=:rating.uploader, "
            " bathroomId=:rating.bathroomId, "
            " overallRating=:rating.overallRating, "
            " cleanlinessRating=:rating.cleanlinessRating, "
            " textReview=:rating.textReview "
            "WHERE "
            " id=:rating.id;",
            PARAM(oatpp::Object<RatingDto>, rating))

      QUERY(deleteRating,
            "DELETE FROM Rating WHERE id=:id;",
            PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif // CRUD_APPDB_HPP
