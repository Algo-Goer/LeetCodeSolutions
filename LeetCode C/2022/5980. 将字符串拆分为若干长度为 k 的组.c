/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** divideString(char * s, int k, char fill, int* returnSize)
{
    int len = strlen(s);
    int group = (len - 1) / k + 1;    // 有几组,-1是因为减掉空字符
    char *ans = (char *)malloc(sizeof(char) * (group + 1));
    * returnSize = group + 1;
    int index = 0;  // ans数组中的指针
    for (int i = 0; i < k; i++)  // i是数组s中的指针
    {
        ans[index++] = s[i++];
    }
}