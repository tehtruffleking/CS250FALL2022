#include "DoublyList.h"

DoublyList::DoublyList()
{
	first = nullptr;
	last = nullptr;
	current = nullptr;
	count = 0;
}

void DoublyList::insertFront(int newData)
{
	if (first == nullptr)
	{
		first = new DoubleNode(newData, nullptr, nullptr);
		last = first;
		current = first;
	}
	else
	{
		first = new DoubleNode(newData, nullptr, first);
		first->getNext()->setPrev(first);
	}
	++count;
}

void DoublyList::insertBack(int newData)
{
	if (first == nullptr)
	{
		first = new DoubleNode(newData, nullptr, nullptr);
		last = first;
		current = first;
	}
	else
	{
		last->setNext(new DoubleNode(newData, last, nullptr));
		last = last->getNext();
	}
	++count;
}

void DoublyList::printForward() const
{
	DoubleNode* current = first;

	if (first == nullptr)
	{
		std::cerr << "The list is empty.\n";
	}

	while (current != nullptr)
	{
		std::cout << current->getData() << " ";
		current = current->getNext();
	}
}

void DoublyList::printReverse() const
{
	DoubleNode* current = last;

	if (first == nullptr)
	{
		std::cerr << "The list is empty.\n";
	}

	while (current != nullptr)
	{
		std::cout << current->getData() << " ";
		current = current->getPrev();
	}
}

int DoublyList::getNumOfElements()
{
	return count;
}
int DoublyList::front()
{
	if (!count)
	{
		std::cerr << "The list is empty.\n";
	}
	else
	{
		return (first->getData());
	}
}

int DoublyList::back()
{
	if (!count)
	{
		std::cerr << "The list is empty.\n";
	}
	else
	{
		return (last->getData());
	}
}

int DoublyList::currentNode()
{
	if (!count)
	{
		std::cerr << "The list is empty.\n";
	}
	else
	{
		return (current->getData());
	}
}

void DoublyList::search(int targetData)
{
	int tempCount = 0;

	while (current->getData() != targetData)
	{
		current = current->getNext();
		++tempCount;
		
		if (current == nullptr)
		{
			current = first;
		}

		if (tempCount > count)
		{
			std::cerr << "Element not present in list.\n";
			break;
		}
	}
}

bool DoublyList::inList(int searchParameter) const
{
	DoubleNode* current = first;

	while (current != nullptr)
	{
		if (current->getData() == searchParameter)
		{
			return true;
		}
		current = current->getNext();
	}
}

void DoublyList::insertInOrder(int newData)
{
	DoubleNode* current = first;

	if (count == 0)
	{
		first = new DoubleNode(newData, nullptr, nullptr);
		last = first;
	}
	else if (count == 1)
	{
		if (first->getData() < newData)
		{
			last->setNext(new DoubleNode(newData, last, nullptr));
			last = last->getNext();
		}
		else
		{
			first = (new DoubleNode(newData, nullptr, first));
			first->getNext()->setPrev(first);
		}
	}
	else
	{
		while (current->getData() < newData)
		{
			current = current->getNext();
		}
		current->getPrev()->setNext(new DoubleNode(newData, nullptr, nullptr));
		current->getPrev()->getNext()->setNext(current);
		current = current->getPrev();
		current->getNext()->setPrev(current);
		current = current->getNext();
		current->getNext()->setPrev(current);
	}
	++count;
}

int DoublyList::findMiddleNode()
{
	DoubleNode* current = first;
	int nodeLocation = (count / 2);

	for (int i = 0; i < nodeLocation; i++)
	{
		current = current->getNext();
	}

	return current->getData();
}

void DoublyList::moveToList(DoublyList &newOwner)
{
	newOwner.first = this->first;
	newOwner.last = this->last;
	newOwner.current = this->current;
	newOwner.count = this->count;

	this->first = nullptr;
	this->last = nullptr;
	this->current = nullptr;
	this->count = 0;
}

void DoublyList::swapLists(DoublyList &otherList)
{
	DoubleNode* temp = nullptr;
	int tempCount = 0;

	temp = otherList.first;
	otherList.first = this->first;
	this->first = temp;

	temp = otherList.last;
	otherList.last = this->last;
	this->last = temp;

	tempCount = otherList.count;
	otherList.count = this->count;
	this->count = tempCount;
}

void DoublyList::deleteNode(int nodeData)
{
	if (count == 0)
	{
		std::cerr << "The list is empty.\n";
	}
	else if (count == 1)
	{
		delete current;
		first = nullptr;
		last = nullptr;
		current = nullptr;
		--count;
	}
	else
	{
		search(nodeData);

		if (current == first)
		{
			first = current->getNext();
			current->getNext()->setPrev(nullptr);

			delete current;
			current = first;
		}
		else if (current == last)
		{
			current->getPrev()->setNext(nullptr);
			last = current->getPrev();

			delete current;
			current = first;
		}
		else
		{
			current->getPrev()->setNext(current->getNext());
			current->getNext()->setPrev(current->getPrev());
			delete current;
			current = first;
		}
		--count;
	}
}

void DoublyList::clearList()
{
	DoubleNode* temp = first;

	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}
	current = nullptr;
	last = nullptr;
	first = nullptr;
	count = 0;
}

DoublyList::~DoublyList()
{
	clearList();
	std::cout << "List cleared.";
}
