/*
 * pointers.cpp
 *
 *  Created on: 10 mars 2022
 *      Author: Matthias
 */

#include <utility>
#include <iostream>
#include <vector>

using namespace std;

template<class T,class U>
ostream& operator<<(ostream& out, const pair<T,U>& p){
	return out << p.first << "/" << p.second;
}

void displayPairModeC(ostream* out_ptr, pair<int,double>* p_ptr){
	*out_ptr << p_ptr->first << "#" << p_ptr->second << endl;
}

pair<int,double>* allouerPaire3(double second){
	return new pair<int,double>(3,second);
}

 int allouerPaire3bis(pair<int,double>** p_ptr_ptr, double second){
	*p_ptr_ptr = new pair<int,double>(3,second);
	// TODO : here handle errors
	return 0;
}

int modifyPair3to4(pair<int,double>* p_ptr){
	p_ptr->first = 4;
	return 0;
}

int main(int argc, char **argv) {
	pair<int,double> p(3, 3.14);
	pair<int,double>* p_ptr = new pair<int,double>(4,6.28);
	pair<int,pair<int,double>> p2 {3, {4,3.14}};
	pair<int,vector<int>> p3 {3, {4,5,6}};
	pair<int,double>* p5_ptr = allouerPaire3(9.36);

	cout << &p << "," << &p_ptr << "," << p_ptr << endl;
	cout << p.first << "," << p.second << endl;
	cout << p_ptr->first << "," << (*p_ptr).second << endl;
	cout << p << endl; // p par reference
	cout << *p_ptr << endl; // zone pointée passée par référence

	cout << *p5_ptr << endl;
	delete p5_ptr;

	allouerPaire3bis(&p5_ptr, 5.123456);
	cout << *p5_ptr << endl;

	modifyPair3to4(p5_ptr);
	cout << *p5_ptr << endl;

	modifyPair3to4(&p);
	cout << p << endl;

	cout << p2 << endl;

	// cout << p3 << endl;

	displayPairModeC(&cout, &p);
	displayPairModeC(&cout, p_ptr);

	// liberer les paires dans le Heap
	delete p5_ptr;
	delete p_ptr;
}


