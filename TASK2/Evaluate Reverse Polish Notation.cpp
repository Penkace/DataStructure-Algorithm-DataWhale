class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // stoi将字符串转换成整数
        if (tokens.size() == 1) return stoi(tokens[0]);
        // 建立存储数字的栈。这道题实际上是后缀表达式
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } else {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            }
        }
        return st.top();
    }
};
