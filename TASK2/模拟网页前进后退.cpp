#include<iostream>
#include<stack>
#include<string>
#include<stdio.h>
using namespace std;

int main(){
	stack<string>backst,forst;
	// 命令总共有四个，分别是VISIT, BACK, FORWARD, QUIT 
	string command,url;
	// 位于backst栈顶的url是当前的页面 
	backst.push("www.baidu.com");
	cout<<backst.top()<<endl; 
	// 判断输入的指令类型，当command不为QUIT时，执行以下语句 
	while(scanf("%s",&command)!=EOF && command!="QUIT"){
		// VISIT，输入url，并且放入backst栈中，当有visit时，就把forst清空 
		if(command =="VISIT"){
			scanf("%s",&url);
			backst.push(url);
			cout<<url<<endl;
			while(!forst.empty()) forst.pop();
		}
		// BACK，因为backst的栈顶元素表示当前网页，所以先判断backst是否为1，如果为1说明当前网页已经是最后的网页了 
		// 如果不为1，那么就把backst的栈顶url弹出并推入forst中 
		else if(command=="BACK"){
			if(backst.size()==1){
				cout<<"This is the final page"<<endl;
			}
			else{
				url = backst.top();
				backst.top();
				forst.push(url);
				url = backst.top();
				cout<<url<<endl;
			}
		}
		// FORWARD，如果forst为空，说明没有网页可以前进了，如果有，则把forst的栈顶元素放入到backst栈顶。 
		else if(command =="FORWARD"){
			if(forst.empty())
				cout<<"No Page Before"<<endl;
			url = forst.top();
			backst.push(url);
			forst.pop();
			cout<<url<<endl;
		} 
	}
	return 0; 
} 
