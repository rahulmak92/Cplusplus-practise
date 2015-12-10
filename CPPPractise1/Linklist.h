#include<iostream>
using namespace std;
#ifndef LINKLIST_H
#define LINKLIST_H
class Linklist
{
	private:
	public:
	struct Node
	{
		int value;
		Node *next;
	};
	Node* head;

			Linklist();
			void insertNode(int);
			void displayList();
			void countNodes();
			void deleteNode(int);
			Node* RemoveDuplicates()
			{
				Node *temp=head;
				Node *nodePtr,*prev;
				nodePtr=temp;
				prev=NULL;

				while(nodePtr->next)
				{
					prev=nodePtr;
					nodePtr=nodePtr->next;
					if(nodePtr->value==prev->value)
					{
						Node *checker;
						checker=nodePtr;
						while(checker->next && checker->value==nodePtr->value)
						{
							checker=checker->next;

						}

						nodePtr=checker;
					}
					if(nodePtr->value!=prev->value)
					{
						prev->next=nodePtr;
					}
					else
					{
						prev->next=nodePtr->next;
					}
					//nodePtr=prev;
				}

				return temp;
			}
//			void deleteNode(int,Node**);
};
#endif
