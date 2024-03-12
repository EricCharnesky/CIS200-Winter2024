
#include <iostream>
#include "LinkedList.h"
#include "CircularDoublyLinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list(2);
    list.add_item(3);
    list.add_item(4);

    while (list.size() != 0) {
        cout << list.pop() << endl;
    }

    
    
}
