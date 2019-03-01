/***********************************
    Reference: https://blog.csdn.net/natsu1211/article/details/9412397
***********************************/

template<typename T> class Cirlist;
template<typename T> class ListNode {
private:
	Type m_data;
	ListNode *m_pnext;
private:
	friend class CircularList<Type>;
	ListNode() :m_pnext(NULL) {};
	ListNode(const Type item, ListNode<Type> *next = NULL);
	~ListNode() { m_pnext = NULL; }
public:
	Type Getdata()
	{
		return m_data;
	}
};
