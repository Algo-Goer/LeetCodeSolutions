/*
 * @lc app=leetcode.cn id=151 lang=c
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start

/*
 * 双指针，都从右往左遍历字符串数组
 * start指针先找第一个非空字符
 * end指针固定该非空字符后，就找到了单词最后一个字母，固定该位置不动
 * start指针继续往前移动到单词首字母之前一格
 * current指针找到start指针后面一格
 * current指针到end指针区间即字母
 * index指针是新数组ans里的指针，从0开始向后移动
 * 每次加入单词后跳出循环后，加入一个空格' '
 * 在返回字符串数组末尾去掉空格并加上'\0'
 */

char *reverseWords(char *s)
{
    int len = strlen(s);
    char *ans = (char *)malloc(sizeof(char) * (len + 1));
    int start = len - 1; // 从右向左开始遍历
    int end = len - 1;   // 从右向左开始遍历
    int current = 0;     // 目前指针的位置
    int index = 0;       // 索引记录
    // start指针从右向左遍历，最左边为0，最右边为len - 1
    while (start >= 0)
    {
        if (s[start] == ' ')
        {
            start--; // 从右向左遍历，遇到空格指针就继续往左移动一格
        }
        else // 从右向左遍历，遇到非空
        {
            end = start; // end指针赶紧来固定pin单词末尾的非空字母
            while (start >= 0 && s[start] != ' ')
            {
                start--; // start指针继续往前移动到该单词第一个字母之前一格（空格）
            }
            current = start + 1;   // current指针移动到该单词的第一个字母
            while (current <= end) // 开始遍历这个单词
            {
                /* 
                 * 把current到end俩指针区间（含）之间指向的单词从前往后拷贝到新数组ans中
                 * index为数组ans的指针，从0开始往后移动
                 */

                /*
                 * 对于a[i++]和a[++i]:
                 * i++是先使用i现在的值，再给i加1
                 * ++i是先给i加1，再用加1后的值
                 */
                ans[index++] = s[current++];
            }
            // ans[index + 1]出现blueisskyth(?)
            ans[index++] = ' '; // 每个单词加入后再加一个空格' '，然后index指针移动到下一位
        }
    }
    /*
    * 不考虑'\0'就会出现“执行出错”：
    * 在字符串数组的末尾加上'\0'表示字符串结束. 如果没有这个\0,那么在使用系统函数处理这个字符串的时候,函数就不能准确判断字符串在哪里结束.从而导致数组越界
    * 由于s中至少存在一个单词，所以index一定大于0
    */

    /*
     * 在ans[index++]中index已经赋值' '后又加了1，移动到下一位，等待被赋值
     * 替换掉最后的' '为'\0'
     */
    ans[index - 1] = '\0';  // 不是index，是index-1，回退到index上一位
    return ans;
}
// @lc code=end
