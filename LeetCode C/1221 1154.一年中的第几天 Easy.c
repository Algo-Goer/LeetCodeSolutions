
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

