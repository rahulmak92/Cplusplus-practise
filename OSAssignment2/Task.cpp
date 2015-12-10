#include"Task.h"
#include<time.h>
#include<stdlib.h>

Task::Task()
{
	value = 0;
	io_length=0;
	io_value=0;
	execution_time=0;
	total_ticks=0;
}
Task::Task(double v,int exec)
{
	execution_time = exec;
	value = v;
	io_length=0;
	io_value = 0;
	total_ticks=0;
}
const double Task::get_value()
{
	return value;
}
const int Task::get_io_length()
{
	return io_length;
}
const double Task::get_io_value()
{
	return io_value;
}
void Task::set_io_length(int l)
{
	io_length = l;
}
void Task::set_io_value(double v)
{
	io_value = v;
}
void Task::set_value(double v)
{
	value = v;
}
void Task::set_execution_time(int exec_time)
{
	execution_time = exec_time;
}
const int Task::get_execution_time()
{
	return execution_time;
}
void Task::set_total_ticks(int t)
{
	total_ticks=t;
}
int Task::get_total_ticks()
{
	return total_ticks;
}