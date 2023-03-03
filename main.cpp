#include<iostream>
#include "Queue.h"
#include "Queue1.h"
void addQueuePublic(QueuePublic*& arr, int& size);
void addQueueProtected(QueueProtected*& arr, int& size);
void addQueuePrivate(QueuePrivate*& arr, int& size);
void showQueuesPublic(QueuePublic*& arr, int& size);
void showQueuesProtected(QueueProtected*& arr, int& size);
void showQueuesPrivate(QueuePrivate*& arr, int& size);



int menu(QueuePublic*& queues, int& queuesCount);
int menu(QueueProtected*& queues, int& queuesCount);
int menu(QueuePrivate*& queues, int& queuesCount);



int main() {

	int sizePublic = 0;
	int sizeProtected = 0;
	int sizePrivate = 0;
	int menuCode = 4;
	QueuePublic* arrayOfPublicQueues = new QueuePublic[sizePublic];
	QueueProtected* arrayOfProtectedQueues = new QueueProtected[sizeProtected];
	QueuePrivate* arrayOfPrivateQueues = new QueuePrivate[sizePrivate];
	
	
	while (menuCode != 0) {
		int queueType = 0;
		if (menuCode == 4) {
			std::cout << "Choose the type of queue you'll work with" << std::endl;
			std::cout << "1) Public queue" << std::endl;
			std::cout << "2) Protected queue" << std::endl;
			std::cout << "3) Private queue" << std::endl;
			std::cout << "0) exit program" << std::endl;
			std::cin >> queueType;
			menuCode = 2;
		}
		while (queueType < 0 || queueType > 3) {
			std::cout << "Choose correct Type" << std::endl;
			std::cin >> queueType;
			break;

		}
		
		switch (queueType)
		{
		case 1:
			menuCode = menu(arrayOfPublicQueues, sizePublic);
			break;
		case 2:
			menuCode = menu(arrayOfProtectedQueues, sizeProtected);
			break;
		case 3:
			menuCode = menu(arrayOfPrivateQueues, sizeProtected);
			break;
		case 0:
			menuCode = 0;
			break;
		}
	}
	return 0;
}


void addQueuePublic(QueuePublic*& arr, int& size) {
	QueuePublic* newArrayOfQueues = new QueuePublic[++size];
	for (int i = 0; i < size - 1; i++) {
		arr[i].Copy(newArrayOfQueues[i]);
	}

	delete[] arr;
	arr = newArrayOfQueues;
}


void addQueueProtected(QueueProtected*& arr, int& size) {
	QueueProtected* newArrayOfQueues = new QueueProtected[++size];
	for (int i = 0; i < size - 1; i++) {
		arr[i].CopyProtected(newArrayOfQueues[i]);
	}

	delete[] arr;
	arr = newArrayOfQueues;
}

void addQueuePrivate(QueuePrivate*& arr, int& size) {
	QueuePrivate* newArrayOfQueues = new QueuePrivate[++size];
	for (int i = 0; i < size - 1; i++) {
		arr[i].CopyPrivate(newArrayOfQueues[i]);
	}

	delete[] arr;
	arr = newArrayOfQueues;
}

void showQueuesPublic(QueuePublic*& arr, int& size) {
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ") ";
		arr[i].ShowQueue();
	}
}

void showQueuesProtected(QueueProtected*& arr, int& size) {
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ") ";
		arr[i].ShowQueueProtected();
	}
}
void showQueuesPrivate(QueuePrivate*& arr, int& size) {
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ") ";
		arr[i].ShowQueuePrivate();
	}
}



