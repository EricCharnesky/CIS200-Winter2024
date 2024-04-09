#pragma once

#include <string>

using namespace std;

class Assignment {
private:
	string name;
	double pointsPossible;
	double pointsEarned;
public:
	// umgpt - 
	// write c++ code for set and get methods and default and parameterized constructor for a class with attributes 	string name;
	// double pointsPossible;
	// double pointsEarned;


    Assignment()
        : name(""), pointsPossible(0.0), pointsEarned(0.0) {

    }

    Assignment(std::string initName, double initPointsPossible, double initPointsEarned)
        : name(initName), pointsPossible(initPointsPossible), pointsEarned(initPointsEarned) {
    
    }


    void setName(const std::string& newName) {
        name = newName;
    }

    void setPointsPossible(double newPointsPossible) {
        pointsPossible = newPointsPossible;
    }

    void setPointsEarned(double newPointsEarned) {
        pointsEarned = newPointsEarned;
    }

    std::string getName() const {
        return name;
    }

    double getPointsPossible() const {
        return pointsPossible;
    }

    double getPointsEarned() const {
        return pointsEarned;
    }
};