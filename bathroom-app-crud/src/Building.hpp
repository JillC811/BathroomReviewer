#ifndef Building_hpp
#define Building_hpp

#include <utility>
#include <vector> 
#include <string>

class Bathroom;

class Building{
    public:
        std::string name;
        float longitude;
        float latitude;
        std::pair<float, float> location;
        std::vector<Bathroom> bathrooms;
/**
 * Building object constructor
 * @author colton
 * 
 * @param name: name of building
 * @param location float pair of latitude and longitude
 * @param bathrooms: vector of bathrooms located inside building
*/
        Building(std::string name, std::pair<float, float> location, std::vector<Bathroom> bathrooms){
            this->name = name;
            this->location = location;
            this->longitude = location.first;
            this->latitude = location.second;
            this-> bathrooms = bathrooms;
        }
        /*
        * getter for building name
        *
        * @return name of building
        */
        std::string getName() const {
            return name;
        }
        /*
        * setter for building name
        *
        * @param name of building
        */
        void setName(const std::string &newName) {
            this.name = newName;
        }
        /*
        * getter for location
        *
        * @return location of building
        */
        std::pair<float, float> getLocation() const {
            return location;
        }
        /*
        * setter for location
        *
        * @param float pair with latitude and longitude
        */
        void setLocation(const std::pair<float, float> &newLocation) {
            this.location = newLocation;
        }
        /*
        * addbathroom method
        *
        * @return adds bathroom to list of bathrooms
        */
        void addBathroom(const Bathroom & bathroom){
            bathrooms.push_back(bathroom);
        }
        /*
        * getter for bathrooms
        *
        * @return all bathrooms in vuilding
        */
        const std::vector<Bathroom> & getBathrooms() const {
            return this.bathrooms;
        }
};

#endif /*Building_hpp*/