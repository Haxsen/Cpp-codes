#include <iostream>
#include <conio.h>

using namespace std;

template<class T>
struct node {
	T x;
	node* next;
};

template<class T>
class QueueDynamic{
	node<T> *head;

public:
	QueueDynamic(){	head = NULL; }
	QueueDynamic(const QueueDynamic &c){
		if(c.head){
			head = new node<T>;
			node<T> *t1 = head;
			node<T> *t2 = c.head;
			t1->x = t2->x;
			while(t2 && t2->next){
				t2 = t2->next;
				t1->next = new node<T>;
				t1->next->x = t2->x;
				t1 = t1->next;
			}
			t1->next = NULL;
		} else {
			head = NULL;
		}
	}
	void Enqueue(T value){
		node<T> *t = new node<T>;
		t->x = value;
		t->next = head;
		head = t;
	}
	void Dequeue(){
		if (head == NULL) return;
		node<T> *t = head;
		while(t && t->next && t->next->next){
			t = t->next;
		}
		t->next = NULL;
	}
	bool isEmpty(){
		if (head == NULL) return true;
		else return false;
	}
	void Print(){
		if (!head){
			cout << "\nEmpty!\n";
			return;
		}
		node<T> *t = head;
		cout << endl;
		while(t){
			cout << " " << t->x << " ";
			t = t->next;
		}
		cout << endl;
	}

	~QueueDynamic(){
		delete head;
		head = NULL;
	}
};

int main(){
	QueueDynamic<int> q;
	if (q.isEmpty()) cout << "Empty!";
	q.Enqueue(5);
	q.Enqueue(5);
	q.Print();
	q.Enqueue(5);
	q.Print();
	q.Dequeue();
	q.Print();

	QueueDynamic<int> q2 = q;
	q2.Print();

	q.Enqueue(5);
	q.Enqueue(5);
	q.Print();

	q2.Dequeue();
	q2.Print();

	_getch();
	return 0;
}
