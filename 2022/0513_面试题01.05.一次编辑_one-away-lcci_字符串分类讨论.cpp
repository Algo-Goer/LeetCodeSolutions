class Solution 
{
public:
    bool oneEditAway(string first, string second) 
    {
        if (first.size() > second.size()) return oneEditAway(second, first);

        // horse ros
        if (abs((int)first.size() - (int)second.size()) > 1) // 必须加int，否则出现call to abs is ambiguous错误
        // 写成if (fabs(first.size() - second.size()) > 1)也可
            return false;

        if (first.size() == second.size()) // abc adc     abc abd
        {
            int diff = 0;
            for (int i = 0; i < first.size(); ++i)
            {
                if (first[i] != second[i]) 
                    diff++;
                if (diff > 1) 
                    return false;
            }
            return true;
        }
        // ab abc       ab adb   
        // teacher bleacher
        if (first.size() + 1 == second.size())
        {
            int diff = 0;
            for (int i = 0, j = 0; i < first.size(), j < second.size(); ++i, ++j)
            {
                if (first[i] != second[j])
                {
                    diff++;
                    if (diff > 1)   return false;
                    else
                    {
                        --i;
                    }
                }
            }
        }
        return true;
    }
};