#include <iostream>
#include <conio.h>
#include <list>

using namespace std;

list<int> Merger(list<int> l1, list<int> l2){
	l1.merge(l2);
	return l1;
}

void print_list(list<int> l){
	for (auto it = l.begin(); it != l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void main(){
	list<int> t1, t2;
	t1.push_back(1);
	t1.push_back(2);
	t2.push_back(3);
	t2.push_back(4);
	cout << "t1: ";
	print_list(t1);
	cout << "t2: ";
	print_list(t2);
	list<int> t = Merger(t1, t2);
	cout << "Merged: ";
	print_list(t);

	_getch();
}
