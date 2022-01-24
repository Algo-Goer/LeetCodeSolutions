#
# @lc app=leetcode.cn id=155 lang=python3
#
# [155] 最小栈
#

# @lc code=start

"""
复习Stack的class定义
另外此题要求在O(1)内找到最小元素：可以用第二个栈作为辅助，并且保持栈顶top为最小值
时间复杂度O(1)，空间复杂度O(n)
"""
class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []


    def push(self, val: int) -> None:
        self.stack.append(val)
        if len(self.min_stack) == 0 or val <=self.min_stack[-1]:
            self.min_stack.append(val)


    def pop(self) -> None:
        x = self.stack.pop()
        if x == self.min_stack[-1]: # [-1]代表最后一个元素，即栈顶元素
            self.min_stack.pop()


    def top(self) -> int:
        return self.stack[-1]
       


    def getMin(self) -> int:
        return self.min_stack[-1]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

