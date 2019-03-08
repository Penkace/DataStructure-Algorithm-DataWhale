/*********************************************
    File: HASH TABLE
    References: https://blog.csdn.net/liujianfeng1984/article/details/47595557

*********************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAX_HASH_ARRAY = 50;
typedef struct _HASH_NODE {
	int key;
	int val;
	struct _HASH_NODE* next;
};
_HASH_NODE * hashtable[MAX_HASH_ARRAY] = { 0 };

// 映射函数,传入一个实数
int hashFunctionForint(int key) {
	int hashKey = key % 97;
	return hashKey;
}

// 映射函数，传入一个字符串
int hashFunctionForstr(char *string) {
	int hashKey = 0;
	int sum = 0;
	for (int i = 0; i < strlen(string); i++) {
		hashKey = (10 * hashKey + string[i]) % 31;
	}
	return hashKey;
}

// 计算哈希表的索引，先计算hashKey，进行取模运算
int hashIndex(int key) {
	int hashKey = hashFunctionForint(key);
	return hashKey % MAX_HASH_ARRAY;
}

// 插入操作，放入到哈希表中
void push(int key, int val) {
	int index = hashIndex(key);
	_HASH_NODE *tmp = (_HASH_NODE*)malloc(sizeof(_HASH_NODE)); // 分配一个_HASH_NODE大小的空间
	if (tmp == NULL) {
		printf("failed to malloc.\r\n");
		return;
	}
	memset(tmp, 0, sizeof(_HASH_NODE));
	tmp->key = key;
	tmp->val = val;
	tmp->next = hashtable[index];
	hashtable[index] = tmp;
}

// 查找操作
int get(int key) {
	int val = 1;
	int index = hashIndex(key);
	_HASH_NODE* tmp = hashtable[index];
	while (tmp) {
		if (tmp->key == key) {
			val = tmp->val;
			break;
		}
		tmp = tmp->next;
	}
	return val;
}

// 返回哈希表的长度
int getlengthhash(_HASH_NODE* head) {
	int count = 0;
	while (head!=nullptr) {
		count++;
		head = head->next;
	}
	return count;
}

// 返回哈希表的值
void showHashTable() {
	int i = 0;
	printf("-- showhashTable --\r\n");
	for (int i = 0; i < MAX_HASH_ARRAY; i++) {
		_HASH_NODE* tmp = hashtable[i];
		int cnt = getlengthhash(tmp);
		if (cnt > 0) {
			cout << "chain" << i << "(" << cnt << ")" << endl;
			while (tmp != NULL) {
				printf(" key %d ,val %d \n", tmp->key, tmp->val);
				tmp = tmp->next;
			}
		}
	}
	printf("-----------------------");
}

int main() {
	push(3, 3);
	push(4, 4);
	push(7, 7);
	push(29, 29);
	push(17, 17);
	showHashTable();
	printf("get key %d, val %d\n", 14, get(14));
	printf("get key %d ,val %d\n", 25, get(25));
	system("pause");
	return 0;
}
