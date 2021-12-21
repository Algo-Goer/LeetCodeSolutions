**1154. 一年中的第几天**<br>

给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。


示例 1：

输入：date = "2019-01-09"

输出：9

示例 2：

输入：date = "2019-02-10"

输出：41

示例 3：

输入：date = "2003-03-01"

输出：60

示例 4：

输入：date = "2004-03-01"

输出：61
 
提示：
- date.length == 10<br>
- date[4] == date[7] == '-'，其他的 date[i] 都是数字
- date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日

<br>


**思路**
<br>
- 闰年29天
  - 2000年那种闰年，能除尽400
  - 2004年那种闰年，能除尽4
- 声明中指针为char类型，要atoi()转换为int才可以计算
- "%04d-%02d-%02d"是时间表达的方式，昨天刷PTA的时候学到了


<br>

```c
int dayOfYear(char * date)  // char为指向字符串的指针，字符串转换为int用atoi()
{
    int year = atoi(date);
    int month = atoi(date + 5);
    int day = atoi(date + 8);
    int sumDay = 0;
    int ans = 0;
    scanf("%04d-%02d-%02d", &year, &month, &day);
    int ar[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < month; i++)
    {
        sumDay += ar[i];
    }
    ans += day + sumDay;
    if (year % 400 == 0 && year % 100 == 0 && month > 2)   // 闰年，2000年那种
    {
        ans += 1;
    }
    if (year % 100 != 0 && year % 4 == 0 && month > 2) // 闰年，2004年那种
    {
        ans += 1;
    } 
    return ans;
}
```

时间复杂度：O(1)<br>
空间复杂度：O(1)