/*
 * @lc app=leetcode.cn id=1518 lang=c
 * 12.17 Fri.
 * [1518] ��������
 * ��⣺
 * ÿ����һ����(numExchange-1)��ƿ��
 * �߽�������
 * ���numBottles/(numExchange-1)Ϊ0����ô���һ��Ҫ��ȥ
 */

// @lc code=start

int numWaterBottles(int numBottles, int numExchange)
{
   int MaxExchange = numBottles / (numExchange - 1); // ���ɶһ�����
        if (numBottles % (numExchange - 1) == 0)
            return numBottles + numBottles / (numExchange - 1) - 1;
        else
            return numBottles + numBottles / (numExchange - 1);
    
}
