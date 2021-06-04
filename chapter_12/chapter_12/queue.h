#pragma once
#include <iostream>
#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
private:
	long arrive;
	int processtiome;

public:
	Customer() { arrive = processtiome = 0; };
	void set(long when);
	long when() const { return arrive; };
	int ptime() const { return processtiome; };

};

typedef Customer Item;

class Queue
{
private:
	enum { Q_SIZE = 10 };

	struct Node
	{
		Item item;
		struct Node* next;
	};

	Node* front;
	Node* rear;
	int items;
	const int qsize;
public:
	Queue(int qs = Q_SIZE);
	~Queue();

	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);

public:
	// 显示提供 赋值 和 复制 构造函数
	Queue(const Queue& q) :qsize(0),front(NULL),rear(NULL),items(0) {};
	Queue& operator=(const Queue& q) { return *this; };
};
#endif