/*
 * @lc app=leetcode.cn id=5960 lang=c
 *
 * [5960] 将标题首字母大写
 */

// @lc code=start

// 双指针
char *capitalizeTitle(char *title)
{
    int len = strlen(title);
    int j = 0;
    for (int i = 0; i <= len; i++)
    {
        if (title[i] != ' ' && title[i] != '\0')
        {
            title[i] = tolower(title[i]);
        }

        else if (title[i] == ' ' || title[i] == '\0') // title[i] == '\0'不可少，否则输出"Capitalize The title"
        {
            if (i - j > 2)
            {
                title[j] = toupper(title[j]);
                // j = i + 1; 不能写在这里，否则输出"First Letter Of each Word"
            }
            j = i + 1; // j的新的起始位置，无论单词是几个字母，碰到空格或终止符，j都必须移到下一位
        }
    }
    return title;
}
// @lc code=end
