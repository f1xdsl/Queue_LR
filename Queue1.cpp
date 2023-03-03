#include <limits.h>
#include <iostream>
#include "Queue1.h"
#include "Element.h"

//methods fo public Queue
void QueuePublic::CalculateRange() {
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


//methods for protected queue
void QueueProtected::CalculateRange() {
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

void QueueProtected::PushProtected(int value) {
	this->Push(value);
}

void QueueProtected::PopProtected() {
	this->Pop();
}

void QueueProtected::CopyProtected(QueueProtected& outQueue) {
	this->Copy(outQueue);
}

void QueueProtected::MergeProtected(QueueProtected& secondQueue) {
	this->Merge(secondQueue);
}

void QueueProtected::ShowQueueProtected() {
	this->ShowQueue();
}


//methods for private queue
void QueuePrivate::CalculateRange() {
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

void QueuePrivate::PushPrivate(int value) {
	this->Push(value);
}

void QueuePrivate::PopPrivate() {
	this->Pop();
}

void QueuePrivate::CopyPrivate(QueuePrivate& outQueue) {
	this->Copy(outQueue);
}

void QueuePrivate::MergePrivate(QueuePrivate& secondQueue) {
	this->Merge(secondQueue);
}

void QueuePrivate::ShowQueuePrivate() {
	this->ShowQueue();
}
