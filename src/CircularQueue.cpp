#include <iostream>
#include <vector>
using namespace std;

class CircularQueue
{
private:
	vector<int> data;	//储存队列的数组
	int head;	//指向队列起始位置的指针
	int tail;	//指向队列结束位置的指针
	int size;	//数组的大小
public:
	CircularQueue();	//默认构造函数
	CircularQueue(int k);	//构造函数
	bool isEmpty();	//判断队列是否为空
	bool isFull();	//判断队列是否已满
	bool enQueue(int value);	//入队,若成功则返回true,反之为false
	bool deQueue();	//出队,若成功则返回false,反之为false
	int Front();	//返回队列起始位置的值
	int Back();	//返回队列结束位置的值
	int Size();	//返回队列的大小
	void show();	//显示队列的所有值
};

CircularQueue::CircularQueue()	//默认构造函数
{
	data.resize(0);
	head = -1;
	tail = -1;
	size = 0;
}

CircularQueue::CircularQueue(int k)	//构造函数
{
	data.resize(k);
	head = -1;
	tail = -1;
	size = k;
}

bool CircularQueue::isEmpty()	//判断队列是否为空
{
	return head == -1;
}

bool CircularQueue::isFull()	//判断队列是否已满
{
	return((tail + 1) % size) == head;
}

bool CircularQueue::enQueue(int value)	//入队,若成功则返回true,反之为false
{
	if (isFull())
	{
		cout << "超出范围啦!" << endl;
		return false;
	}
	if (isEmpty())
		head = 0;

	tail = (tail + 1) % size;
	data[tail] = value;
	return true;
}

bool CircularQueue::deQueue()	//出队,若成功则返回false,反之为false
{
	if (isEmpty())
	{
		cout << "队列已经空啦!" << endl;
		return false;
	}
	if (head == tail)
	{
		head = -1;
		tail = -1;
		return true;
	}
	
	head = (head + 1) % size;
	return true;
}

int CircularQueue::Front()	//返回队列起始位置的值
{
	if (isEmpty())
		return -1;

	return data[head];
}

int CircularQueue::Back()	//返回队列结束位置的值
{
	if (isEmpty())
		return -1;

	return data[tail];
}

int CircularQueue::Size()	//返回队列的大小
{
	if (isEmpty())
		return 0;
	else
	{
		if (head < tail)
			return tail - head + 1;
		if (head > tail)
			return tail - head + size + 1;
		if (head == tail)
			return 1;
	}
}

void CircularQueue::show()	//显示队列的所有值
{
	if (isEmpty())
		cout << "队列为空" << endl;
	else
	{
		if (head < tail)
		{
			cout << "head ->";
			for (int i = head; i < tail; i++)
				cout << data[i] << ",";
			cout << data[tail] << "<- tail" << endl;
		}

		if (head > tail)
		{
			cout << "head ->";
			for (int i = head; i < size; i++)
				cout << data[i] << ",";
			for (int i = 0; i < tail; i++)
				cout << data[i] << ",";
			cout << data[tail] << "<- tail" << endl;
		}

		if (head == tail)
			cout << "head ->" << data[head] << "<- tail" << endl;
	}
}
