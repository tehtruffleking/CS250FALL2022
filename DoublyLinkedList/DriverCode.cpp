#include <iostream>
#include "DoublyList.h"

int main()
{
    std::cout << "Hello World!\n";

    DoublyList myList;
    DoublyList anotherList;

    myList.insertBack(1);
    myList.insertInOrder(0);
    myList.insertBack(2);
    myList.insertBack(3);
    myList.insertBack(4);
    myList.insertBack(9);

    myList.printForward();
    std::cout << "\n";

    myList.insertInOrder(5);
    myList.insertInOrder(7);

    myList.insertBack(10);
    myList.insertBack(11);

    myList.printForward();
    std::cout << "\n";

    std::cout << myList.getNumOfElements() << "\n";

    std::cout << myList.findMiddleNode() << "\n";
    //myList.moveToList(anotherList);

    //std::cout << "Hang on to your butts.\n";

    ////anotherList.printForward();
    ////std::cout << "\n";

    ////myList.printForward();
    ////std::cout << "\n";

    ////std::cout << anotherList.getNumOfElements() << "\n";

    //myList.insertBack(6);
    //myList.insertBack(7);
    //myList.insertBack(8);
    //myList.insertBack(9);
    //myList.insertBack(4);


    //myList.swapLists(anotherList);

    //myList.printForward();
    //std::cout << "\n";
    //anotherList.printForward();
    //std::cout << "\n";

    return 0;
}
