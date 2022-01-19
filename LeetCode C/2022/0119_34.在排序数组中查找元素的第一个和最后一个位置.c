/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 * 二分查找(类【367、704、35】)，双指针,malloc()运用
 * 不同于【704】【35】，本题虽然也是升序数组，但是有重复元素
 */

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *ans = malloc(sizeof(int) * 2);
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;

    if (numsSize == 0 || nums[0] > target || nums[numsSize - 1] < target)
    {
        return ans;
    }

    int left = 0;
    int right = numsSize - 1;
    int mid;
    int flag = 0;

    // 同经典二分法
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] == target)
        {
            flag = 1;
            break;
        }
    }

    // 找到一个target后向两边搜索，因为本题有重复元素
    if (flag == 1)
    {
        left = mid;
        right = mid;
        while (left - 1 >= 0 && nums[left] == nums[left - 1])
        {
            left--;
        }
        ans[0] = left;
        while (right + 1 < numsSize && nums[right] == nums[right + 1])
        {
            right++;
        }
        ans[1] = right;
    }
    
    return ans;
}
// @lc code=end