int menu(QueuePublic*& queues, int& queuesCount) {
	int action = 1;
	int currrentQueue = -1;
	while (action != 0) {
		std::cout << "\nSelect an action:" << std::endl;
		std::cout << "1) Add queue" << std::endl;
		std::cout << "2) Push element" << std::endl;
		std::cout << "3) Pop element" << std::endl;
		std::cout << "4) Copy queue" << std::endl;
		std::cout << "5) Calculate range of queue" << std::endl;
		std::cout << "6) Merge queues" << std::endl;
		std::cout << "7) Show queue" << std::endl;
		std::cout << "8) Choose queue" << std::endl;
		std::cout << "9) Select queue type" << std::endl;
		std::cout << "0) Exit\n" << std::endl;
		std::cin >> action;
		std::cout << std::endl;
		switch (action)
		{

		case 1:
			addQueuePublic(queues, queuesCount);
			currrentQueue = queuesCount-1;
			std::cout << "\nQueue added!" <<std::endl;
			break;


		case 2:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				int value;
				std::cout << "Enter a value: ";
				std::cin >> value;
				queues[currrentQueue].Push(value);
				std::cout << "\nValue pushed : " << value << std::endl;
			}
			break;


		case 3:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				queues[currrentQueue].Pop();
			}
			break;


		case 4:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				addQueuePublic(queues, queuesCount);
				queues[currrentQueue].Copy(queues[queuesCount - 1]);
				std::cout << "\nQueue copied!" << std::endl;
			}
			break;


		case 5:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				queues[currrentQueue].CalculateRange();
			}
			break;


		case 6:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				int second;
				std::cout << "Choose second queue:\n" << std::endl;
				showQueuesPublic(queues, queuesCount);
				std::cin >> second;
				while (second < 1 || second > queuesCount) {
					std::cout << "Input correct number:" << std::endl;
					std::cin >> second;
				}
				addQueuePublic(queues, queuesCount);
				queues[currrentQueue].Copy(queues[queuesCount - 1]);
				queues[queuesCount-1].Merge(queues[second - 1]);
				std::cout << "\nQueues merged!";
			}
			break;


		case 7:
			if (currrentQueue == -1)
			{
				std::cout << "Choose queue you will work with" << std::endl;
				goto Choose;
			}
			else
			{
				queues[currrentQueue].ShowQueue();
			}
			break;


		case 8:
			Choose:
			int choose;
			std::cout << "Choose queue you will work with:" << std::endl;
			showQueuesPublic(queues, queuesCount);
			std::cin >> choose;
			while (choose < 1 || choose > queuesCount) {
				std::cout << "Input correct number:" << std::endl;
				std::cin >> choose;
			}
			currrentQueue = choose - 1;
			break;

		case 9:
			return 4;

		case 0:
			break;
			return 0;


		default:
			std::cout << "Choose correct action" << std::endl;
			break;
		}

	}
	return 0;
}

int menu(QueueProtected*& queues, int& queuesCount) {
	int action = 1;
	int currrentQueue = -1;
	while (action != 0) {
		std::cout << "\nSelect an action:" << std::endl;
		std::cout << "1) Add queue" << std::endl;
		std::cout << "2) Push element" << std::endl;
		std::cout << "3) Pop element" << std::endl;
		std::cout << "4) Copy queue" << std::endl;
		std::cout << "5) Calculate range of queue" << std::endl;
		std::cout << "6) Merge queues" << std::endl;
		std::cout << "7) Show queue" << std::endl;
		std::cout << "8) Choose queue" << std::endl;
		std::cout << "9) Select queue type" << std::endl;
		std::cout << "0) Exit\n" << std::endl;
		std::cin >> action;
		std::cout << std::endl;
		switch (action)
		{

		case 1:
			addQueueProtected(queues, queuesCount);
			currrentQueue = queuesCount - 1;
			std::cout << "\nQueue added!" << std::endl;
			break;


		case 2:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				int value;
				std::cout << "Enter a value: ";
				std::cin >> value;
				queues[currrentQueue].PushProtected(value);
				std::cout << "\nValue pushed : " << value << std::endl;
			}
			break;


		case 3:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				queues[currrentQueue].PopProtected();
			}
			break;


		case 4:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				addQueueProtected(queues, queuesCount);
				queues[currrentQueue].CopyProtected(queues[queuesCount - 1]);
				std::cout << "\nQueue copied!" << std::endl;
			}
			break;


		case 5:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				queues[currrentQueue].CalculateRange();
			}
			break;


		case 6:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				int second;
				std::cout << "Choose second queue:\n" << std::endl;
				showQueuesProtected(queues, queuesCount);
				std::cin >> second;
				while (second < 1 || second > queuesCount) {
					std::cout << "Input correct number:" << std::endl;
					std::cin >> second;
				}
				addQueueProtected(queues, queuesCount);
				queues[currrentQueue].CopyProtected(queues[queuesCount - 1]);
				queues[queuesCount - 1].MergeProtected(queues[second - 1]);
				std::cout << "\nQueues merged!";
			}
			break;


		case 7:
			if (currrentQueue == -1)
			{
				std::cout << "Choose queue you will work with" << std::endl;
				goto Choose;
			}
			else
			{
				queues[currrentQueue].ShowQueueProtected();
			}
			break;


		case 8:
		Choose:
			int choose;
			std::cout << "Choose queue you will work with:" << std::endl;
			showQueuesProtected(queues, queuesCount);
			std::cin >> choose;
			while (choose < 1 || choose > queuesCount) {
				std::cout << "Input correct number:" << std::endl;
				std::cin >> choose;
			}
			currrentQueue = choose - 1;
			break;

		case 9:
			return 4;

		case 0:
			break;
			return 0;


		default:
			std::cout << "Choose correct action" << std::endl;
			break;
		}

	}
	return 0;
}



