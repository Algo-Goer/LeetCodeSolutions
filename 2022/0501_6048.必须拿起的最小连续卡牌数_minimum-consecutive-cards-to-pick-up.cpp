/*
找第二个相同的数字的下标
*/
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        // greedy
        unordered_map<int, int> m;
        int result = INT_MAX;
        for (int i = 0; i < cards.size(); ++i)
        {
            if (m.count(cards[i])) // count()返回值为0或1
            {
                result = min(result, i - m[cards[i]] + 1);
            }
            m[cards[i]] = i;
        }
        return result == INT_MAX ? -1 : result;
    }
};