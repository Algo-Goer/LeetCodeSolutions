/*
 * @lc app=leetcode.cn id=1518 lang=c
 * 12.17 Fri.
 * [1518] ��������
 * ���⣺
 * ÿ����һ����(numExchange-1)��ƿ��
 * ����Ҫ���Ǳ߽�������
 * (numBottles-1)/(numExchange-1)+numBottles
 */

// @lc code=start

int numWaterBottles(int numBottles, int numExchange)
{
    return (numBottles-1)/(numExchange-1) + numBottles;
}
