#include <iostream>
#include <conio.h>
#include <list>

using namespace std;

void remove_evenpos(list<int> &l){
	for (auto it = l.begin(); it != l.end(); ){
		if(it!=l.end()) auto t = it._Getpnext();
		it = l.erase(it);
		if (it!=l.end()) it++;
	}
}
void remove_duplicates(list<int> &l){
	l.sort();
	l.unique();
}
void remove_duplicates_consecutive(list<int> &l){
	auto rep = l.begin();
	rep++;
	for(auto it=l.begin();it!=l.end() && rep!=l.end(); ){
		if (*it == *rep){
			it = l.erase(it);
			rep++;
		} else {
			rep++;
			it++;
		}
	}
	//l.unique([](int a, int b){return (a == b); });
}
void print_list(list<int> &l){
	for (auto it = l.begin(); it != l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
void print_backward(list<int> &l){
	l.reverse();
	for (auto it = l.begin(); it != l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void main(){
	list<int> ml { 0, 1, 2, 8, 3, 3, 4, 5, 5, 6, 6, 5, 7, 8, 9, 10 };
	print_list(ml);
	remove_evenpos(ml);
	print_list(ml);
	print_backward(ml);
	list<int> ml2{ 0, 0, 1, 1, 4, 2, 3, 4, 4, 5 };
	print_list(ml2);
	remove_duplicates_consecutive(ml2);
	print_list(ml2);
	remove_duplicates(ml2);
	print_list(ml2);

	_getch();
}
