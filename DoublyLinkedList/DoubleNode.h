#ifndef DOUBLENODE_H
#define DOUBLENODE_H

class DoubleNode
{
public:
	DoubleNode();
	DoubleNode(int theData, DoubleNode* prevLink, DoubleNode* nextLink);

	int getData() const;

	DoubleNode* getPrev() const;
	DoubleNode* getNext() const;

	void setData(int theData);
	void setPrev(DoubleNode* prevLink);
	void setNext(DoubleNode* nextLink);

	~DoubleNode();

private:
	int data;
	DoubleNode* prev;
	DoubleNode* next;
};

#endif
