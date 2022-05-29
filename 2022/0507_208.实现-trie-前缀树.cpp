/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie
{
private:
    struct TrieNode
    {
        bool isEnd;
        vector<shared_ptr<TrieNode>> children;
        TrieNode() : isEnd(false), children(26, NULL) {}
    };

    shared_ptr<TrieNode> findPrefix(string &prefix) // 没有&也可以AC
    {
        auto node = root;
        for (int i = 0; i < prefix.size() && node != NULL; ++i) // node != NULL表示前缀树中还有剩余节点
        {
            node = node->children[prefix[i] - 'a']; // prefix[i]-'a'表示字符串的第i个字符的ASCII码减去'a'的值
        }
        return node; // 若是前缀就返回最后一个字母所在的node，否则返回NULL
    }

    shared_ptr<TrieNode> root;

public:
    Trie()
    {
        root = make_shared<TrieNode>(); // make_shared创建一个shared_ptr智能指针，指向一个TrieNode对象
    }

    void insert(string word)
    {
        auto node = root; // node指向root
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->children[word[i] - 'a'] == NULL)                   // 若node的children[word[i] - 'a']为空，则创建一个新的TrieNode对象
                node->children[word[i] - 'a'] = make_shared<TrieNode>(); // make_shared创建一个shared_ptr智能指针，指向一个TrieNode对象
            node = node->children[word[i] - 'a'];                        // 进入到对应子树节点中
        }
        node->isEnd = true; // 整个单词遍历结束，将最后一个节点标记为单词结尾
    }

    bool search(string word)
    {
        auto node = findPrefix(word);
        return node != NULL && node->isEnd; // 若node不为空且node的isEnd为true，则返回true，否则返回false
    }

    bool startsWith(string prefix)
    {
        return findPrefix(prefix) != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
