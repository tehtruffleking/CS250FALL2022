#ifndef DOUBLYLIST_H
#define DOUBLELIST_H

#include <iostream>
#include "DoubleNode.h"

class DoublyList
{
public:
	DoublyList();
	
	void insertFront(int newData);
	void insertBack(int newData);

	void printForward() const;
	void printReverse() const;

	int getNumOfElements();
	int front();
	int back();
	int currentNode();

	void search(int targetData);
	bool inList(int searchParameter) const;
	void insertInOrder(int newData);

	int findMiddleNode();

	void moveToList(DoublyList &newOwner);
	void swapLists(DoublyList &otherList);

	void deleteNode(int nodeData);
	void clearList();

	~DoublyList();

private:
	DoubleNode* first;
	DoubleNode* last;
	DoubleNode* current;
	int count;
};
#endif // !DOUBLYLIST_H
