class Solution
{
public:
    int convertTime(string current, string correct)
    {
        int a = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int b = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int ans = 0;
        while (b - a >= 60)
            a += 60, ans++;
        while (b - a >= 15)
            a += 15, ans++;
        while (b - a >= 5)
            a += 5, ans++;
        return ans + b - a;
    }
};