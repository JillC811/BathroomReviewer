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
 * 
 * name: name of building
 * location: longitude and latitude coordinates of building
 * bathrooms: vector of bathrooms located inside building
*/
        Building(std::string name, std::pair<float, float> location, std::vector<Bathroom> bathrooms){
            this->name = name;
            this->location = location;
            this->longitude = location.first;
            this->latitude = location.second;
            this-> bathrooms = bathrooms;
        }

        std::string getName() const {
            return name;
        }

        void setName(const std::string &newName) {
            name = newName;
        }

        std::pair<float, float> getLocation() const {
            return location;
        }

        void setLocation(const std::pair<float, float> &newLocation) {
            location = newLocation;
        }

        void addBathroom(const Bathroom & bathroom){
            bathrooms.push_back(bathroom);
        }

        const std::vector<Bathroom> & getBathrooms() const {
            return bathrooms;
        }
};

#endif /*Building_hpp*/