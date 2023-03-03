#include "Queue.h"


#ifndef QUEUE1_H
#define QUEUE1_H

class QueuePublic : public Queue {
public:	
	void CalculateRange();
};
class QueueProtected : protected Queue {
public:	
	void CalculateRange();
	void PushProtected(int value);
	void PopProtected();
	void CopyProtected(QueueProtected& outQueue); //Copies this queue to outQueue
	void MergeProtected(QueueProtected& secondQueue); //merge this queue with second queue (secondQueue goes back) 
	void ShowQueueProtected();
};
class QueuePrivate : private Queue {
public:
	void CalculateRange();
	void PushPrivate(int value);
	void PopPrivate();
	void CopyPrivate(QueuePrivate& outQueue); //Copies this queue to outQueue
	void MergePrivate(QueuePrivate& secondQueue); //merge this queue with second queue (secondQueue goes back) 
	void ShowQueuePrivate();
};
#endif // !QUEUE1_H
