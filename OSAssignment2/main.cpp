#include"Task.h"
#include"Priority_queue.h"
#include "Success_array.h"
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<fstream>

using namespace std;

double generate_number();
int generate_execution_time();
int generate_io_length();

int main()
{
	ofstream output_file;
	output_file.open("output.txt");

	srand(time(NULL));
	Task *ptr;
	Priority_queue queue;
	Priority_queue io_queue;
	Success_array success;

	int value_status = 0;
	int finished_status = 0;
	int io_status = 0;
	int slice = 20;

	//number of slices
	for(int i = 0; i <75;i ++)
	{
		//slices, 20 ticks in a slice
		for(int j = 0; j<slice;j++)
		{
			double number = generate_number();
			//setting the io_value and length if number > .95 also will not generate if
			//remaining execution time is zero i.e. task is complete
			if(number > 0.98&& !queue.is_empty() && io_status !=1 && queue.get_remaining_exec()!=0)
			{
				queue.set_io_number(number);
				queue.set_io_len(generate_io_length());
				io_status = 1;
			}
			//decrement the execution time if io event hasnt occured
			if(io_status!=1)
			{
				if(!queue.is_empty() && queue.get_remaining_exec()>=1)
					queue.decrement_execution_time();
			}
			if(value_status ==0)
			{
				//generate new task object with execution time and value
				ptr = new Task(generate_number(),generate_execution_time());
				//if value > .9 set status and save this object
				if(ptr->get_value()>.96)
					value_status =1;
				//otherwise delete it and try again next iteration
				if(value_status == 0)
					delete ptr;
			}
		}
		io_queue.decrement_all(slice);
		queue.increment_ticks(slice);
		io_queue.increment_ticks(slice);
		//remove task if execution time is 0
		//also set flag since theres no need to rotate
		if(!queue.is_empty() && queue.get_remaining_exec() == 0)
		{
			success.insert(queue.dequeue_task());
			finished_status = 1;
		}
		if(io_status ==1)
		{
			Task t =queue.dequeue_task();
			io_queue.enqueue_task(&t);
		}
		//check io queue for finished io tasks
		int size = io_queue.get_count();
		for(int i =0; i < size;i++)
		{
			//if len -0 then task done
			if(io_queue.get_io_len()==0)
			{
				Task t = io_queue.dequeue_task();
				queue.enqueue_task(&t);
			}
			//if first task len !=0 then rotate it to
			//the end and look at a different one
			else
				io_queue.rotate();
		}
				
		//if ptr has a value over .9 value_status is 1
		//will insert new task at the end of queue before
		//old value gets rotated
		if(value_status ==1)
		{
			queue.enqueue_task(ptr);
			value_status =0;
			delete ptr;
		}
		
		/*do the rotation when slice is done
		make sure a value hasnt been popped off just now because if it was you dont need
		to rotate*/
		if(finished_status!=1 && io_status!=1)
			queue.rotate();
		//finished status is one if an item was popped, zero otherwise
		//set it back to zero for next iteration
		finished_status = 0;
		io_status=0;
	}
	cout<<"Number of tasks still in wait queue "<<queue.get_count()<<endl;
	cout<<"Number of successful tasks "<< success.get_index()<<endl;
	cout<<"Number of tasks in io queue "<<io_queue.get_count()<<endl;
	cout<<"Throughput: "<<success.get_index()/1500.0<<endl;
	int total =0;
	for(int i = 0; i < success.get_index();i++)
	{
		Task temp = success.get_task(i);
		total+=temp.get_total_ticks();
	}
	if(success.get_index()!=0)
		cout<<"Average Latency: "<<total/success.get_index()<<endl<<endl;

	success.write_to_file(output_file);
	cout<<"successful tasks have printed to file."<<endl;
	
	output_file.close();
	return 0;
}
//generate number 0-1 for determining creation of a task or io value
double generate_number()
{
	return (double)rand()/RAND_MAX;
}
//execution time betweem 25-34
int generate_execution_time()
{
	return rand()%40 + 10;
}
//io_execution time between 20-49
int generate_io_length()
{
	return rand()%30 + 15;
}