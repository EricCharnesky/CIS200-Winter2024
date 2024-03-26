
#include <iostream>

#include "Stack.h"

int main()
{
    std::cout << "Hello World!\n";
    Stack<int> numbers;

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);

    while (!numbers.isEmpty()) {
        cout << numbers.pop() << endl;
    }
}
