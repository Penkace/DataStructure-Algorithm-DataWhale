#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;

// 求前缀表
void prefix_table(char pattern[], int prefix[], int n) {
	// 一开始规定好的
	prefix[0] = 0;
	int len = 0;
	// 检测第i个字母
	int i = 1;
	// 主要讲第一次循环，如果i=1,len=0且pattern[0]!=pattern[1]的时候，当不匹配时我们会侧向选择，即 len = prefix[len-1]
	// 但是在字符串的开头 prefix[len-1]是会越界的，所以应该直接让prefix[i] = len就好，然后继续向前匹配
	while (i < n) {
		if (pattern[i] == pattern[len]) {
			len++;
			prefix[i] = len;
			i++;
		}
		else {
			if (len > 0) {
				len = prefix[len - 1];
			}
			else {
				prefix[i] = len;
				i++;
			}
		}
	}
}
// 前缀表移动
void move_prefix_table(int prefix[], int n) {
	// 生成的前缀表并不是我们想要的前缀表，我们要把前缀表有的向后移动，然后prefix[0]=-1
	for (int i = n-1; i>0; i--) {
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;
}

// KMP算法
void kmp_search(char text[], char pattern[]) {
	int n = strlen(pattern);
   	int* prefix = new int[n];
	prefix_table(pattern,prefix, n);
	move_prefix_table(prefix, n);
	int j = 0;
	int i = 0;
	int m = strlen(text);
	// 做好前期各个变量的准备，主要是text,pattern的长度以及i,j两个下标
	//text[i]   len(text) = m;
	// pattern[j]  len(pattern) = n;
	// 开始遍历text
	while (i < m) {
		// 如果j到了pattern的尽头且最后一位也匹配了，说明当前位置就是匹配到的字符串
		if (j == n-1 && pattern[j] == text[i]) {
			printf("Find pattern at %d\n", i - j);
			// 为了匹配所有的pattern，设置j = prefix[j]继续匹配
			j = prefix[j];
		}
		// 如果字符匹配，直接ij向后移动
		if (text[i] == pattern[j]) {
			i++; j++;
		}
		// 如果当前ij下pattern和text不匹配
		else {
			// 则令 j = prefix[j]
			j = prefix[j];
			// 如果这时候在字符串的开头，两者都不匹配的情况，只能将pattern向text的下一位匹配，即i，j各加1
			if (j == -1) {
				i++; j++;
			}
		}
	}
}
int main() {
	char pattern[] = "ABABCABAA";
	char text[] = "ABABABCABAABABABAB";
	kmp_search(text, pattern);	
	/*int prefix[9];
	int n = 9;
	prefix_table(pattern, prefix, n);
	move_prefix_table(prefix, n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", prefix[i]);
	}
	 */
	system("pause");
	return 0;
}
