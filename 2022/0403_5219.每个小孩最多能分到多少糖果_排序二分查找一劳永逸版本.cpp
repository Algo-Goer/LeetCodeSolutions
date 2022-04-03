class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        long n = candies.size();
        long ans = 0;
        /*
        要二分查找必然要先排序好吗？不是的，我发现把这句sort()删了也可以AC，而且详见举例，不排序也可以得出正确结果。
        粗想想，可能是因为反正每个人分到的数量都得一样吧，所以不排序最终也可以夹逼定理一般得到那个唯一解
        sort(candies.begin(), candies.end());
        */
        // 统计糖果总数
        long sum = 0;
        for (auto candy : candies)
            sum += candy;
        /* special cases不必分析咯
        if (sum / k == 0)
            return 0; // 一开始就可以写好啦，因为和后面二分查找不是顺路的
        else if (sum / k == 1)
            return 1;
        */
        long l = 0, r = sum / k, mid = 0;
        while (l != r)
        {
            mid = (l + r + 1) / 2;
            long count = 0; // 堆数
            for (auto candy : candies)
            {
                count += candy / mid; // 中等难度点在于此，多了这一步，思维链接之处
            }
            if (count < k) // 关键的二者关系
                r = mid - 1;
            else
                l = mid;
        }
        return l;
    }
};
/*
举例
candies=[4,7,5], k=4
sum=16 r=16/3=5
l=0, r=5, mid=3, count=4/3+7/3+5/3=1+2+1=4=k, l=mid=3
l=3, r=5, mid=4, count=4/4+7/4+5/4=1+1+1=3<4=k, r=mid-1=3
l=3, r=3  不进入while循环
return l=3
*/