#ifndef Bathroom_hpp
#define Bathroom_hpp

#include <utility>
#include <vector>

class Building;
class Rating;
/**
 * @brief bathroom object class
 * @author colton
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

        /** @brief Bathroom object constructor
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
        /**setter for building
         * 
         * @param building
        */
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
        /**setter for floor
         * 
         * @param int floor
        */
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

        /**setter for location
         * 
         * @param float pair location
        */
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
        /**setter for gender
         * 
         * @param char gender
        */
        void setGender(char gender) {
            this->gender = gender;
        }
        /*
        * getter for stallcount
        *
        * @return # of stalls of bathroom
        */
        int getStallCount() const {
            return stallCount;
        }
        /**setter for stallcount
         * 
         * @param int # of stalls
        */
        void setStallCount(int stallCount) {
            this->stallCount = stallCount;
        }
        /*
        * getter for urinal count
        *
        * @return # of urinals
        */
        int getUrinalCount() const {
            return urinalCount;
        }
        /**setter for urinalcount
         * 
         * @param int # of urinals in bathroom
        */
        void setUrinalCount(int urinalCount) {
            this->urinalCount = urinalCount;
        }
        /*
        * getter for ratings
        *
        * @return int vector of ratings in bathroom
        */
        std::vector<int> getRatings() const {
            return ratings;
        }
        /**setter for ratings
         * 
         * @param vector of ratings to set
        */
        void setRating(std::vector<int> ratings) {
            this->ratings = ratings;
        }
};


#endif /*Bathroom_hpp*/