#include <iostream>   // for NULL
using namespace std;

class NumberList
{
private:
    struct ListNode    // a data type
    {
        double value;
        struct ListNode *next;
    };
    ListNode *head;

public:
    NumberList();
    ~NumberList();
    void sort();
    void appendNode(double);
    void displayList();
    void insertNode(double num);
};
void NumberList::insertNode(double num)
{
   ListNode *newNode;   // ptr to new node
   ListNode *p;
// ptr to traverse list
   ListNode *n;
// node previous to p
   //allocate new node
   newNode = new ListNode;
   newNode->value = num;
   // skip all nodes less than num
   p = head;
   while (p && p->value < num) {
     n = p;        // save
     p = p->next;  // advance
}
   if (p == head) {
//insert before first
     head = newNode;
     newNode->next = p;
}
   else {                //insert after n
     n->next = newNode;
     newNode->next = p;
}
}
NumberList::NumberList() {
    head = NULL;
}


NumberList::~NumberList() {

    ListNode *p = head;
    ListNode *n;
    while (p!=NULL) {
        n = p->next;  //save address of next node
        delete p;
        p = n;     //make p point to the next node
    }
}

void NumberList::appendNode(double num) {

    ListNode *newNode;
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;

    if (head==NULL)
        head = newNode;

    else {
        ListNode *p = head;
        while (p->next!=NULL) {
            p = p->next;
        }
        // now p points to the last node
        p->next = newNode;
    }
}


void NumberList::displayList() {

    ListNode *p = head;
    while (p!=NULL) {
        cout << p->value  << "  ";
        p = p->next;
    }
    cout << endl;

}
void NumberList::sort()
{
	NumberList *newList=new NumberList();
	ListNode *nodePtr,*temp;
	temp=NULL;
	nodePtr=head;

	while(nodePtr)
	{
		temp=nodePtr;
		newList->insertNode(nodePtr->value);
		delete nodePtr;
		nodePtr=temp->next;
	}
	head=newList->head;
}

int main() {

    // set up the list
    NumberList list;

    //Append Some values to the list
    list.appendNode(7.9);
    list.appendNode(2.5);

    list.appendNode(12.6);


    // Display the values in the list
    list.displayList();
    list.sort();
    list.displayList();

}
