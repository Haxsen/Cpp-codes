#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

class doubleLinkList{
	private:
		node *head, *tail;
		
	public:
		doubleLinkList(){
			head = NULL;
			tail = NULL;
		}
		
		void insertEnd(int value){
			node *temp = new node();
			temp->data = value;
			if(head == NULL){
				temp->next = temp->prev = NULL;
				head = temp;
				tail = temp;
			}else{
				temp->prev = tail;
				tail->next = temp;
				tail = temp;
				tail->next = NULL;
			}
		}
		
		void insertStart(int value){
			node *temp = new node;
			temp->data = value;
			if(head == NULL){
				head = temp;
				tail = temp;
				tail->next = NULL;
				head->prev = NULL;
			}else{
				temp->next = head;
				head->prev = temp;
				head = temp;
				head->prev = NULL;
			}
		}
		
		void delNode(int value){
			node *temp = new node;
			node *save = new node;
			temp = head;
			if(head->data == value){
				head = head->next;
				head->prev = NULL;
				return;
			}
			while(temp != NULL){
				if(temp->data == value){
					node *next = temp->next;
					next->prev = save;
					save->next = next;
				}
				save = temp;
				temp = temp->next;
			}
		}
		
		void display(){
			node *temp = new node();
			temp = head;
			while(temp != NULL){
				cout<<temp->data<<"  ";
				temp = temp->next;
			}
			cout<<endl;
		}
		void displayback(){
			node *temp = new node();
			temp = tail;
			while(temp != NULL){
				cout<<temp->data<<"  ";
				temp = temp->prev;
			}
			cout<<endl;
		}
};



int main(){
	doubleLinkList list1;
	int x, insertStart, delNode, insertEnd;
	cout<<"\nEnter the numbers to insert: ";
	while(true){
		cin>>x;
		if (x == -999)
		    break;
		list1.insertEnd(x);
	}
	cout<<"\nEnter the number to insert in Start: ";
	cin>>insertStart;
	list1.insertStart(insertStart);
	cin>>insertStart;
	list1.insertStart(insertStart);
	cout<<"\nEnter the number to insert in End: ";
	cin>>insertEnd;
	list1.insertEnd(insertEnd);
	cout<<"\nEnter the number to delete: ";
	cin>>delNode;
	list1.delNode(delNode);
	cout<<"\nNormal: ";
	list1.display();
	cout<<"\nReversed: ";
	list1.displayback();
}
