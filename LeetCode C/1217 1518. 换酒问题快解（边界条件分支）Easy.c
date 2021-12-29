/*
 * @lc app=leetcode.cn id=1518 lang=c
 * 12.17 Fri.
 * [1518] 换酒问题
 * 快解：
 * 每交换一次少(numExchange-1)个瓶子
 * 边界条件：
 * 如果numBottles/(numExchange-1)为0，那么最后一次要减去
 */

// @lc code=start

int numWaterBottles(int numBottles, int numExchange)
{
   int MaxExchange = numBottles / (numExchange - 1); // 最大可兑换次数
        if (numBottles % (numExchange - 1) == 0)
            return numBottles + numBottles / (numExchange - 1) - 1;
        else
            return numBottles + numBottles / (numExchange - 1);
    
}
