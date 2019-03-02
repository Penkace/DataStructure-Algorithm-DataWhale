class Solution {
public:
    bool isValid(string s) {
        // 括号匹配用栈实现
        stack<char>record;
        for(int i=0;i<s.length();i++){
            // 括号的左边进栈，当有右边括号时再出栈
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                record.push(s[i]);
            }
            else
            {
                // 遇到右边括号，如果栈为空，说明没有左括号，返回false
                if(record.size()==0) return false;
                // 如果有则得到栈顶元素，再判断当前s[i]括号与那种类型的括号是匹的
                char c=record.top();
                record.pop();
                char match;
                if(s[i]==')')
                    match='(';
                else if(s[i]==']')
                    match='[';
                else{
                    assert(s[i]=='}');
                    match='{';
                }
                // 判断得到的两种括号是否一致
                if(c!=match) return false;
            }
        }
        
    if(record.size()==0) return true;
    else return false;
    }
};
