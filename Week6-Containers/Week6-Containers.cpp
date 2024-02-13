
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> scores;

    int score = 0;

    while (score != -1) {
        cout << "Enter a score or -1 to stop: " << endl;
        cin >> score;
        if (score != -1) {
            scores.push_back(score);
        }
        
    }

    int highestScore = scores.at(0);

    for (int score : scores) {
        if (score > highestScore) {
            highestScore = score;
        }
    }

    int difference = 100 - highestScore;

    // if we don't use the &, the scores in the vector won't change
    for (int& score : scores) {
        score += difference;
    }
    
    pair<string, double> ericsScore;

    ericsScore.first = "Eric";
    ericsScore.second = 99.9;

    vector<pair<string, double>> grades;

    pair<string, double> jebsScore;
    jebsScore.first = "Jeb";
    jebsScore.second = 92.3;
    grades.push_back(jebsScore);

    map<int, pair<string, string>> studentList;

    pair<string, string> eric;
    eric.first = "Eric Charnesky";
    eric.second = "D.Eng.";
    studentList.emplace(123, eric);

    cout << "Eric's name is" << studentList.at(123).first 
        << " and major is " << studentList.at(123).second;
    
    pair<string, string> eric2;
    eric2.first = "Eric 2";
    eric2.second = "AI";
    // at to access or update

    if (studentList.count(122)) {
        studentList.at(122) = eric2;
    }
    else {
        studentList.emplace(122, eric2);
    }

    for (pair<int, pair<string, string>> student : studentList) {
        cout << student.first << " ";
        cout << student.second.first << " "  << student.second.second << endl;
    }
   

    // no order guaranteed with sets
    set<string> names;

    names.insert("Joy");
    names.insert("Jeb");
    names.insert("Jenavieve");
    names.insert("Journey");
    names.insert("Jubilee");
    names.insert("Jackson");
    names.insert("Jasper");

    names.insert("Joy"); // ignores duplicates

    for (string name : names) {
        cout << name << endl;
    }

    queue<int> scoresQueue;

    for (int score = 70; score < 100; score++) {
        scoresQueue.push(score);
    }

    cout << "Front of the queue " << scoresQueue.front() << endl;
    
    while (scoresQueue.size() != 0) {
        cout << scoresQueue.front() << endl;
        scoresQueue.pop();
    }

    deque<pair<string, vector<string>>> cars;

    vector<string> order;
    order.push_back("cheeseburger");
    order.push_back("coke zero");
    // make_pair is our shortcut for making pairs
    cars.push_back(make_pair("bolt", order));


    auto locationOf100 = find(scores.begin(), scores.end(), 100);

    if (locationOf100 == scores.end()) {
        cout << "100 was not found in scores" << endl;
    }
    else {
        cout << "100 is present in the scores vector" << endl;
    }
}
