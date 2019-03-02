#include<iostream>
#include "LinkQueue.hpp"
using namespace std;

int main() {
	LinkQueue<int> q;
	for (int i = 0; i < 10; i++) {
		q.EnQueue(i);
		cout << q.size() << endl;
	}
	
	cout<< q.isEmpty();
	system("pause");
	return 0;
}
