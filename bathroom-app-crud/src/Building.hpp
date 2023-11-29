#ifndef Building_hpp
#define Building_hpp

#include <utility>
#include <vector> 
#include <string>

class Bathroom;

/**
 * @brief building object class
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
*/
class Building{
    public:
        std::string name;
        std::string longitude;
        std::string latitude;
        std::vector<Bathroom> bathrooms;


        /**
         * @brief Building object constructor
         * 
         * @param name name of building
         * @param location longitude and latitude coordinates of building
         * @param bathrooms vector of bathrooms located inside building
        */
        Building(std::string name, std::string longitude, std::string latitude, std::vector<Bathroom> bathrooms){
            this->name = name;
            this->longitude = longitude;
            this->latitude = latitude;
            this-> bathrooms = bathrooms;
        }

        /**
         * @brief getter for building name
         * 
         * @return building name
        */
        std::string getName() const {
            return name;
        }

        /**
         * @brief setter for building name
         * 
         * @param newName new name to be set
        */
        void setName(const std::string &newName) {
            this->name = newName;
        }

        /**
        * @brief getter for bathroom latitude
        *
        * @return string of latitude
        */
        std::string getLatitude() const { 
            return latitude;
        }

        /**
         * @brief setter for building latitude
         * 
         * @param latitude x coordinate
        */
        void setLatitude(std::string latitude) {
            this->latitude = latitude;
        }

        /**
        * @brief getter for building longitude
        *
        * @return string of longitude
        */
        std::string getLongitude() const { 
            return longitude;
        }

        /**
         * @brief setter for building longitude
         * 
         * @param longitude y coordinate
        */
        void setLongitude(std::string longitude) {
            this->longitude = longitude;
        }

        /**
         * @brief Adds bathroom to list of bathrooms attached to building
         * 
         * @param bathroom new bathroom to be added
        */
        void addBathroom(const Bathroom & bathroom){
            bathrooms.push_back(bathroom);
        }

        /**
         * @brief gets all of the bathrooms connected to a building object
         * 
         * @return returns the vector of bathroom objects
        */
        const std::vector<Bathroom> & getBathrooms() const {
            return this->bathrooms;
        }
    
};

#endif /*Building_hpp*/