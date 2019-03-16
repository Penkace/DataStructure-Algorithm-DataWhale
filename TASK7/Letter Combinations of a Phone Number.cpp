/****************************
这道题以前做过，主要的思想是dfs+回溯，可以通过树来方便理解；
此外，可以新建一个枚举表来减少代码的判断。
****************************/

class Solution {
public:
    vector<string>res;
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits=="")
            return res;
        
        findCombination(digits,0,"");
        return res;
    }
    void findCombination(const string &digits,int index,const string &s){
        if(index ==digits.size()){
            res.push_back(s);
            return;
        }
        char c=digits[index];
        assert(c>='0'&&c<='9'&&c!='1');
        string letters = letterMap[c-'0'];
        for(int i=0;i<letters.size();i++){
            findCombination(digits,index+1,s+letters[i]);
        }
        return;
    }
    const string letterMap[10]={
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
};
