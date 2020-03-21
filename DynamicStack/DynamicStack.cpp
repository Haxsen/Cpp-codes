#include <iostream>
#include <conio.h>

using namespace std;

struct node{
	int data;
	node *next;
};

class StackDynamic {
	node *top;

public:
	StackDynamic(){ top = NULL; };
	void push(int v){ 
		node *temp = new node;
		temp->data = v;
		temp->next = top;
		top = temp;
	}
	void pop(){
		if (top != NULL){
			node *temp = top;
			top = top->next;
			cout << temp->data << " Popped From Stack " << endl;
			delete temp;
		}
		else
		{
			cout << "Stack Underflow " << endl;
		}

	}


	void display(){
		node *temp = top;
		while (temp != NULL){
			cout << temp->data << endl;
			temp = temp->next;
		}

	}
	void PrintTop(){
		if (top == NULL){
			cout << "Stack is Empty..\n ";
		}
		else{
			cout << " Top is " << top->data << endl;
		}
	}

	~StackDynamic(){
		delete top;
		top = NULL;
	}

};

int main()
{
	StackDynamic s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.PrintTop();
	s.push(6);
	s.PrintTop();
	s.pop();
	s.PrintTop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.PrintTop();

	_getch();
	return 0;
}
