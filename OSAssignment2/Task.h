#ifndef TASK_H
#define TASK_H

class Task
{
private:
	double value;
	int io_length;
	double io_value;
	int execution_time;
	int total_ticks;
public:
	Task();
	Task(double v,int exec);
	void set_io_length(int l);
	void set_io_value(double v);
	void set_value(double v);
	const double get_io_value();
	const int get_io_length();
	const double get_value();
	const int get_execution_time();
	void set_execution_time(int exec_time);
	void set_total_ticks(int t);
	int get_total_ticks();
};
#endif