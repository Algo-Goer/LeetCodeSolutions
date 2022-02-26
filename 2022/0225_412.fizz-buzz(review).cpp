/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> res;
        for (int i = 1; i <= n; i++)   // 下标从1开始
        {
            string current;
            if (i % 3 == 0)
                current += "Fizz";
            if (i % 5 == 0) // 不可以写else if
                current += "Buzz";
            if (current.empty())
                current = to_string(i);
            res.emplace_back(current);
        }
        return res;
    }
};
/*
C++开发中我们会经常用到插入操作对stl的各种容器进行操作，比如vector,map,set等。在引入右值引用，转移构造函数，转移复制运算符之前，通常使用push_back()向容器中加入一个右值元素(临时对象)时，首先会调用构造函数构造这个临时对象，然后需要调用拷贝构造函数将这个临时对象放入容器中。原来的临时变量释放。这样造成的问题就是临时变量申请资源的浪费。 
引入了右值引用，转移构造函数后，push_back()右值时就会调用构造函数和转移构造函数,如果可以在插入的时候直接构造，就只需要构造一次即可。这就是c++11 新加的emplace_back。
*/
// @lc code=end

