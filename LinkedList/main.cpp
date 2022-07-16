

#include <iostream>
#include"DoublyLinkedList.hpp"
int main()
{
    DoublyLinkedList list;
    list.insertFront(5);
    list.insertFront(7); 
    list.insertFront(9); 
    list.insertFront(4);
    list.insertFront(3);
    
    std::cout << "wprowadzam na poczatku" << std::endl;
    list.print();
    list.insertBack(88);
    std::cout << "wprowadzam na koncu" << std::endl;
    list.print();
    list.insertAfter(33, 2);
    std::cout << "wprowadzam po poz 2" << std::endl;
    list.print();

    //list.clear();
    //list.print();
    
    /*std::cout << "rozmiar listy= " << list.size() << std::endl;
    std::cout << "usuwam pierwszy" << std::endl;
    list.remove(0);
    list.print();
    std::cout << "usuwam ostatni" << std::endl;
    list.remove(4);
    list.print();
    std::cout << "usuwam œrodkowy" << std::endl;
    list.remove(2);
    list.print();
    std::cout << "usuwam dwa pierwsze" << std::endl;
    list.remove(0);
    list.remove(0);
    list.print();
    std::cout << "usuwam jedyny" << std::endl;
    list.remove(0);*/
   //list.print();

    DoublyLinkedList list1;
    list1.insertFront(2);
    list1.insertFront(2);
    list1.insertFront(2);
    list1.insertFront(2);
    list1.print();
    list.merge(list1, 2);
    list.print();





}
