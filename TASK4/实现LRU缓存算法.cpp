/*****************************************
  References: https://blog.csdn.net/z702143700/article/details/48374201
*****************************************/

#include<iostream>
#include<queue>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache {
	struct Node {
		int key;
		int value;
		Node(int k, int v) :key(k), value(v) {}
	};
private:
	int capacity;
	list<Node> cacheList;// 内存页
	unordered_map<int, list<Node>::iterator> cacheMap;// 利用哈希表存储

public:
	LRUCache(int c) :capacity(c) {};
	// 先判断hash中是否存在，如果不存在，发生缺页终端
	int find(int key) {
		// 判断的元素是否存在
		if (cacheMap.find(key) == cacheMap.end())
			return -1;
		// 如果存在，则在cacheList的头部插入元素
		cacheList.splice(cacheList.begin(), cacheList,cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	void set(int key, int value) {
		if (cacheMap.find(key) == cacheMap.end()) {
			// 如果没有找到key，先判断List是否为满，满就淘汰最后一个
			if (cacheList.size() == capacity) {
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			// 没满就放入首部
			cacheList.push_front(Node(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else {
			// 
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
};
