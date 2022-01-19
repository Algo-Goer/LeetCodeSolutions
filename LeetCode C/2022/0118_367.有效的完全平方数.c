/*
 * @lc app=leetcode.cn id=367 lang=c
 *
 * [367] 有效的完全平方数
 */

// @lc code=start

// 经典二分法的变形使用
bool isPerfectSquare(int num)
{
    int low = 1;
    int high = num; // 检验的起始区间为[1, num]
    long long mid;       // 写成int mid;出现runtime error: signed integer overflow。 注意提示：1 <= num <= 2^31 - 1
    // 第704题和第35题的num都在[-10000,10000]以内，没有第367题那么大
    // 写成long也可

    while (low <= high)
    {
        mid = low + (high - low) / 2; //每次先检验区间中点
        if (mid * mid == num)         // 如果中点平方恰好为num，那直接返回true
            return true;
        else if (mid * mid < num) // 如果中点平方小于num，范围就缩小至[mid + 1，high]
            low = mid + 1;
        else if (mid * mid > num) // 反之，范围就缩小至[low, mid - 1]
            high = mid - 1;
    }
    return false;
}

// 经典二分模板
// if (nums[mid] == target)
//             return mid;
//         else if (nums[mid] < target)
//         /*
//          * 本算法搜索区间两端都为闭区间，即[left, right]，
//          * 当发现索引mid并非target时，就去搜索[left, mid - 1]或者[mid + 1, right]
//          * 因为mid已经搜索过了，所以应该从搜索区间中去除
//          */
//             left = mid + 1;
//         else if (nums[mid] > target)
//             right = mid - 1;
// @lc code=end
