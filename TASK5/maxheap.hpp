/***************************************************************************
	References: https://blog.csdn.net/jkay_wong/article/details/6877446
***************************************************************************/
#include <iostream>
using namespace std;

template <class T>
class MaxHeap
{
private:
	T * heap;
	int CurSize;
	int MaxSize;
public:
	MaxHeap(int maxsize = 10)
	{
		MaxSize = maxsize;
		CurSize = 0;
		heap = new T[MaxSize + 1];
	}

	~MaxHeap()
	{
		delete[]heap;
	}

	int Get_Size() const
	{
		return CurSize;
	}

	T Get_Max()
	{
		if (CurSize == 0)
		{
			cout << "堆为空" << endl;
			return -9999;
		}
		else
		{
			return heap[1];
		}
	}

	MaxHeap<T> &Insert(const T& x)
	{
		if (CurSize == MaxSize)
		{
			cout << "堆满，" << x << " 插入失败" << endl;
			return *this;
		}
		//为x寻找应插入位置
		//i从新的叶子结点开始，沿着树向上
		int i = ++CurSize;
		while (i != 1 && x>heap[i / 2])
		{
			heap[i] = heap[i / 2]; //将元素下移
			i /= 2; //移向父节点
		}

		heap[i] = x;
		cout << x << " 插入成功" << endl;
		return *this;
	}

	MaxHeap<T> &DeleteMax(T& x)
	{
		//将最大元素放入x，并从堆中删除它
		if (CurSize == 0)
		{
			x = -9999;
			return *this;
		}

		x = heap[1];

		//重构堆
		heap[0] = heap[CurSize--]; //0号位置存放最后一个元素值，然后将该位置删除

								   //从根开始，为heap[0]寻找合适位置
		int i = 1;
		int ci = 2;

		while (ci <= CurSize)
		{
			//ci是较大的孩子的位置
			if (ci<CurSize && heap[ci]<heap[ci + 1])
				ci++;

			//判断是否可以放入heap[i]位置
			if (heap[0]>heap[ci])
				break;

			//不能
			heap[i] = heap[ci];
			i = ci; // 下移一层
			ci *= 2;
		}

		heap[i] = heap[0];
		return *this;
	}

	void Init_heap(T a[], int size, int maxsize)
	{
		delete[]heap;
		heap = new T[maxsize + 1];
		CurSize = size;
		MaxSize = maxsize;

		for (int j = 1; j<size + 1; j++)
			heap[j] = a[j];

		//产生一个最大堆
		for (int i = CurSize / 2; i >= 1; i--)
		{
			T y = heap[i]; //子树的根

						   //寻找放置y的位置
			int c = 2 * i;
			while (c <= CurSize)
			{
				if (c<CurSize && heap[c]<heap[c + 1])
					c++;

				if (y >= heap[c])
					break;

				heap[c / 2] = heap[c];
				c *= 2;
			}
			heap[c / 2] = y;
		}
	}
};
