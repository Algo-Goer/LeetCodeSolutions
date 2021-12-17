/*
 * @lc app=leetcode.cn id=1518 lang=c
 * 12.17 Fri.
 * [1518] 换酒问题
 * 最快解：
 * 每交换一次少(numExchange-1)个瓶子
 * 不需要考虑边界条件：
 * (numBottles-1)/(numExchange-1)+numBottles
 */

// @lc code=start

int numWaterBottles(int numBottles, int numExchange)
{
    return (numBottles-1)/(numExchange-1) + numBottles;
}
