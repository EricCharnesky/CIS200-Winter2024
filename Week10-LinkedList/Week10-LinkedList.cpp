
#include <iostream>
#include "LinkedList.h"
#include "CircularDoublyLinkedList.h"
#include "PositionalLinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list(2);
    list.add_item(3);
    list.add_item(4);

    while (list.size() != 0) {
        cout << list.pop() << endl;
    }

    CircularDoublyLinkedList<int> circularLinkedList;

    circularLinkedList.add_first(2);
    circularLinkedList.add_last(3);
    circularLinkedList.add_last(4);

    circularLinkedList.print_forward();
    circularLinkedList.print_backwards();

    while (circularLinkedList.size() != 0) {
        cout << circularLinkedList.pop_last() << endl;
    }

    
    PositionalLinkedList<string> names;

    names.add_first("Eric");
    names.add_last("Jeb");
    names.add_last("Vivi");

    auto currentPosition = names.first();
    auto joysPosition = names.add_after(currentPosition, "Joy");
    while (currentPosition != nullptr) {
        cout << currentPosition->data() << endl;
        currentPosition = names.after(currentPosition);
    }
    
}
