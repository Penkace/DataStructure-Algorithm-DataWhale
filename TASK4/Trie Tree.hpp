/*******
前缀树的头文件. leetcode上也有Trie相关的题目，于是放上去跑，只能通过部分样例
*******/
// 创建结点类
class TrieNode{
public:
    // 存储26个字母的对应下标的结点
    TrieNode* next[26];
    bool isWord;
    TrieNode(){
        memset(next,NULL,sizeof(next));
        isWord = false;
    }
    ~TrieNode(){
        for(int i=0;i<26;i++)
            if(next[i])
                delete next[i];
    }
};

class Trie {
    // 创建一个空的前缀树结点
    TrieNode* root;
public:
    // 初始化前缀树
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        delete root;
    }
    
    // 插入单词
    void insert(string word) {
        TrieNode* tmp = root;
        int l = word.length();
        for(int i=0;i<l;i++){
            // 如果插入的位置为空,就在相应的位置创建新的结点
            if(tmp->next[word[i]-'a'] == NULL)
                tmp->next[word[i]-'a'] = new TrieNode();
            // 创建下一个空间
            tmp = tmp->next[word[i]-'a'];
        }
        // 在单词的结尾设置true
        tmp->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int l = word.length();
        TrieNode* tmp = root;
        for(int i=0;i<l;i++){
            if(tmp->next[word[i]-'a']!=NULL){
                // 指向下一个字母的结点,如果前面有一个结点为空，那么到最后的tmp也是空的，我们得判断tmp是否为空来辨别是否到达单词的尾部
                tmp =tmp->next[word[i]-'a'];
            }
        }
        return tmp && tmp->isWord;
    }
    
    // 前缀匹配
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        int l = prefix.length();
        for(int i=0;i<l;i++){
            if(tmp->next[prefix[i]-'a']!=NULL)
                tmp = tmp->next[prefix[i]-'a'];
        }
        return tmp;
    }
};
