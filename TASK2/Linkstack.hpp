template<class T>
class LinkStack {
private:
	int NodeNum;// 表示栈的长度
	// Node 包含data ， next指向stack中的下一个元素
	struct Node {
		T data;
		Node *next;
	};
	Node *top;
public:
	LinkStack();
	~LinkStack();
	void push(T data);
	T pop();
	bool isEmpty();
	void clear();
	int size();
	T Stop();
};

template<class T>
LinkStack<T>::LinkStack() {
	// 构造函数，初始化top栈顶和NodeNum长度
	this->NodeNum = 0;
	this->top = NULL;
}

template<class T>
LinkStack<T>::~LinkStack() {
	// 析构函数
	this->clear();
}

template<class T>
int LinkStack<T>::size() {
	// 返回记录长度的NodeNum
	return NodeNum;
}

template<class T>
bool LinkStack<T>::isEmpty() {
	// 判断是否为空，top表示栈顶结点
	return top == NULL;
}

template<class T>
void LinkStack<T>::clear() {
	Node *temp;
	// 清理结点，释放内存
	while (top != NULL) {
		temp = top;
		top = top->next;
		delete temp;
	}
	NodeNum = 0;
	top = NULL;
}

template<class T>
void LinkStack<T>::push(T data) {
	Node *node = new Node;
	node->data = data;
	node->next = NULL;
	if (top == NULL) {
		top = node;
	}
	else {
		node->next = top;
		top = node;
	}
	NodeNum = 0;
}

template<class T>
T LinkStack<T>::pop() {
	Node *temp;
	T tmp;
	if (top == NULL) {
		return 0;
	}
	else {
		// 删除结点并返回值
		temp = top;
		top = top->next;
		tmp = temp->data;
		delete temp;
		NodeNum--;
		return tmp;
	}
}
template<class T>
T LinkStack<T>::Stop() {
	if (top != NULL) {
		return top->data;
	}
		
	else {
		return NULL;
	}
}

