#include<iostream>
#include"linklist.hpp"
#include<string>
using namespace std;
int main() {
	LinkStack<string> bstack,fstack;
	string command, url;
	bstack.push("www.baidu.com");
	cout << bstack.Stop() << endl;
	while (cin >> command, command != "QUIT") {
		if (command == "VISIT") {
			cin >> url;
			bstack.push(url);
			cout << url << endl;
			while (!fstack.isEmpty()) {
				fstack.clear();
			}
		}
		else if (command == "BACK") {
			if (bstack.size() == 1) {
				cout << "No Page Back" << endl;
			}
			else {
				url = bstack.pop();// 在STL库里面的pop是不会返回值的
				fstack.push(url);
				cout << bstack.Stop() << endl;
			}
		}
		else if (command == "FORWARD") {
			if (fstack.isEmpty()) {
				cout << "No Page Forward" << endl;
			}
			else {
				url = fstack.pop();
				cout << url << endl;
				bstack.push(url);
			}
		}
	}
	system("pause");
	return 0;
}