int menu(QueuePrivate*& queues, int& queuesCount) {
	int action = 1;
	int currrentQueue = -1;
	while (action != 0) {
		std::cout << "\nSelect an action:" << std::endl;
		std::cout << "1) Add queue" << std::endl;
		std::cout << "2) Push element" << std::endl;
		std::cout << "3) Pop element" << std::endl;
		std::cout << "4) Copy queue" << std::endl;
		std::cout << "5) Calculate range of queue" << std::endl;
		std::cout << "6) Merge queues" << std::endl;
		std::cout << "7) Show queue" << std::endl;
		std::cout << "8) Choose queue" << std::endl;
		std::cout << "9) Select queue type" << std::endl;
		std::cout << "0) Exit\n" << std::endl;
		std::cin >> action;
		std::cout << std::endl;
		switch (action)
		{

		case 1:
			addQueuePrivate(queues, queuesCount);
			currrentQueue = queuesCount - 1;
			std::cout << "\nQueue added!" << std::endl;
			break;


		case 2:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				int value;
				std::cout << "Enter a value: ";
				std::cin >> value;
				queues[currrentQueue].PushPrivate(value);
				std::cout << "\nValue pushed : " << value << std::endl;
			}
			break;


		case 3:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				queues[currrentQueue].PopPrivate();
			}
			break;


		case 4:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				addQueuePrivate(queues, queuesCount);
				queues[currrentQueue].CopyPrivate(queues[queuesCount - 1]);
				std::cout << "\nQueue copied!" << std::endl;
			}
			break;


		case 5:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				queues[currrentQueue].CalculateRange();
			}
			break;


		case 6:
			if (currrentQueue == -1)
			{
				goto Choose;
			}
			else
			{
				int second;
				std::cout << "Choose second queue:\n" << std::endl;
				showQueuesPrivate(queues, queuesCount);
				std::cin >> second;
				while (second < 1 || second > queuesCount) {
					std::cout << "Input correct number:" << std::endl;
					std::cin >> second;
				}
				addQueuePrivate(queues, queuesCount);
				queues[currrentQueue].CopyPrivate(queues[queuesCount - 1]);
				queues[queuesCount - 1].MergePrivate(queues[second - 1]);
				std::cout << "\nQueues merged!";
			}
			break;


		case 7:
			if (currrentQueue == -1)
			{
				std::cout << "Choose queue you will work with" << std::endl;
				goto Choose;
			}
			else
			{
				queues[currrentQueue].ShowQueuePrivate();
			}
			break;


		case 8:
		Choose:
			int choose;
			std::cout << "Choose queue you will work with:" << std::endl;
			showQueuesPrivate(queues, queuesCount);
			std::cin >> choose;
			while (choose < 1 || choose > queuesCount) {
				std::cout << "Input correct number:" << std::endl;
				std::cin >> choose;
			}
			currrentQueue = choose - 1;
			break;

		case 9:
			return 4;

		case 0:
			break;
			return 0;


		default:
			std::cout << "Choose correct action" << std::endl;
			break;
		}

	}
	return 0;
}