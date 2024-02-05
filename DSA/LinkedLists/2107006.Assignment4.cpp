#include "2107006_Assignment4.h"

int main(){

    doublylinkedlist<int>l1;

    l1.insertBegin(1);
    l1.insertEnd(2);
    l1.insertBegin(3);
    l1.insertBegin(4);
    l1.insertEnd(3);
    l1.insertAtPosition(2,4);
    l1.insertBegin(2);
    l1.insertAtPosition(4,7);
    l1.insertBegin(6);
    l1.display();

    l1.quickSort();
    l1.display();

    l1.deletebegin();
    l1.display();

    l1.deleteEnd();
    l1.display();

    l1.deleteatposition(3);
    l1.display();

    l1.deletebyvalue(2);
    l1.display();

    l1.insertBegin(5);
    l1.insertAtPosition(1,2);
    l1.insertEnd(7);
    l1.display(); 

    l1.mergeSort(l1.gethead());
    l1.display();  
}