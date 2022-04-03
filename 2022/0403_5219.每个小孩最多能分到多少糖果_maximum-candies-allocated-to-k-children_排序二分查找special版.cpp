/*
5219. 每个小孩最多能分到多少糖果
给你一个下标从0开始的整数数组candies数组中的每个元素表示大小为candies[i]的一堆糖果
你可以将每堆糖果分成任意数量的子堆
但无法再将两堆合并到一起

另给你一个整数k
你需要将这些糖果分配给k个小孩
使每个小孩分到相同数量的糖果

每个小孩可以拿走至多一堆糖果
有些糖果可能会不被分配

返回每个小孩可以拿走的最大糖果数目
*/

// sort & binary search
// code2 sort & binary search (once for all) 一劳永逸版

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        long n = candies.size();
        long ans = 0;
        // 统计糖果总数
        long sum = 0;
        for (auto candy : candies)
            sum += candy;
        if (sum / k == 0)
            return 0; // 一开始就可以写好啦，因为和后面二分查找不是顺路的
        else if (sum / k == 1)
            return 1;
        long l = 0, r = sum / k, mid = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            long count = 0; // 堆数
            for (auto candy : candies)
            {
                count += candy / mid; // 中等难度点在于此，多了这一步，思维链接之处
            }
            if (count < k) // 关键的二者关系
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l - 1;
    }
};
/*
举例
candies=[5,8,6], k=3
sum=19 r=19/3=6
l=0, r=6, mid=3, count=3=k, l=mid+1=4
l=4, r=6, mid=5, count=3=k, l=mid+1=6
l=6, r=6, mid=6, count=2<k, r=mid-1=5
l=6, r=5 不进入while循环
return l-1=5

candies=[2,5], k=11
sum=7 r=7/11=0, 直接返回0，这个可以最前面就写好啦，不然照下面二分查找走下来输出-1就报错了

candies=[4,7,5], k=4
sum=16 r=16/3=5
l=0, r=5, mid=2, count=4/2+7/2+5/2=2+3+2=7>4=k, l=mid+1=3
l=3, r=5, mid=4, count=4/4+7/4+5/4=1+1+1=3<4=k, r=mid-1=3
l=3, r=3, mid=3, count=4/3+7/3+5/3=1+2+1=4=k, l=mid+1=4
l=4, r=3 不进入while循环
return l-1=3

candies=[4,7,5], k=16
sum=16 r=16/16=1
l=0, r=1, mid=0, 这个时候就会出现分母为0的错误
所以可以也写在前面，直接返回1
不过一会看看其他题解，有没有一劳永逸版写法——不考虑到这些特殊情况也能AC的代码
*/
