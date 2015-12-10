class Station
{
private:
	int max, min;
	bool transmitting;
	bool is_in_wait;
	bool in_collision;
public:
	Station();
	Station(int, int);
	double get_r1();
	int get_r2();
	int get_r3();
	int get_r4();
	int get_r5();
	bool its_transmitting(){return transmitting;}
	void start_transmit(){transmitting = true;}
	void end_transmit(){transmitting = false;}
	bool is_waiting(){return is_in_wait;}
	void set_waiting_status(int i){is_in_wait = i;}
	void set_collision(int i){in_collision = i;}
	bool is_in_collision(){return in_collision;}

};
