template<class T>
class LinkQueue {
private:
	struct QNode {
		T data;
		QNode *next;
	};
	QNode *head;
	QNode *rear;
public:
	LinkQueue();
	~LinkQueue(void);
	void clear();
	bool isEmpty();
	int size();
	T gethead();// 得到队头元素
	void EnQueue(T val);
	T DeQueue();//  删除队头元素
};

template<class T>
LinkQueue<T>::LinkQueue() {
	this->head = nullptr;// NULL 的话会报错
	this->rear = nullptr;
}

template<class T>
LinkQueue<T>::~LinkQueue(void) {
	this->clear();
}

template<class T>
void LinkQueue<T>::clear() {
	QNode *temp;
	while (head != nullptr) {
		temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
	this->head = nullptr;
	this->rear = nullptr;
}

template<class T>
int LinkQueue<T>::size() {
	int count = 0;
	QNode *cnt = this->head;
	while (cnt != rear) {
		count++;
		cnt = cnt->next;
	}
	return count + 1;
}

template<class T>
bool LinkQueue<T>::isEmpty() {
	return this->head == nullptr;
}

template<class T>
T LinkQueue<T>::gethead() {
	return this->head->data;
}

template<class T>
void LinkQueue<T>::EnQueue(T val) {
	QNode *temp = new QNode;
	temp->data = val;
	temp->next = nullptr;
	if (head == nullptr) {
		head = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = rear->next;
	}
}
	

template<class T>
T LinkQueue<T>::DeQueue() {
	QNode *temp;
	T val;
	if (head == nullptr) {
		return 0;
	}
	else {
		temp = this->head;
		this->head = this->head->first->next;
		val = temp->data;
		delete temp;
		return val;
	}
}
