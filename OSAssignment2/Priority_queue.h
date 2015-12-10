#include"Task.h"
#include<deque>
#include<iostream>
using namespace std;

class Priority_queue
{
private:
	deque<Task>q;
	Task method_task;
	int count;
public:
	Priority_queue(){count=0;};
	void enqueue_task(Task *t);
	const Task & dequeue_task();
	void print_first_element();
	bool is_empty();
	void decrement_execution_time();
	void rotate();
	const int get_remaining_exec();
	const int get_count();
	void decrement_all(int slice);
	void set_io_number(double num);
	void set_io_len(int len);
	int get_io_len();
	int get_io_number();
	void increment_ticks(int slice);
};