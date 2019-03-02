/*****************************************************************************
	Reference: https://blog.csdn.net/EckelWei/article/details/8634829
*****************************************************************************/
template<typename T>
class CirQueue {
private:
	int size;
	int head, tail;
	T *base;
public:
	CirQueue(int init= 10);
	int getlength();
	bool EnQueue(T val);
	T DeQueue();
	void QTraverse();
};
template<typename T>
CirQueue<T>::CirQueue(int init) {
	this->size = init;
	base = new T[size];
	if (!base) exit(1);
	head = tail = 0;
}
template<typename T>
void CirQueue<T>::QTraverse() {
	int length = (tail - head + size) % size;
	cout << "从队尾到队首为:" << endl;
	while (length--) {
		cout << base[head + length] << endl;
	}
	cout << endl;
}
template<typename T>
int CirQueue<T>::getlength() {
	// 取循环队列的长度主要依靠head和tail之间的距离,如果
	return (tail - head+size)%size;
}
template<typename T>
bool CirQueue<T>::EnQueue(T val) {
	if ((tail + 1) % size == head) {
		cout << "队列已满" << endl;
		return false;
	}
	else {
		base[tail] = val;
		tail = (tail + 1) % size;
		return true;
	}
}
template<typename T>
T CirQueue<T>::DeQueue() {
	if (head == tail) {
		return false;
	}// head往后移,不用删除前面的元素，因为是循环队列所以之后会回来
	T data = base[head];
	head = (head + 1) % size;
	return data;
}
