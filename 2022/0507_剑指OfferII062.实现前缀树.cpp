// 学习了@我要出去乱说的代码
class Trie {
private:
    struct TrieNode // 26叉树结构体，每一棵子树也是一棵26叉树
    {
        bool isEnd;
        vector<shared_ptr<TrieNode>> children; /// shared_ptr智能指针，防止内存泄漏，指针在返回后会自动释放内存，智能指针的头文件在<memory>中
        TrieNode(): isEnd(false), children(26, nullptr){} // 成员列表初始化
    };

    shared_ptr<TrieNode> findPrefix(string &prefix) // 查找前缀
    {
        auto node = root;
        for (int i = 0; i < prefix.size() && node != NULL; ++i)
        {
            node = node->children[prefix[i] - 'a']; // prefix[i] - 'a'表示字符串的第i个字符的ASCII码减去'a'的值
        }
        return node; // 若是前缀就返回最后一个字母所在的node，否则返回NULL
    }

    shared_ptr<TrieNode> root;

public:
    Trie() {
        root = make_shared<TrieNode>(); // make_shared创建一个shared_ptr智能指针，指向一个TrieNode对象
    }
    
    // 往前缀树中插入单词
    void insert(string word) {
        auto node = root; // node为当前节点，从头节点开始
        for (auto &ch : word) // 遍历每个字母，若字母对应的结点不存在，则创建它
        {
            if (node->children[ch - 'a'] == NULL)
            {
                node->children[ch - 'a'] = make_shared<TrieNode>();
            }

            node = node->children[ch - 'a']; // 进入到对应子树节点中
        }

        node->isEnd = true; // 整个单词遍历结束，将最后一个节点标记为单词结尾
    }
    
    // 前缀树中查找单词
    bool search(string word) {
        auto node = findPrefix(word);
        return node != NULL && node->isEnd == true; // 若找到了前缀，且最后一个字符是单词结尾，则返回true
    }
    
    // 前缀树中查找前缀
    bool startsWith(string prefix) {
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
