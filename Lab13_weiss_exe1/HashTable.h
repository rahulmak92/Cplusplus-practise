template <typename HashedObj>
#include<list>
#ifndef HASHTABLE_H
#define HASHTABLE_H
class HashTable
{
	public:
			explicit HashTable(int size=101);
			bool contains(const HashedObj & x) const;
			void makeEmpty();
			void insert(const HashedObj & x);
			void remove(const HashedObj & x);
	private:
			//vector<list<HashedObj> > theLists;

};
#endif
