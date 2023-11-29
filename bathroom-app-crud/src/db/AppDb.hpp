
#ifndef CRUD_APPDB_HPP
#define CRUD_APPDB_HPP

#include "dto/UserDto.hpp"
#include "dto/BathroomDto.hpp"
#include "dto/BuildingDto.hpp"
#include "dto/RatingDto.hpp"
#include "oatpp-sqlite/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) 
/*
*Main app client for interfacing with data in database, contains all the queries for the database
*/
class AppDb : public oatpp::orm::DbClient
{
/**
 * AppDb client definitions.
 */
public:
      AppDb(const std::shared_ptr<oatpp::orm::Executor> &executor)
          : oatpp::orm::DbClient(executor)
      {
            oatpp::orm::SchemaMigration migration(executor);
            migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/001_init.sql");

            migration.migrate(); 

            auto version = executor->getSchemaVersion();
            OATPP_LOGD("AppDb", "Migration - OK. Version=%ld.", version);
      }


      /**
      * createUser Query, inserts new user into database
      * 
      * @param username User's username
      * @param email User's email
      * @param password User's account password
      * @param role Whether user is a admin or a regular user
      */
      QUERY(createUser,
            "INSERT INTO AppUser"
            "(username, email, password, role) VALUES "
            "(:user.username, :user.email, :user.password, :user.role);",
            PARAM(oatpp::Object<UserDto>, user)
            )

      /**
      * signIn Query, checks for user's username and password
      * 
      * @param username User's username
      * @param password User's account password
      */
      QUERY(signIn,
            "SELECT * FROM AppUser WHERE username=:username AND password=:password;",
            PARAM(oatpp::String, username),
            PARAM(oatpp::String, password)
            )

      /**
      * getAllUsers Query, gets all users in database within a range
      * 
      * @param offset how many users to skip
      * @param limit how many users to return
      */
      QUERY(getAllUsers,
            "SELECT * FROM AppUser LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit)
            )

      /**
      * getUserById query: gets user from id
      * 
      * @param id User's id
      */
      QUERY(getUserById,
            "SELECT * FROM AppUser WHERE id=:id;",
            PARAM(oatpp::Int32, id)
            )
      //
      /**
      * updateUser query, updates user using their id
      * 
      * @param username User's username
      * @param email User's email
      * @param password User's account password
      * @param role Whether user is a admin or a regular user
      * @param id user's id
      */
      QUERY(updateUser,
            "UPDATE AppUser "
            "SET "
            " username=:user.username, "
            " email=:user.email, "
            " password=:user.password, "
            " role=:user.role "
            "WHERE "
            " id=:user.id;",
            PARAM(oatpp::Object<UserDto>, user)
            )
      
      /**
      * deleteUserById query: removes user from database
      * 
      * @param id id of User to be deleted
      */    
      QUERY(deleteUserById,
            "DELETE FROM AppUser WHERE id=:id;",
            PARAM(oatpp::Int32, id)
            )

    

      ////////////////////////////
      ///// Bathroom
      /////////////////


      /**
      * createBathroom Query, inserts new user into database
      * 
      * @param building Building where bathroom is located
      * @param flood Which floor of Building bathroom is on
      * @param latitude exact latitude of bathroom
      * @param longitude exact longitude of bathroom
      * @param gender gender of bathroom
      * @param stallCount # of stalls in bathroom
      * @param urinalCount # of urinals in bathroom
      */
      QUERY(createBathroom,
            "INSERT INTO Bathroom"
            "(building, floor, latitude, longitude, gender, stallCount, urinalCount) VALUES "
            "(:bathroom.building, :bathroom.floor, :bathroom.latitude, :bathroom.longitude, :bathroom.gender, :bathroom.stallCount, :bathroom.urinalCount);",
            PARAM(oatpp::Object<BathroomDto>, bathroom))
      
      /**
      * getAllBathrooms Query, gets all bathrooms in database within a range
      * 
      * @param offset how many users to skip
      * @param limit how many users to return
      */
      QUERY(getAllBathrooms,
            "SELECT * FROM Bathroom LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit))
      
      /**
      * getBathroomById Query, gets bathroom by id in database
      * 
      * @param building Building where bathroom is located
      */
      QUERY(getBathroomById,
            "SELECT * FROM Bathroom WHERE id=:id;",
            PARAM(oatpp::Int32, id))
      
      /**
      * getBathroomByBuilding query, gets list of bathrooms by building
      * 
      * @param building Building where bathroom is located
      */
      QUERY(getBathroomByBuilding,
            "SELECT * FROM Bathroom WHERE building=:building;",
            PARAM(oatpp::String, building))
      
      /**
      * updateBathroom Query, updates bathroom info in databse
      * 
      * @param building Building where bathroom is located
      * @param flood Which floor of Building bathroom is on
      * @param latitude exact latitude of bathroom
      * @param longitude exact longitude of bathroom
      * @param gender gender of bathroom
      * @param stallCount # of stalls in bathroom
      * @param urinalCount # of urinals in bathroom
      * 
      * @param id id of bathroom in database
      */
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
      
      /**
      * deleteBathroom Query, deletes bathroom from database
      * 
      * @param id id of bathroom to be deleted
      */
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

      QUERY(updateBuilding,
            "UPDATE Building "
            "SET "
            " name=:building.name, "
            " latitude=:bathroom.latitude, "
            " longitude=:bathroom.longitude, "
            "WHERE "
            " name=:building.name;",
            PARAM(oatpp::Object<BuildingDto>, building))

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
