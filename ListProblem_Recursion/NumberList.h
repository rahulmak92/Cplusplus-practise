#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <iostream>

using namespace std;

class NumberList
{
private:
	struct ListNode
	{
		double value;
		ListNode *next;
	};

	ListNode *head;
	double maxNode(ListNode *);
	double minNode(ListNode *);
	bool isSorted(ListNode *);
	double totalSum(ListNode *);
	void reverseList(ListNode *);
	int nodeOccurrence(ListNode *, double);
	void removeDuplicates(ListNode *);
	void removeDuplicates1(ListNode *);
	int count(ListNode *);
	void sort(ListNode *);

public:
	NumberList()
	{
		head = NULL;
	}

	~NumberList();

	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void displayList() const;

	double maxNode()
	{
		return maxNode(head);
	}

	double minNode()
	{
		return minNode(head);
	}

	bool isSorted()
	{
		return isSorted(head);
	}

	double totalSum()
	{
		return totalSum(head);
	}

	void reverseList()
	{
		reverseList(head);
	}

	int nodeOccurrence(double);

	void removeDuplicates()
	{
		removeDuplicates(head);
	}

	int count()
	{
		return count(head);
	}

	void sort()
	{
		sort(head);
	}
};

#endif
