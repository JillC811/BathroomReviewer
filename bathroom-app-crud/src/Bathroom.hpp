#ifndef Bathroom_hpp
#define Bathroom_hpp

#include <utility>
#include <vector>

class Building;
class Rating;
/**
 * @brief bathroom object class
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong
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

        /** 
         * @brief Bathroom object constructor
         * @param id: randomly assigned integer for bathroom
         * @param building: name of building bathroom is in
         * @param floor: floor number bathroom is on
         * @param longitude y coordinates of the bathroom
         * @param latitude x coordinates of bathroom
         * @param gender M for male, F for female, B for both
         * @param stallCount of stalls in bathroom
         * @param urinalCount # of urinals in bathroom
         * @param ratings: list of user ratings out of 5.
         */
        Bathroom(int id, Building* building, int floor, std::string latitude, std::string longitude , char gender, int stallCount, int urinalCount, std::vector<int> ratings)
        {
            this->id = id;
            this->building = building;
            this->floor = floor;
            this->location = location;
            this->longitude = longitude;
            this->latitude = latitude;
            this->gender = gender;
            this->stallCount = stallCount;
            this->urinalCount = urinalCount;
            this->ratings = ratings;
        }
        //////////////////
        //various getters and setters for bathroom attributes
        //////////////////

        /**
        * @brief getter for id
        *
        * @return id of bathroom
        */
        int getID() const { 
            return id; 
        }
        /**
         * @brief setter for id
         * 
         * @param id
        */
        void setID(int id) { 
            this->id = id; 
        }
        /**
        * @brief getter for building
        *
        * @return building object of bathroom
        */
        Building * getBuilding() const { 
            return building; 
        }
        /**
         * @brief setter for building
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
        /**
        * @brief getter for bathroom latitude
        *
        * @return string of latitude
        */
        std::string getLatitude() const { 
            return latitude;
        }

        /**
         * @brief setter for bathroom latitude
         * 
         * @param latitude x coordinate
        */
        void setLatitude(std::string latitude) {
            this->latitude = latitude;
        }

        /**
        * @brief getter for bathroom longitude
        *
        * @return string of longitude
        */
        std::string getLongitude() const { 
            return latitude;
        }

        /**
         * @brief setter for bathroom longitude
         * 
         * @param longitude y coordinate
        */
        void setLongitude(std::string longitude) {
            this->longitude = longitude;
        }

        /**
        * @brief getter for gender
        *
        * @return gender of bathroom
        */
        char getGender() const {
            return gender; 
        }
        /**
         * @brief setter for gender
         * 
         * @param char gender
        */
        void setGender(char gender) {
            this->gender = gender;
        }
        /**
        * @brief getter for stallcount
        *
        * @return # of stalls of bathroom
        */
        int getStallCount() const {
            return stallCount;
        }
        /**
         * @brief setter for stallcount
         * 
         * @param int # of stalls
        */
        void setStallCount(int stallCount) {
            this->stallCount = stallCount;
        }
        /**
        * @brief getter for urinal count
        *
        * @return # of urinals
        */
        int getUrinalCount() const {
            return urinalCount;
        }
        /**
         * @brief setter for urinalcount
         * 
         * @param int # of urinals in bathroom
        */
        void setUrinalCount(int urinalCount) {
            this->urinalCount = urinalCount;
        }
        /**
        * @brief getter for ratings
        *
        * @return int vector of ratings in bathroom
        */
        std::vector<int> getRatings() const {
            return ratings;
        }
        /**
         * @brief setter for ratings
         * 
         * @param vector of ratings to set
        */
        void setRating(std::vector<int> ratings) {
            this->ratings = ratings;
        }
};


#endif /*Bathroom_hpp*/