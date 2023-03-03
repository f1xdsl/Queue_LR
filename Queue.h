#include "Element.h"
#ifndef QUEUE_H
#define QUEUE_H


class Queue {
public:
	Queue();
	~Queue();
	void Push(int value);
	void Pop();
	void Copy(Queue& outQueue); //Copies this queue to outQueue
	void Merge(Queue& secondQueue); //merge this queue with second queue (secondQueue goes back) 
	void CalculateRange();
	void ShowQueue();

protected:
	//void recursiveCopy(Element* currentElementOfInQueue, Element* currentElementOfOutQueue);
	Element* recursiveCopy(Element* currentElementOfInQueue, Element* headOfNewQueue = nullptr);
	void recursiveShow(Element* currentElement);
	void recursiveClean(Element* currentElement);
	void setLastElement(Element* newLastElement);
	Element* getLastElement();

private:
	Element* lastElement_;
};
#endif // !QUEUE_H