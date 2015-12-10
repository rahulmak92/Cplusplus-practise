#include"Carrier.h"

Carrier::Carrier(int s,int m)
{
		size = s;
		successful_messages=0;
		m_right=0, m_left=0;
		collision_one=false,collision_two_one=false,collision_two_two = false,collision_three=false;
		middle = m;

		ptr = new int [size];
		for(int i = 0; i < size;i++)
			ptr[i] = 0;
}
void Carrier::add_bit(int station, int count,int message)
{

	check_collision(count,station);

	if(collision_one == false)
	{	
	
		if(station == 0 )//station 0 sends message
		{
			if(count <size && ptr[count]!=4)
				ptr[count] = 1;
			//message has reached station 2
			if(count >= size)
			{
				for(int i = 0; i < size; i++)
				{
					if(ptr[i] == 1)
					{
						ptr[i] = 0;
						break;
					}
				}
			}
			//message has left station 0, station clear
			if(count>=message && ptr[count-message]!=4)
				ptr[count-message]=0;
		}
	}
	else
	{
		if(station==0)
			handle_collision(count,station);
	}

	
	if(station == middle)
	{
		if(collision_two_two == false)
		{
			if(count + middle <=size-1 && ptr[count+middle]!=4)
				ptr[count+middle] = 2;
		}
		if(collision_two_one == false)
		{
			if(middle-count >=0 &&ptr[middle-count]!=4)
				ptr[middle-count] = 2;
		}
		
		if(count >= message)
		{
			if(collision_two_two == false)
			{
				if(count +middle < size && ptr[count+middle-message]!=4)
					ptr[count +middle-message]=0;
			}
			if(collision_two_one==false)
			{
				if(count < middle+1 && ptr[middle-count+message]!=4)
					ptr[middle-count+message]=0;
			}
		}

		if(collision_two_one == false)
		{
			if(count>= middle+1)
			{
				for(int i = 0; i < message;i++)
				{
					if((ptr[i+1] == 0 || ptr[i+1] == 3) && ptr[i] == 2)
					{
						ptr[i] = 0;
						break;
					}
				}
			}
		}
		if(collision_two_two == false)
		{
			if((count +middle) >= size)
			{
				for(int i = middle; i < size; i++)
				{
					if(ptr[i] == 2)
					{
						ptr[i] = 0;
						break;
					}
				}
			}
		}
		if(station == middle)
		{
			if(collision_two_one==true || collision_two_two==true)
				handle_collision(count,station);
		}
	}
		

	if(collision_three == false)
	{
		if(station == size-1)
		{
			if(size-1-count>=0 && ptr[size-1-count]!=4)
				ptr[size-1-count] = 3;

			if(count >= message && count < size && ptr[size-1-count+message]!=4)
				ptr[size - 1 -count + message] = 0;

			if(count >= size)
			{
				for(int i = 0; i < message;i++)
				{
					if((ptr[i+1] == 0 || ptr[i+1] == 2) && ptr[i] ==3)
					{
						ptr[i] = 0;
						break;
					}
				}
			}
		}
	}
	else
	{
		if(station == size-1)
			handle_collision(count,station);
	}
}
void Carrier::check_collision(int count,int station)
{
	if(station == 0 && collision_one!=true)
	{
		if(ptr[count]!=0 &&count<=size-1)
		{
			collision_one = true;
			if(ptr[count] == 2)
				collision_two_one = true;
			if(ptr[count] == 3)
				collision_three = true;
		}
	}
	if(station == middle)
	{
		if(collision_two_one !=true)
		{
			if(middle-1-count >=0 && ptr[middle-1-count+1]!=0)
			{
				collision_two_one = true;
				collision_one = true;
			}
			
		}
		if(collision_two_two!=true)
		{
			if((middle+1+count)<size && ptr[middle+count]!=0)
			{
				collision_two_two = true;
				collision_three = true;
			}
		}
	}
	if(station == size-1 && collision_three !=true)
	{
		if(count >=1 && ptr[size-1 - count]!=0 && size - count >0)
		{
			collision_three = true;
			if(ptr[size-1 -count] == 1)
				collision_one = true;
			if(ptr[size-1-count] == 2)
				collision_two_two =true;
		}
	}
}
void Carrier::handle_collision(int index, int station)
{
	if(station == 0)
	{
		if(index < size)
			ptr[index]=4;
	}
	if(station == middle)
	{
		if(collision_two_one == true && middle- index +1>=0)
			ptr[middle-index+1] = 4;
		if(collision_two_two == true && middle+1 + index <= size)
			ptr[middle+1 + index-1] = 4;
	}
	if(station == size-1)
	{
		if(size-1-index>=0)
			ptr[size-1-index]=4;
	}

}
void Carrier::clear_carrier()
{
	for(int i = 0; i < size;i++)
		ptr[i] = 0;
}
bool Carrier::is_full()
{
	for(int i = 0; i < size; i++)
	{
		if(ptr[i] != 4)
			return false;
	}
	collision_one = false;
	collision_three = false;
	collision_two_one=false;
	collision_two_two = false;
	return true;
}

				