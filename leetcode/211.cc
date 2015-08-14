struct TrieNode
{
    TrieNode *ptr[26];
    bool flag;
    TrieNode(): flag(false){
        for (int i = 0; i < 26; i++)
            ptr[i] = nullptr;
    }
};

class WordDictionary {
public:

    TrieNode *root;
    WordDictionary(): root(new TrieNode) {}
    // Adds a word into the data structure.
    void addWord(string word) {
        int n = word.size();
        TrieNode *tp = root;
        for (int i = 0; i < n; i++) {
            int c = word[i] - 'a';
            if (tp->ptr[c] == nullptr) {
                tp->ptr[c] = new TrieNode;
            }
            tp = tp->ptr[c];
        }
        tp->flag = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(word, 0, root);
    }
    bool dfs(string &word, int now, TrieNode *nowp) {
        if (now == word.size() - 1) {
            if (word[now] == '.') {
                for (int i = 0; i < 26; i++) {
                    if (nowp->ptr[i] != nullptr && nowp->ptr[i]->flag == true)
                        return true;
                }
                return false;
            } else if (nowp->ptr[word[now] - 'a'] != nullptr &&
                    nowp->ptr[word[now] - 'a']->flag == true)
                return true;
            return false;
        }
        if (word[now] == '.') {
            for (int i = 0; i < 26; i++)
                if (nowp->ptr[i] != nullptr)
                    if (dfs(word, now + 1, nowp->ptr[i]))
                        return true;
            return false;
        } else {
            if (nowp->ptr[word[now] - 'a'] != nullptr)
                return dfs(word, now + 1, nowp->ptr[word[now] - 'a']);
            else
                return false;
        }
    }
};
