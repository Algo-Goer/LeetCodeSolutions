/*
转化时间需要的最少操作数
给你两个字符串current和correct表示两个24小时制时间
24小时制时间按"HH:MM"进行格式化，其中HH在00和23之间，而MM在00和59之间
最早的24小时制时间为00:00
最晚的是23:59
在一步操作中
你可以将current这个时间增加1、5、15或60分钟。你可以执行这一操作任意次数
返回将current转化为correct需要的最少操作数
*/
class Solution
{
public:
    int convertTime(string current, string correct)
    {
        int c_hour = stoi(current.substr(0, 2));
        int c_min = stoi(current.substr(3, 2));
        int c_total = c_hour * 60 + c_min; // 150 // 11:00 -> 11 * 60 + 0 = 660
        int tmp2;
        int correct_hour = stoi(correct.substr(0, 2));
        int correct_min = stoi(correct.substr(3, 2));
        int correct_total = correct_hour * 60 + correct_min; // 275 // 11:01 -> 661
        int ans = 0;
        int tmp = correct_total - c_total; // 275 - 150 = 125, 125/60=2, 125%(60*2)=5 // 661-660=1, 1/60=0, 1%(60*0)=1
        int tmp1 = tmp / 60;
        if (tmp1 > 0)
        {
            tmp2 = tmp % (60 * tmp1);
        }
        else if (tmp1 == 0)
        {
            tmp2 = tmp;
        }
        while (tmp1 > 0)
        {
            ans++;
            tmp1--;
        }
        while (tmp2 > 0)
        {
            if (tmp2 % 15 == 0)
            {
                ans++;
                tmp2 -= 15;
            }
            else if (tmp2 % 15 != 0 && tmp2 % 5 == 0)
            {
                ans++;
                tmp2 -= 5;
            }
            else if (tmp2 % 15 != 0 && tmp2 % 5 != 0)
            {
                ans++;
                tmp2 -= 1;
            }
        }
        return ans;
    }
};