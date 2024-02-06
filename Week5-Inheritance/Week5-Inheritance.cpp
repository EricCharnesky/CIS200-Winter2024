#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"

#include <iostream>

using namespace std;

int main()
{
    std::cout << "What day is it?" << endl;

    cout << "Enter a length" << endl;
    double length;
    cin >> length;

    cout << "Enter a width" << endl;
    double width;
    cin >> width;
    
    Rectangle* rectangle = new Rectangle(length, width);

    cout << "The perimeter of your rectangle is: " << (*rectangle).getPerimeter() << endl;
    rectangle->setSideLength(5, 2);

    vector<Polygon*> shapes;

    shapes.push_back(rectangle);

    // if we use pointers, we get the polymorphic behavior and the right function runs
    for (Polygon* shape : shapes) {
        cout << "Permieter of the shape is " << shape->getPerimeter() << endl;
        cout << "Area of the shape is " << shape->getArea() << endl;
    }

    Triangle* triangle = new Triangle(3, 4, 5);
    cout << "Area of your triangle " << triangle->getArea() << endl;

    shapes.push_back(triangle);
    // can't create once it has a pure virtual function
    // Polygon newPolygon = Polygon(6);

}

