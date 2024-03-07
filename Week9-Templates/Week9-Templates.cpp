
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
    int number;
    string name;
};

class GuestStudent : public Student {
    string homeSchool;
};

template<typename T>
bool isLarger(T first, T second) {
    return first > second;
}

template<typename T>
class Tripple {
private:
    T first;
    T second;
    T third;
public:

    T getSmallest() {
        T smallest = first;
        if (second < smallest) {
            smallest = second;
        }
        if (third < smallest) {
            smallest = third;
        }

        return smallest;
    }
};

template<typename First, typename Second>
class Pair {

public:
    First first;
    Second second;
};

template<typename T>
class GroceryList {
private:
    vector<T> list;
    string store;
public:
    GroceryList(string store) {
        this->store = store;
        list = vector<T>();
    }

    void addItem(T item) {
        list.push_back(item);
    }

    string getStore() {
        return store;
    }

    void printList() {
        for (T item : list) {
            clout << item << endl;
        }
    }

};

int main()
{

    Pair<int, string> ourPair;

    std::cout << "Hello World!\n";

    Student firstStudent;
    GuestStudent guestStudent;

    vector<Student> numbers;
    Student first = numbers.at(0);
    cout << isLarger<int>(4, 6) << endl;
    cout << isLarger<Student>(firstStudent, guestStudent);

    Tripple<Student> students;
    students.getSmallest();

    Tripple<vector<Student>> moreStudents;
}
