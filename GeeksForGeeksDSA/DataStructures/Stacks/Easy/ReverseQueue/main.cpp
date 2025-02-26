#include <iostream>

using namespace std;

class Queue
{
private:
	int *valueArray;
	int front, rear, maxSize;

public:
	Queue(int incomingMaxSize)
	// Everything right to the colons --> Member initializer list where values are assigned to variables 
		: maxSize(incomingMaxSize), front(0), rear(-1)
	{
		valueArray = new int[maxSize];
	}

	~Queue()
	{
		delete[] valueArray;
	}

	void enqueue(int x) // Adds value to the rear, similar to push()
	{
		if (isFull())
		{
			cout << "Queue is full! Cannot enqueue " << x << endl;
			return;
		}
		valueArray[++rear] = x;
	}

	int dequeue() // Removes element and is similar to pop()
	{
		if (isEmpty())
		{
			cout << "Queue is empty! Cannot dequeue." << endl;
			return -1;
		}
		return valueArray[front++]; // Move front forward
	}

	bool isEmpty()
	{
		return front > rear;
	}

	bool isFull()
	{
		return rear == maxSize - 1;
	}

	void checkArrayValues()
	{
		if (isEmpty())
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		cout << "Queue: ";
		for (int i = front; i <= rear; i++)
		{
			cout << valueArray[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int input[] = {1, 2, 3, 4, 5};
	int arraySize = sizeof(input) / sizeof(input[0]);

	Queue q(arraySize);

	for (int i = 0; i < arraySize; i++)
	{
		q.enqueue(input[i]);
	}

	q.checkArrayValues();

	cout << "Dequeued: " << q.dequeue() << endl;
	q.checkArrayValues();

	cout << "Dequeued: " << q.dequeue() << endl;
	q.checkArrayValues();

	return 0;
}
