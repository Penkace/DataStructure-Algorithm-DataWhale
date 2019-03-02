/********************************************************************************
    References: http://www.cnblogs.com/grandyang/p/4424731.html
                https://zxi.mytechroad.com/blog/stack/leetcode-32-longest-valid-parentheses/
                http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-valid-parentheses.html
    Idea: 因为刚做完括号匹配的题目，所以在做这道题目的时候就有些思维定式，想着把括号字符放进去，参考了上面的链接才意识到这是一道求极值的问题，
          可以直接放入下标，方便计算长度。一般求极值的题目使用dp可解，或者是常规的解法
********************************************************************************/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        int maxn = 0;
        int start = 0;
        // 遍历一遍字符串
        for (int i = 0; i < s.size(); ++i) {
            // 遇到左括号，放入其下标，而不是这个左括号
            if (s[i] == '('){
                stack.push(i);
            } 
            else{
                // 遇到右括号，但是栈为空，因此前面没有匹配的字符串
                if (stack.empty()) 
                    start = i + 1;
                else {
                    // 如果不为空，则判断除了这个
                    stack.pop();
                    // 如果栈顶的左括号出栈之后，判断是否还有左括号在里面，如果没有，说明当前是匹配的，于是比较大小
                    if(stack.empty()){
                        maxn = max(maxn,i-start+1);
                    }
                    else{
                        // 如果还有括号在栈里面，则比较与上一个括号的差距，并且每次都与maxn比较，确保maxn为最大值
                        maxn = max(maxn,i-stack.top());
                    }
                }
            }
        }
        return maxn;
    }
};
