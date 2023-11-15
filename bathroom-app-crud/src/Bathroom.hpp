#ifndef Bathroom_hpp
#define Bathroom_hpp

#include <utility>
#include <vector>

class Building;
class Rating;

class Bathroom{
    //should these private variables be protected instead?
    private:
        int id;
    public:
        Building * building;
        int floor;
        std::pair<float, float> location;
        char gender;
        int stallCount;
        int urinalCount;
        std::vector<int> ratings;
        /**Bathroom object constructor
         *
         * id: randomly assigned integer for bathroom
         * building: name of building bathroom is in
         * floor: floor number bathroom is on
         * location: latitude and longitude coordinates of bathroom
         * gender: Char, M for male, F for female, B for both
         * stallCount: # of stalls in bathroom
         * urinalCount: # of urinals in bathroom
         * ratings: rating out of 5, averaged between users ratings
         * 
         * 
         **/
        Bathroom(int id, Building* building, int floor, std::pair<float, float> location, char gender, int stallCount, int urinalCount, std::vector<int> ratings)
        {
            this->id = id;
            this->building = building;
            this->floor = floor;
            this->location = location;
            this->gender = gender;
            this->stallCount = stallCount;
            this->urinalCount = urinalCount;
            this->ratings = ratings;
        }
        /**
         * various getters and setters for bathroom attributes
        */
        int getID() const { 
            return id; 
        }
        void setID(int id) { 
            this->id = id; 
        }

        Building * getBuilding() const { 
            return building; 
        }
        void setBuilding(Building * building) { 
            this->building = building; 
        }

        int getFloor() const { 
            return floor;
        }
        void setFloor(int floor) {
            this->floor = floor; 
        }

        std::pair<float, float> getLocation() const { 
            return location;
        }
        void setLocation(std::pair<float,float> loaction) {
            this->location = loaction;
        }

        char getGender() const {
            return gender; 
        }
        void setGender(char gender) {
            this->gender = gender;
        }

        int getStallCount() const {
            return stallCount;
        }
        void setStallCount(int stallCount) {
            this->stallCount = stallCount;
        }

        int getUrinalCount() const {
            return urinalCount;
        }
        void setUrinalCount(int urinalCount) {
            this->urinalCount = urinalCount;
        }

        std::vector<int> getRatings() const {
            return ratings;
        }
        void setRating(std::vector<int> ratings) {
            this->ratings = ratings;
        }
};


#endif /*Bathroom_hpp*/