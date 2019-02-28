/********************************************
    Reference: https://blog.csdn.net/natsu1211/article/details/9412397
********************************************/
#include "CirlistNode.h"
template<typename Type> class Cirlist {
public:
	Cirlist() :head(new ListNode<Type>()) {
		head->m_pnext = head;
	}
	~Cirlist() {
		MakeEmpty();
		delete head;
	}
public:
	void MakeEmpty();
	int Length();
	ListNode<Type> *Find(int n);
	bool Insert(Type item, int n = 0);
	Type Remove(int n = 0);
	bool RemoveAll(Type item);
	Type Get(int n);
	void Print();
private:
	ListNode<Type>* head;
};
template<typename Type> void Cirlist<Type>::MakeEmpty() {
	ListNode<Type>* pdel = head;
	while (head->m_pnext != head) {
		pdel = head->m_pnext;
		head->m_pnext = pdel->m_pnext;
		delete pdel;
	}
}
template<typename Type> int Cirlist<Type>::Length() {
	ListNode<Type>* pmove = head;
	int count(0);
	while (pmove->m_pnext != head)
	{
		pmove = pmove->m_pnext;
		++count;
	}
		return count;
}
template<typename Type> ListNode<Type>* Cirlist<Type>::Find(int n) {
	if (n<0 || n>Cirlist<Type>::Length())
	{
		cout << "the n is out of boundary!" << endl;
		exit(-1);
	}
	ListNode<Type>* pmove = head->m_pnext;
	for (int i = 0; i < n; i++)
		pmove = pmove->m_pnext;
	cout << "Found!" << endl;
	return pmove;
}
template <typename Type> bool CircularList<Type>::Insert(Type item, int n)
{
	if (n<0 || n>CircularList<Type>::Length())
	{
		cout << "the n is out of boundary!" << endl;
		return false;
	}
	ListNode<Type>* pmove = head;
	for (int i = 0; i<n; i++)
		pmove = pmove->m_pnext;

	ListNode<Type>* newnode = new ListNode<Type>(item);
	if (newnode == NULL)
	{
		cout << "Application error!" << endl;
		return false;
	}
	newnode->m_pnext = pmove->m_pnext;
	pmove->m_pnext = newnode;
	return true;
}

template <typename Type> Type CircularList<Type>::Remove(int n)
{
	if (n<0 || n>CircularList<Type>::Length())
	{
		cout << "the n is out of boundary!" << endl;
		return false;
	}
	ListNode<Type>* pmove = head;
	for (int i = 0; i<n; i++)
	{
		pmove = pmove->m_pnext;
	}
	ListNode<Type>* pdel = pmove->m_pnext;
	Type temp = pdel->m_data;
	pmove->m_pnext = pdel->m_pnext;
	delete pdel;
	return temp;
}

template <typename Type> bool CircularList<Type>::RemoveAll(Type item)
{
	ListNode<Type>* pmove = head;
	ListNode<Type>* pdel = head->m_pnext;
	while (pdel != head)
	{
		if (pdel->m_data == item)
		{
			pmove->m_pnext = pdel->m_pnext;
			cout << "Found and Deleted!" << endl;
			delete pdel;
			pdel = pmove->m_pnext;//主要要重新给pdel赋值，因为前面delete了
			continue;
		}
		pmove = pmove->m_pnext;
		pdel = pdel->m_pnext;
	}
	return true;
}

template <typename Type> Type CircularList<Type>::Get(int n)
{
	if (n<0 || n>CircularList<Type>::Length())
	{
		cout << "the n is out of boundary!" << endl;
		return false;
	}
	ListNode<Type>* pmove = head->m_pnext;
	for (int i = 0; i<n; i++)
		pmove = pmove->m_pnext;

	return pmove->m_data;
}

template <typename Type> void CircularList<Type>::Print()
{
	cout << "head";
	ListNode<Type>* pmove = head->m_pnext;
	while (pmove != head)
	{
		cout << "--->" << pmove->m_data;
		pmove = pmove->m_pnext;
	}
	cout << "--->head" << endl;
}
