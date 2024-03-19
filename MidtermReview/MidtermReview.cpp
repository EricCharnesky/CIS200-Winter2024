using namespace std;

#include <iostream>
#include <vector>

class Midterm {
private:
    string name;
    int score;
public:
    Midterm(string name, int score) {
        this->name = name;
        this->score = score;
    }

    string getName() {
        return name;
    }

    virtual int getScore() {
        return score;
    }
};

class EasyMidterm : public Midterm {
public:
    EasyMidterm(string name, int score) : Midterm(name, score) {

    }

    int getScore() override {
        return 100;
    }
};

int _sumOfEvenIndexesMinusOdds(vector<int>& numbers, int currentIndex, int currentSum) {
    if (currentIndex >= numbers.size()) {
        return currentSum;
    }
    if (currentIndex % 2 == 0) {
        currentSum += numbers.at(currentIndex);
    }
    else {
        currentSum -= numbers.at(currentIndex);
    }
    return _sumOfEvenIndexesMinusOdds(numbers, currentIndex + 1, currentSum);
}

int sumOfEvenIndexesMinusOdds(vector<int> numbers) {
    return _sumOfEvenIndexesMinusOdds(numbers, 0, 0);
}

bool doRowSumsMatchColumnSums(vector<vector<int>> grid) {
    int currentIndex = 0;

    while (currentIndex < grid.size()) {
        int rowSum = 0;
        int columnSum = 0;

        for (int columnIndex = 0; columnIndex < grid.size(); columnIndex++) {
            rowSum += grid.at(currentIndex).at(columnIndex);
        }

        for (int rowIndex = 0; rowIndex < grid.size(); rowIndex++) {
            columnSum += grid.at(rowIndex).at(currentIndex);
        }

        if (rowSum != columnSum) {
            return false;
        }
        currentIndex++;
    }
    return true;
}

int main()
{
    vector<int> numbers = { 1, 2, 3, 4, 5};
    cout << sumOfEvenIndexesMinusOdds(numbers) << endl;

    vector<vector<int>> grid = {
        { 3, 2, 1},
        { 1, 7, 3},
        { 2, 2, 5}
    };

    cout << doRowSumsMatchColumnSums(grid) << endl;

    Midterm hard("eric", 75);
    EasyMidterm easy("Eric", 75);

    cout << "Hard midterm score: " << hard.getScore() << endl;
    cout << "Easy midterm score: " << easy.getScore() << endl;

}
