#ifndef Bathroom_hpp
#define Bathroom_hpp

#include <utility>

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
        Rating * rating;

        Bathroom(int id, Building* building, int floor, std::pair<float, float> location, char gender, int stallCount, int urinalCount, Rating* rating)
        {
            this->id = id;
            this->building = building;
            this->floor = floor;
            this->location = location;
            this->gender = gender;
            this->stallCount = stallCount;
            this->urinalCount = urinalCount;
            this->rating = rating;
        }
        int getID() const { return id; }
        void setID(int id) { this->id = id; }

        Building * getBuilding() const { return building; }
        void setBuilding(Building * building) { this->building = building; }

        int getFloor() const { return floor; }
        void setFloor(int floor) { this->floor = floor; }

        std::pair<float, float> getLocation() const { return location; }
        void setLocation(std::pair<float,float> loaction) { this->location = loaction; }

        char getGender() const { return gender; }
        void setGender(char gender) { this->gender = gender; }

        int getStallCount() const { return stallCount; }
        void setStallCount() { this->stallCount = stallCount; }

        int getUrinalCount() const { return urinalCount; }
        void setUrinalCount(int urinalCount) { this->urinalCount = urinalCount; }

        Rating * getRating() const { return rating; }
        void setRating(Rating * rating) { this->rating = rating; }
};


#endif /*Bathroom_hpp*/