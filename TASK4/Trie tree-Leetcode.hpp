struct TrieNode {
    TrieNode() {
        memset(mData,0,sizeof(mData);
        mWord = false;
    }
    
    TrieNode *mData[256];
    bool mWord;
};


class Trie {
public:
    
    /** Initialize your data structure here. */
    Trie() {
        mRoot = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *aNode = mRoot;
        int l = word.size();
        for (int i=0;i<l;i++) {
            if (aNode->mData[word[i]-'a'] == 0) {
                aNode->mData[word[i]-'a'] = new TrieNode();
            }
            aNode = aNode->mData[word[i]-'a'];
        }
        aNode->mWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *aNode = mRoot;
        int l = word.size();
        for (int i=0;i<l&& aNode;i++) {
            aNode = aNode->mData[word[i]-'a'];
        }
        return aNode&&aNode->mWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *aNode = mRoot;
        int l = prefix.size();
        for (int i=0;i<l&& aNode;i++) {
            aNode = aNode->mData[prefix[i]-'a'];
        }
        return aNode;
    }
    
    TrieNode *mRoot;
};
