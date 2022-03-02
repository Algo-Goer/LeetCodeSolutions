#
# @lc app=leetcode.cn id=564 lang=python3
#
# [564] 寻找最近的回文数
#

# @lc code=start
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        length = len(n)
        if (length == 1):
            return str(int(n) - 1)
        # 99,999
        if n == '9' * length:
            return str(int(n) + 2)
        # 100,1000
        if n == '1' + '0' * (length - 1):
            return str(int(n) - 1)
        # 101,1001
        if n == '1' + '0' * (length - 2) + '1':
            return str(int(n) - 2)

        # 表示从起点一直取到len(n) + 1 // 2(该点不包括),//表示整除,/表示浮点运算
        half = n[:(len(n) + 1) // 2] # 不要忘记括号,表示从起点一直取到下标为(len(n) + 1) // 2但不包括(len(n) + 1) // 2
        # 123->12 1234->12
        temp = [str(int(half) - 1), half, str(int(half) + 1)]  # 12->11,12,13
        new_palindrome = [i + i[len(n) // 2 - 1::-1] for i in temp]  # 构成新的回文数
        # i[len(n) // 2 - 1::-1] 表示从下标为len(n) // 2 - 1开始取到结束,步长为-1,也就是倒着取
        # 123-> 12 + i[len(n) // 2 - 1::-1] -> 12 + 1 (tmp=12)
        # 1234-> 12 + i[len(n) // 2 - 1::-1] -> 12 + 21 (tmp=12)
        if n in new_palindrome:
            new_palindrome.remove(n)  # 去除自己
        diff = [abs(int(i) - int(n)) for i in new_palindrome]  # 求差值的绝对值
        # diff.index(min(diff))表示求diff中最小值的下标
        return new_palindrome[diff.index(min(diff))]
# @lc code=end
'''
aList=[3,4,5,6,7,9,11,13,15,17]
print(aList[::])  #[3, 4, 5, 6, 7, 9, 11, 13, 15, 17]
print(aList[::-1])  #[17, 15, 13, 11, 9, 7, 6, 5, 4, 3]
#加了负号 就是一个逆向输出
print(aList[::2])  # [3, 5, 7, 11, 15]
#以步长为2进行输出 输出下标依次为0 2 4 6
print(aList[1::2])  #[4, 6, 9, 13, 17],从一开始步长为2
print(aList[3::])  #[6, 7, 9, 11, 13, 15, 17]
print(aList[3:6])  #省略的是步长 而且不包括下标为6的元素   #[6, 7, 9]
'''
