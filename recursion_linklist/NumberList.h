#include<iostream>
#ifndef NUMBERLIST_H
#define NUMBERLIST_H
using namespace std;
class NumberList
{
	private:
			struct ListNode
			{
				struct ListNode *next;
				double value;
			};
			ListNode *head;
			int countNodes(ListNode *) const;
			void showReverse(ListNode *) const;
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
			int numNodes() const
			{
				return countNodes(head);
			}
			void displayBackwards() const
			{
				showReverse(head);
			}
};
#endif
