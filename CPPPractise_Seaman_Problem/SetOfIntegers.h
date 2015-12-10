#ifndef SETOFINTEGERS_H
#define SETOFINTEGERS_H
class Set
{
	private:
			int *elements;
			int size;
			int count;
			int getSize()
			{ return size;}
			int getCount()
			{return count;}
	public:
			Set();
			Set(int);
			Set(const Set &);
			~Set();
			void insert(int);
			bool check(int) const;
			void displaySet();
			Set operator+(const Set &);
			Set operator=(const Set &);
			Set operator*(const Set &);
			Set operator-(const Set &);
			bool operator==(const Set &);
};
#endif
