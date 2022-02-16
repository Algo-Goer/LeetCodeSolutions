/**
 * @file 0213_6004_得到 0 的操作数.c
 * @author Algo-Goer
 * @brief 
 * @version 0.1
 * @date 2022-02-13
 * 
 * 6004. 得到 0 的操作数 显示英文描述 
 * 给你两个 非负 整数 num1 和 num2 。
 * 每一步 操作 中，如果 num1 >= num2 ，你必须用 num1 减 num2 ；否则，你必须用 num2 减 num1 。
 * 返回使 num1 = 0 或 num2 = 0 的 操作数 。
 */

int countOperations(int num1, int num2)
{
    int count = 0;
    while (num1 != 0 && num2 != 0)
    {
        if (num1 >= num2)
        {
            num1 -= num2;
            count++;
        }
        else
        {
            num2 -= num1;
            count++;
        }
    }
    return count;
}
