#include "Queue.h"
#include "Element.h"
#include <limits.h>
#include <iostream>

Queue::Queue() {
	this->setLastElement(nullptr);
}

Queue::~Queue() {
	if (this->getLastElement() != nullptr) {
		recursiveClean(this->getLastElement());
		this->setLastElement(nullptr);

	}
}

void Queue::recursiveClean(Element* currentElement) {
	if (currentElement->GetPrevious() != nullptr) {
		recursiveClean(currentElement->GetPrevious());
		delete currentElement->GetPrevious();
	}
	//delete currentElement;
}


void Queue::Push(int value) {
	Element* currentElement = new Element;
	currentElement->Set_Previous(getLastElement());
	currentElement->SetValue(value);
	this->setLastElement(currentElement);
}

void Queue::Pop() {
	Element* head;
	Element* headNext;
	if (this->getLastElement() == nullptr) {
		std::cout << "Queue is empty" << std::endl;
	}
	else 
	{
		head = this->getLastElement()->GetPrevious(); //First element(Head) of queue 
		headNext = this->getLastElement(); //Second Element of queue
		if (head == nullptr) {
			std::cout << "Removed element: " << headNext->GetValue() << std::endl;
			delete headNext;
			this->setLastElement(nullptr);
		}
		else{
			while (head->GetPrevious() != nullptr) {
				headNext = head;
				head = headNext->GetPrevious();
			}
			std::cout << "Removed element: " << head->GetValue() << std::endl;
			delete head;
			headNext->Set_Previous(nullptr);
		}
	}	
}

/*
void Queue::recursiveCopy(Element* currentElementOfInQueue, Element* currentElementOfOutQueue) {
	if(currentElementOfInQueue->GetPrevious() != nullptr){
		Element* newElementOfOutQueue = new Element;
		currentElementOfOutQueue->Set_Previous(newElementOfOutQueue);
		currentElementOfOutQueue->SetValue(currentElementOfInQueue->GetValue());
		recursiveCopy(currentElementOfInQueue->GetPrevious(), newElementOfOutQueue);
	}
	
}
*/


Element* Queue::recursiveCopy(Element* currentElementOfInQueue, Element* headOfNewQueue) { 
	if (currentElementOfInQueue != nullptr) {
		Element* newElementOfOutQueue = new Element;
		newElementOfOutQueue->SetValue(currentElementOfInQueue->GetValue());
		newElementOfOutQueue->Set_Previous(recursiveCopy(currentElementOfInQueue->GetPrevious(),headOfNewQueue));
		return newElementOfOutQueue;
	}

	return headOfNewQueue;
}


void Queue::Copy(Queue& outQueue) {
	if (this->getLastElement() != nullptr) {
		Element* tailOfInQueue = this->getLastElement();
		outQueue.setLastElement(recursiveCopy(tailOfInQueue));
	}
}


void Queue::Merge(Queue& secondQueue) {
	if (this->getLastElement() == nullptr || secondQueue.getLastElement() == nullptr) {
		std::cout << "Can't merge empty queues" << std::endl;
	}
	else
	{
		this->setLastElement(recursiveCopy(secondQueue.getLastElement(), this->getLastElement()));

	}
	

}

void Queue::CalculateRange() {
	if (this->getLastElement() == nullptr || this->getLastElement()->GetPrevious() == nullptr) {
		std::cout << "Can't calculate range of empty queue or queue with 1 element" << std::endl;
	}
	else {
		Element* currentElement = this->getLastElement();
		int min = INT_MAX;
		int max = INT_MIN;
		int valueOfCurrentElement;
		while (currentElement != nullptr) {
			valueOfCurrentElement = currentElement->GetValue();
			if (valueOfCurrentElement > max) max = valueOfCurrentElement;
			if (valueOfCurrentElement < min) min = valueOfCurrentElement;
			currentElement = currentElement->GetPrevious();
		}
		std::cout << "Range of queue: " << max - min << std::endl;
	}
}








void Queue::recursiveShow(Element* currentElement) {
	if (currentElement != nullptr) {
		recursiveShow(currentElement->GetPrevious());
		std::cout << currentElement->GetValue() << " ";
	}
}

void Queue::ShowQueue() {

	if (this->getLastElement() == nullptr) {
		std::cout << "Queue is empty" << std::endl;
	}
	else
	{
		recursiveShow(this->getLastElement());
		std::cout << std::endl;
	}
}


Element* Queue::getLastElement() {
	return lastElement_;
}
void Queue::setLastElement(Element* newLastElement) {
	this->lastElement_ = newLastElement;
}
