/**
 * @brief Main app client for interfacing with data in database, contains all the queries for the database 
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
 * 
*/


#ifndef CRUD_APPDB_HPP
#define CRUD_APPDB_HPP

#include "dto/UserDto.hpp"
#include "dto/BathroomDto.hpp"
#include "dto/BuildingDto.hpp"
#include "dto/RatingDto.hpp"
#include "oatpp-sqlite/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) 
class AppDb : public oatpp::orm::DbClient
{
/**
 * @brief AppDb client definitions.
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
      * @brief createUser Query, inserts new user into database
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
      * @brief signIn Query, checks for user's username and password
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
      * @brief getAllUsers Query, gets all users in database within a range
      * 
      * @param offset how many users to skip
      * @param limit max number of users to return
      */
      QUERY(getAllUsers,
            "SELECT * FROM AppUser LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit)
            )

      /**
      * @brief getUserById query: gets user from id
      * 
      * @param id User's id
      */
      QUERY(getUserById,
            "SELECT * FROM AppUser WHERE id=:id;",
            PARAM(oatpp::Int32, id)
            )
      //
      /**
      * @brief updateUser query, updates user using their id
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
      * @brief deleteUserById query: removes user from database
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
      * @brief createBathroom Query, inserts new user into database
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
      * @brief getAllBathrooms Query, gets all bathrooms in database within a range
      * 
      * @param offset how many users to skip
      * @param limit how many users to return
      */
      QUERY(getAllBathrooms,
            "SELECT * FROM Bathroom LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit))
      
      /**
      * @brief getBathroomById Query, gets bathroom by id in database
      * 
      * @param building Building where bathroom is located
      */
      QUERY(getBathroomById,
            "SELECT * FROM Bathroom WHERE id=:id;",
            PARAM(oatpp::Int32, id))
      
      /**
      * @brief getBathroomByBuilding query, gets list of bathrooms by building
      * 
      * @param building Building where bathroom is located
      */
      QUERY(getBathroomByBuilding,
            "SELECT * FROM Bathroom WHERE building=:building;",
            PARAM(oatpp::String, building))
      
      /**
      * @brief updateBathroom Query, updates bathroom info in databse
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
      * @brief deleteBathroom Query, deletes bathroom from database
      * 
      * @param id id of bathroom to be deleted
      */
      QUERY(deleteBathroom,
            "DELETE FROM Bathroom WHERE id=:id;",
            PARAM(oatpp::Int32, id))

      ////////////////////////////
      ///// Buildings
      /////////////////

      /**
      * @brief createBuilding Query, inserts a new building to the database
      * 
      * @param name the name of the building to be displayed on the map
      * @param latitude the x coordinate for the map display
      * @param longitude the y coordinate for the map display
      */
      QUERY(createBuilding,
            "INSERT INTO Building"
            "(name, latitude, longitude) VALUES "
            "(:building.name, :building.latitude, :building.longitude);",
            PARAM(oatpp::Object<BuildingDto>, building))


      /**
      * @brief getAllBuildings Query, gets all buildings in database with a starting at offset and up to limit
      * 
      * @param offset how many buildings to skip
      * @param limit max number of buildings to return
      */
      QUERY(getAllBuildings,
            "SELECT * FROM Building LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit))


      /**
      * @brief getBuildingByName Query, get a building from database by name
      * 
      * @param name name of building to be returned   
      */
      QUERY(getBuildingByName,
            "SELECT * FROM Building WHERE name=:name;",
            PARAM(oatpp::String, name))


      /**
      * @brief updateBuilding Query, updates an existing building with a new DTO
      * 
      * @param name the name of the building to be updated
      * 
      * @param name the new name to be set
      * @param latitude the new x coordinate to be set
      * @param longitude the new y coordinate to be set
      */
      QUERY(updateBuilding,
            "UPDATE Building "
            "SET "
            " name=:building.name, "
            " latitude=:bathroom.latitude, "
            " longitude=:bathroom.longitude, "
            "WHERE "
            " name=:building.name;",
            PARAM(oatpp::Object<BuildingDto>, building))


      /**
      * @brief deleteBuilding Query, deletes building from database
      * 
      * @param name name of building to be deleted
      */
      QUERY(deleteBuilding,
            "DELETE FROM Building WHERE name=:name;",
            PARAM(oatpp::String, name))
      
      ////////////////////////////
      ///// Ratings
      /////////////////

      /**
      * @brief createRating Query, inserts a new rating into the database, attached to a bathroom
      * 
      * @param bathroomId id of bathroom to be  connected to the rating
      * @param uploader the usernmae of the persn who uploaded the review
      * @param overallRating the user's overall rating on a scale of 0 - 5 stars
      * @param cleanlinessRating the user's rating of how clean the bathroom is on a scale of 0 - 5 stars
      * @param textReview the user's written review of the bathroom to provide more details
      */
      QUERY(createRating,
            "INSERT INTO Rating"
            "(bathroomId, uploader, overallRating, cleanlinessRating, textReview) VALUES "
            "(:rating.bathroomId, :rating.uploader, :rating.overallRating, :rating.cleanlinessRating, :rating.textReview);",
            PARAM(oatpp::Object<RatingDto>, rating))

      /**
      * @brief getAllRatings Query, gets all ratings from database with a specified offset and limit
      * 
      * @param offset how many ratings to skip
      * @param limit max number of ratings to return
      */
      QUERY(getAllRatings,
            "SELECT * FROM Rating LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit))

      /**
      * @brief getRatingById Query, gets a rating from database, given the rating ID
      * 
      * @param id id of the rating to be fetched
      */
      QUERY(getRatingById,
            "SELECT * FROM Rating WHERE id=:id;",
            PARAM(oatpp::Int32, id))


      /**
      * @brief getRatingByUser Query, finds all reviews posted by a given user
      * 
      * @param uploader the username of the person who uploaded
      * @param offset the number of reviews to be skipped
      * @param limit the max number of reviews to return
      */
      QUERY(getRatingByUser,
            "SELECT * FROM rating WHERE uploader=:uploader LIMIT :limit OFFSET :offset;",
            PARAM(oatpp::String, uploader),
            PARAM(oatpp::UInt32, offset),
            PARAM(oatpp::UInt32, limit)
            )

      /**
      * @brief getRatingByBathroom Query, gets all reviews attached to a given bathroom
      * 
      * @param bathroomId the id of the bathroom the fetch reviews for
      */
      QUERY(getRatingByBathroom,
            "SELECT * FROM Rating WHERE bathroomId=:bathroomId;",
            PARAM(oatpp::Int32, bathroomId))
      

      /**
      * @brief updateRating Query, updates an existing rating with a new DTO
      * 
      * @param id id of the rating to updated
      *
      * @param uploader the username of the person who uploaded the review
      * @param bathroomId the id of the bathroom connected to the rating
      * @param overallRating the overall rating of the bathroom on a scale of 0 - 5 stars
      * @param cleanlinessRating the rating of how clean the bathroom is on a scale of 0 - 5 stars
      * @param textReview a written text review for more details about a bathroom
      */
      QUERY(updateRating,
            "UPDATE rating "
            "SET "
            " uploader=:rating.uploader, "
            " overallRating=:rating.overallRating, "
            " cleanlinessRating=:rating.cleanlinessRating, "
            " textReview=:rating.textReview "
            "WHERE "
            " id=:rating.id;",
            PARAM(oatpp::Object<RatingDto>, rating))

      /**
       * @brief delete Rating Query, deletes a rating from the database
       * 
       * @param id id of the rating to be updated
      */
      QUERY(deleteRating,
            "DELETE FROM Rating WHERE id=:id;",
            PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif // CRUD_APPDB_HPP
