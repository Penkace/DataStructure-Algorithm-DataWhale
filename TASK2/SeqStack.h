/* Reference: https://segmentfault.com/a/1190000012954888 */
#ifdef STACK_H_
#define STACK_H_
#include<iostream>

template<Typename T>
class Stack {
public:
	Stack(int top = 10);// 构造函数，设置默认函数top = 10
	~Stack();
	bool destory();
	bool clear();
	int getLength() const; // const的成员函数
	T* getContainer(int i = 0) const;//返回栈顶地址
	int getTop() const;
	int getBase() const;
	bool isEmpty() const;
	bool isFull() const;
	bool push(T data);
	bool pop(T &data);

private:
	int top;
	int base;//栈底元素
	T* container;//栈指针元素
	int stackSize;
};
template<Typename T>
Stack<T>::Stack(int stacksize) {
	this->stacksize = stacksize;
	this->container = new T[this->stacksize];
	this->top = 0;
	this->base = 0;
}
template<Typename T>
bool Stack<T>::destory() {
	this->top = 0;
	this->base = 0;
	delete[]this->container;
	this->container = NULL;
	return true;
}

template<Typename T>
Stack<T>::~Stack() {
	this->destory();
}

template<Typename T>
bool Stack<T>::clear() {
	this->top = 0;
	this->base = 0;
	return true;
}

template<Typename T>
int Stack<T>::getLength() const {
	return this->top - this->base;
}

template<Typename T>
T* Stack<T>::getContainer(int i) const {
	return (i == 0) ? this->container : &this->container[i];
}

template<Typename T>
int Stack<T>::getTop() const {
	return this->top;
}
template<Typename T>
int Stack<T>::getBase() const {
	return this->base;
}
template<Typename T>
bool Stack<T>::isEmpty() const {
	return this->top == this->base;
}

template<Typename T>
bool Stack<T>::push(T data) {
	if (this->isFull()) {
		return false;
	}
	this->container[this->top++] = data;
	return true;
}
template<Typename T>
bool Stack<T>::pop(T &data) {
	if (this->isEmpty()) {
		return false;
	}
	data = this->container[--this->top];
	return true;
}
#endif
