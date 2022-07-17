
#include <iostream>
#include "ListOneWay.hpp"

int main()
{
    ListOneWay list;
    list.insertFront(2);
    list.insertFront(9);
    list.insertFront(4);
    list.insertFront(1);
    list.insertFront(7);
    list.print();
    list.insertBack(33);
    list.print();
    list.insertAfter(55, 2);
    list.print();
    list.remove(0);
    list.print();
    list.remove(3);
    list.print();
    


}
