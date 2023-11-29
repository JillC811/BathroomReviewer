#ifndef Rating_hpp
#define Rating_hpp

#include <utility>

/**
 * @brief  Rating object class, contains getters and setters for rating object
 * 
 * @authors Justin Tsang, Elizabeth Shiu, Joey Gendy, Colton Undseth, Jill Chong 
*/

class Bathroom;

class Rating{
    private:
        int id;
    public:
        int overallRating;
        int cleanlinessRating;
        std::string username;
        std::string textReview;
/**
 * @brief rating object constructor
 * 
 * @param id review id 
 * @param uploader username of rating author
 * @param overallRating Overall rating of bathroom from user
 * @param cleanlinessRating Rating of how clean bathroom from user
 * @param textReview Review of bathroom written by user, limited to number of characters
*/

    Rating(int id, std::string username, int overallRating, int cleanlinessRating, std::string textReview){
        this->id = id;
        this->username = username;
        this->overallRating = overallRating;
        this->cleanlinessRating = cleanlinessRating;
        this->textReview = textReview;
    }

    /**
     * @brief getter for rating ID
     * 
     * @return returns the rating id
    */
    int getID() const{
        return this->id;
    }

    /**
     * @brief setter for rating ID
     * 
     * @param id the rating id
    */
    void setID(int id){
        this->id = id;
    }

    /**
     * @brief getter for rating ID
     * 
     * @return returns the rating from 0-5
    */
    int getOverallRating() const{
        return this->overallRating;
    }

    /**
     * @brief setter for overall rating
     * 
     * @param overallRating the rating from 0-5
    */
    void setOverallRating(int overallRating){
        this->overallRating = overallRating
    }

    /**
     * @brief getter for cleanliness rating
     * 
     * @return returns the cleanliness rating form 0-5
    */
    int getCleanlinessRating() const{
        return this->cleanlinessRating;
    }

    /**
     * @brief setter for cleanliness rating
     * 
     * @param cleanlinessRating rating from 0-5
    */
    void setCleanlinessRating(int cleanlinessRating){
        this->cleanlinessRating = cleanlinessRating;
    }

    /**
     * @brief getter for Text Review
     * 
     * @return returns the user submitted text review
    */
    std::string getTextReview() const{
        return this->textReview;
    }

    /**
     * @brief setter for text review
     * 
     * @param textReview the string of text set by the user
    */
    void setTextReview(std::string textReview) {
        this->textReview = textReview;
    }
}