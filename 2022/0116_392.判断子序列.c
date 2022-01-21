/*
 * @lc app=leetcode.cn id=392 lang=c
 *
 * [392] 判断子序列
 */

// @lc code=start

/*
 * 双指针里的快慢指针，时间复杂度为O(m+n)，m和n分别为两序列的规模数。空间复杂度为O(1)
 * 初始俩指针均指向0，分别都往后移动；如果都指向同一字母，就继续同时往后移动一格；若指向不同，则s中指针不动，继续移动t中指针
 * 反正无论如何，t中指针都一直在移动
 * 若s中指针（慢指针）也移动到末尾了（字符串数组末尾是'\0'），说明s中所有字母是t中的子序列，则返回true；反之false

 */

bool isSubsequence(char *s, char *t)
{
    int lenS = strlen(s);
    int lenT = strlen(t);
    int i = 0;                   // 数组s里的指针
    int j = 0;                   // 数组t里的指针
    while (i < lenS && j < lenT) // 满足这两个条件就同时进入while循环
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++; // 反正无论如何，t中指针都一直在移动
    }
    /*
     * return s[i] == '\0'; 
     * 这种写法也可
     */
    return i == lenS; // 如果数组s的指针（慢指针）都移动到末尾(含字符串数组的'\0')了，说明s序列在t中都能找到不一定连续的子序列
}
// @lc code=end
