/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
// code2 Trie写法1 insert search
class Trie
{
private:
    Trie *children[26];
    bool isEnd;

public:
    Trie()
    {
        this->isEnd = false;
        for (int i = 0; i < 26; ++i)
        {
            this->children[i] = NULL;
        }
    }
    void insert(string word)
    {
        Trie *node = this; // 当前节点
        for (const char &s : word)
        {
            int index = s - 'a';               // 字符转换为数字
            if (node->children[index] == NULL) // 如果没有这个字符，就创建一个
            {
                node->children[index] = new Trie(); // 创建新节点
            }
            node = node->children[index]; 
        }
        node->isEnd = true;
    }
    bool search(string word)
    {
        Trie *node = this;
        for (const char &s : word)
        {
            int index = s - 'a';
            if (!node->children[index]->isEnd) // [208]：if (node->children[index] == NULL) 区别在这里，因为本题要在上一个单词基础上加一个字母而来，所以"banana"就排除了
                return false; // word里每个字符必须都是isEnd == true才符合search条件，而[208]不需要
            node = node->children[index]; // 向下一层
        }
        return node != NULL && node->isEnd;
    }
};
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        Trie trie; // 创建一个字典树
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
