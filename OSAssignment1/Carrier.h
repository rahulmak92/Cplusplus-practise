#ifndef CARRIER_H
#define CARRIER_H


class Carrier
{
	int *ptr;
	int size=7;
	int successful_messages;
	int m_right, m_left;
	bool collision_one,collision_three;
	bool collision_two_one, collision_two_two;
	int middle;
public:
	Carrier(int s,int m);
	~Carrier(){delete []ptr;}
	void add_bit(int station, int count,int message);
	void inc_success(){successful_messages++;}
	int get_success(){return successful_messages;}
	bool is_one_free(){return ptr[0]==0;}
	bool is_two_free(){return ptr[middle]==0;}
	bool is_three_free(){return ptr[size-1]==0;}
	int get_one(){return ptr[0];}
	int get_two(){return ptr[middle];}
	int get_three(){return ptr[size-1];}
	void handle_collision(int index,int station);
	void check_collision(int index,int station);
	void clear_carrier();
	bool is_full();
};

#endif
