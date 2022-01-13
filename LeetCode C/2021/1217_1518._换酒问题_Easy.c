
int numWaterBottles(int numBottles, int numExchange)
{
    int ans = numBottles;
    while (numBottles >= numExchange) // 空瓶子大于等于兑换数时
    {
        int new = numBottles / numExchange; // 新兑换的数量
        ans += new;
        numBottles = numBottles % numExchange + new;  // 余数+新兑换的
    }
   
    return ans;
}

