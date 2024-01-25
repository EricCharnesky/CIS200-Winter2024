using namespace std;

#include <iostream>
#include "Gradebook.h"

void quadraticSolver(int a, int b, int c, double& xIntercept1, double& xIntercept2) {
	if (a == 0) {
		throw logic_error("That's not a quadratic function");
	}
	
	double determinant = b * b - 4 * a * c;

	if (determinant < 0) {
		throw logic_error("No x intercepts exist");
	}

	xIntercept1 = (-b + sqrt(determinant)) / (2 * a);
	xIntercept2 = (-b - sqrt(determinant)) / (2 * a);

}

int main()
{
	Student eric = Student("Eric", 5, 100);
	Student eric2 = Student(eric);

	eric.setScore(0, 42);
	cout << "After setting Eric score to 42" << endl;
	cout << "Eric's score 0: " << eric.getScore(0) << endl;
	cout << "Eric 2's score 0: " << eric2.getScore(0) << endl;

	eric2 = Student(eric);

	Student eric3 = eric2;

	cout << "After copy constructor" << endl;
	cout << "Eric's score 0: " << eric.getScore(0) << endl;
	cout << "Eric 2's score 0: " << eric2.getScore(0) << endl;

	eric.setScore(0, 77);

	cout << "After setting Eric score to 77" << endl;
	cout << "Eric's score 0: " << eric.getScore(0) << endl;
	cout << "Eric 2's score 0: " << eric2.getScore(0) << endl;

	eric2 = eric;

	cout << "After assignment operator" << endl;
	cout << "Eric's score 0: " << eric.getScore(0) << endl;
	cout << "Eric 2's score 0: " << eric2.getScore(0) << endl;

	eric.setScore(0, 100);

	cout << "After setting Eric score to 100" << endl;
	cout << "Eric's score 0: " << eric.getScore(0) << endl;
	cout << "Eric 2's score 0: " << eric2.getScore(0) << endl;


	Gradebook cis200GradeBook("CIS 200", 35);

	Student bob = cis200GradeBook.getStudent(0);
	bob.setName("Bob");
	bob.setId(123);
	
	Gradebook cis200bGradeBook("CIS 200b", 50);
	cis200bGradeBook = cis200GradeBook;

	Gradebook anotherGradeBook(cis200bGradeBook);


	for (int classIndex = 0; classIndex < 1000; classIndex++) {
		Gradebook* gradebook = new Gradebook("some class", 50);
		delete gradebook;
	}
	



	int number = 42;
	int* anotherNumber;

	// assigns the memory address of number to anotherNumber pointer
	anotherNumber = &number;

	// gets the value referenced by the pointer
	cout << (*anotherNumber) << endl;

	number = 100;

	cout << (*anotherNumber) << endl;

	(*anotherNumber) = 7;

	cout << number << endl;

	// I'm lazy
	int a, b, c;
	double xIntercept1, xIntercept2;

	cout << "Please enter your a value: " << endl;
	cin >> a;

	cout << "Please enter your b value: " << endl;
	cin >> b;

	cout << "Please enter your c value: " << endl;
	cin >> c;

	try {
		quadraticSolver(a, b, c, xIntercept1, xIntercept2);
		cout << "Your intercepts are: " << xIntercept1 << " and " << xIntercept2 << endl;
	}
	catch (logic_error exception) {
		cout << exception.what() << endl;
	}
	
}