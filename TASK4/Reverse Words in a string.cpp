/***********************************
解决这道题的方法有很多，比如一开始就翻转字符串再翻转每一个单词
或者用stack存储每一个单词最后再输出
其实string类可以用push_back等方法
***********************************/
class Solution {
public:
    string reverseWords(string s) {
        int l = s.size();
        // 存储最后结果的字符串
        string res;
        // 从后往前遍历字符串
        for(int i=l-1;i>=0;){
            //找到非空时的下标
            while(i>=0&&s[i]==' '){
                i--;
            }
            // 要判断是否越界
            if(i<0) break;
            // 如果字符串不为空，就要用空格分隔单词
            if(!res.empty())
                res.push_back(' ');
            // tmp存储即将加入的单词
            string tmp;
            // 记录此时的起点
            int j=i;
            for(;j>=0&&s[j]!=' ';j--){
                tmp.push_back(s[j]);
            }
            // 字符串的reverse函数没有返回值，直接传入指针进行翻转
            reverse(tmp.begin(),tmp.end());
            res.append(tmp);
            // 再次遍历字符串应该从已加入单词的前一个位置开始
            i=j--;
        }
        return res;
    }
};
