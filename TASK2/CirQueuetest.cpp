#include<iostream>
#include "Cirqueue.hpp"
using namespace std;
int main() {
	CirQueue<int>cq;
	int input;
	while (cin >> input) {
		cq.EnQueue(input);
	}
	cout << cq.getlength() << endl;
	cq.QTraverse();
	return 0;
}
