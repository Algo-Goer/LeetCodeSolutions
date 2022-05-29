/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
// code3 Trie写法2 insert search
class Trie
{
private:
    struct TrieNode
    {
        bool isEnd;
        vector<shared_ptr<TrieNode>> children; // 智能指针：由于Trie是动态数据结构，在插入新字符串时需要不断在堆上开辟空间，为了避免内存泄漏，需要在Trie树的析构函数中释放这些内存，可以用智能指针进行管理
        TrieNode() : isEnd(false), children(26, NULL) {} // 初始化26个空节点
    };

    shared_ptr<TrieNode> findPrefix(string prefix)
    {
        shared_ptr<TrieNode> node = root;
        for (int i = 0; i < prefix.size() && node != NULL; ++i) // node != NULL表示前缀树中还有剩余节点
        {
            node = node->children[prefix[i] - 'a']; // prefix[i] - 'a'表示字符串的第i个字符的ASCII减去'a'的ASCII
        }
        return node; // 若是前缀就返回最后一个字母所在的node，否则返回NULL
    }

    shared_ptr<TrieNode> root; // 不可少，否则出错

public:
    Trie()
    {
        root = make_shared<TrieNode>(); // make_shared创建一个shared_ptr智能指针，指向一个TrieNode对象
    }

    void insert(string word)
    {
        shared_ptr<TrieNode> node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->children[word[i] - 'a'] == NULL) // 如果没有这个字符，则创建一个新的TrieNode对象
            {
                node->children[word[i] - 'a'] = make_shared<TrieNode>();
            }
            node = node->children[word[i] - 'a']; // 进入到对应子节点
        }
        node->isEnd = true; // 整个单词遍历结束，将最后一个节点标记为单词结尾
    }

    bool search(string word)
    {
        shared_ptr<TrieNode> node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->children[word[i] - 'a'] == NULL || node->children[word[i] - 'a']->isEnd == false) // 后面一句是[208]没有的
            {
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        return node->isEnd; // 写成return true;也可以AC
    }
};
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        // 创建一个字典树
        Trie trie;
        for (const string &word : words)
        {
            trie.insert(word);
        }
        string ans = "";
        for (const string &word : words)
        {
            if (trie.search(word))
            {
                if (word.size() > ans.size() || (word.size() == ans.size() && word < ans))
                    ans = word;
            }
        }
        return ans;
    }
};
// @lc code=end
