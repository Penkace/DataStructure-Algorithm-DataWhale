/********************************************************************
File: KMP Algorithm
References: https://blog.csdn.net/u011197534/article/details/78385547
Idea: Use dynamic programming to comprehend this problem. The array next records the length that the string can be matched before.
********************************************************************/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void ComputePrefix(string s, int next[]) {
	int n = s.length();
	int q, k;
	next[0] = 0;
	for (k = 0, q = 1; q<n; q++) {
		while (k>0 && s[k] != s[q])
			k = next[k];
		if (s[k] == s[q])
			k++;
		next[q] = k;
	}
}
void KMPMatcher(string text, string pattern) {
	if (pattern == "") return;
	int n = text.length();
	int m = pattern.length();
	int *next = new int[m];
	ComputePrefix(pattern, next);

	for (int i = 0, q = 0; i<n; i++) {
		while (q>0 && pattern[q] != text[i])
			q = next[q];
		if (pattern[q] == text[i])
			q++;
		if (q == m)
		{
			cout << "Pattern occurs with shift " << i - m + 1 << endl;
			q = 0;
		}
	}
}

int main()
{
	string s = "abcdabcdebcd";
	string p = "bcd";
	KMPMatcher(s, p);
	cout << endl;
	system("pause");
	return 0;
}
