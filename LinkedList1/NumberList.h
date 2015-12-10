#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include<iostream>

class NumberList
{
	private:
			struct ListNode
			{
				double value;
				struct ListNode *next;
			};
			ListNode *head;
	public:
			NumberList()
			{
				head=NULL;
			}
			~NumberList();
			void appendNode(double);
			void insertNode(double);
			void deleteNode(double);
			void displayList() const;
};
#endif
