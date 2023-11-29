#ifndef Bathroom_hpp
#define Bathroom_hpp

#include <utility>
#include <vector>

class Building;
class Rating;
/**
 * bathroom object class
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

        /**Bathroom object constructor
         *
         * @param Int id: randomly assigned integer for bathroom
         * @param Building building: name of building bathroom is in
         * @param Int floor: floor number bathroom is on
         * @param pair<float,float> location: latitude and longitude coordinates of bathroom
         * @param Char gender M for male, F for female, B for both
         * @param Int # of stalls in bathroom
         * @param Int urinalCount: # of urinals in bathroom
         * @param vector<int> ratings: list of user ratings out of 5.
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
        /**
         * various getters and setters for bathroom attributes
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
            this->longitude = loaction.first;
            this->latitude = loaction.second;
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