#ifndef Rating_hpp
#define Rating_hpp

#include <utility>
class Bathroom;
/**
 * @brief Rating object class, contains getters and setters for rating object
*/

class Rating{
    private:
        int id;
    public:
        int overallRating;
        int cleanlinessRating;
        String username;
        String textReview;
/**
 * rating object constructor
 * @author jill
 * 
 * @param id: review id 
 * @param uploader: username of rating author
 * @param overallRating: Overall rating of bathroom from user
 * @param cleanlinessRating: Rating of how clean bathroom from user
 * @param textReview: Review of bathroom written by user, limited to number of characters
*/

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