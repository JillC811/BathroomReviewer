#ifndef Bathroom_hpp
#define Bathroom_hpp

#include <utility>
#include <vector>

class Building;
class Rating;
/**
 * @brief bathroom object class
*/
class Bathroom{
    private:
        int id;
    public:
        Building * building;
        int floor;
        float longitude;
        float latitude;
        std::pair<float, float> location;
        char gender;
        int stallCount;
        int urinalCount;
        std::vector<int> ratings;

        /**@brief Bathroom object constructor
         *
         * @param id: randomly assigned integer for bathroom
         * @param building: name of building bathroom is in
         * @param floor: floor number bathroom is on
         * @param <float,float> location: latitude and longitude coordinates of bathroom
         * @param gender M for male, F for female, B for both
         * @param # of stalls in bathroom
         * @param urinalCount: # of urinals in bathroom
         * @param ratings: list of user ratings out of 5.
         * 
         * 
         */
        Bathroom(int id, Building* building, int floor, std::pair<float, float> location, char gender, int stallCount, int urinalCount, std::vector<int> ratings)
        {
            this->id = id;
            this->building = building;
            this->floor = floor;
            this->location = location;
            this->longitude = location.first;
            this->latitude = location.second;
            this->gender = gender;
            this->stallCount = stallCount;
            this->urinalCount = urinalCount;
            this->ratings = ratings;
        }
        //////////////////
        //various getters and setters for bathroom attributes
        //////////////////

        /*
        * getter for id
        *
        * @return id of bathroom
        */
        int getID() const { 
            return id; 
        }
        /**setter for id
         * 
         * @param id
        */
        void setID(int id) { 
            this->id = id; 
        }
        /*
        * getter for building
        *
        * @return building object of bathroom
        */
        Building * getBuilding() const { 
            return building; 
        }
        void setBuilding(Building * building) { 
            this->building = building; 
        }
        /*
        * getter for bathroom floor
        *
        * @return floor
        */
        int getFloor() const { 
            return floor;
        }
        void setFloor(int floor) {
            this->floor = floor; 
        }
        /*
        * getter for bathroom location
        *
        * @return float pair of longitutde and latitude
        */
        std::pair<float, float> getLocation() const { 
            return location;
        }
        void setLocation(std::pair<float,float> location) {
            this->longitude = location.first;
            this->latitude = location.second;
        }
        /*
        * getter for gender
        *
        * @return gender of bathroom
        */
        char getGender() const {
            return gender; 
        }
        void setGender(char gender) {
            this->gender = gender;
        }
        /*
        * getter for id
        *
        * @return id of bathroom
        */
        int getStallCount() const {
            return stallCount;
        }
        void setStallCount(int stallCount) {
            this->stallCount = stallCount;
        }
        /*
        * getter for id
        *
        * @return id of bathroom
        */
        int getUrinalCount() const {
            return urinalCount;
        }
        void setUrinalCount(int urinalCount) {
            this->urinalCount = urinalCount;
        }
        /*
        * getter for id
        *
        * @return id of bathroom
        */
        std::vector<int> getRatings() const {
            return ratings;
        }
        void setRating(std::vector<int> ratings) {
            this->ratings = ratings;
        }
};


#endif /*Bathroom_hpp*/