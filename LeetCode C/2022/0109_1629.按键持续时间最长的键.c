/*
 * @lc app=leetcode.cn id=1629 lang=c
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start


char slowestKey(int* releaseTimes, int releaseTimesSize, char * keysPressed)
{
    int maxTime = releaseTimes[0];
    char ans = keysPressed[0];
    for (int i = 1; i < releaseTimesSize; i++)
    {
        int time = releaseTimes[i] - releaseTimes[i - 1];
        if (maxTime < time || ((maxTime == time) && (ans < keysPressed[i])))
        {
            maxTime = time;
            ans = keysPressed[i];
        }
    }
    return ans;
}
// @lc code=end

