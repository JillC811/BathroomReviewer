#ifndef Rating_hpp
#define Rating_hpp

#include <utility>
class Bathroom;

class Rating{
    private:
        int id;
    public:
        int overallRating;
        int cleanlinessRating;
        String username;
        String textReview;
    Rating(int id, String username, int overallRating, int cleanlinessRating, String textReview){
        this->id = id;
        this->username = username;
        this->overallRating = overallRating;
        this->cleanlinessRating = cleanlinessRating;
        this->textReview = textReview;
    }
    int getID() const{
        return this->id;
    }
    void setID(int id){
        this->id = id;
    }

    int getOverallRating() const{
        return this->overallRating;
    }
    void setOverallRating(int overallRating){
        this->overallRating = overallRating
    }

    int getCleanlinessRating() const{
        return this->cleanlinessRating;
    }
    void setCleanlinessRating(int cleanlinessRating){
        this->cleanlinessRating = cleanlinessRating;
    }
    String getTextReview() const{
        return this->textReview;
    }
    void setTextReview(String textReview) {
        this->textReview = textReview;
    }
}