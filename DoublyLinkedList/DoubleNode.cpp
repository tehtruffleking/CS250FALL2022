#include "DoubleNode.h"

DoubleNode::DoubleNode()
{
	data = 0;
	prev = nullptr;
	next = nullptr;
}

DoubleNode::DoubleNode(int theData, DoubleNode* prevLink, DoubleNode* nextLink)
{
	data = theData;
	prev = prevLink;
	next = nextLink;
}

int DoubleNode::getData() const
{
	return data;
}

DoubleNode* DoubleNode::getPrev() const
{
	return prev;
}

DoubleNode* DoubleNode::getNext() const
{
	return next;
}

void DoubleNode::setData(int theData)
{
	data = theData;
}

void DoubleNode::setPrev(DoubleNode* prevLink)
{
	prev = prevLink;
}

void DoubleNode::setNext(DoubleNode* nextLink)
{
	next = nextLink;
}

DoubleNode::~DoubleNode()
{

}
