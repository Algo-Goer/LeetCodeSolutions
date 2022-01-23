# @before-stub-for-debug-begin
from python3problem20 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
# 打算用Python算法设计书里的代码试一下
# LeetCode没有：
# from Pythonds.basic import Stack
# 建立class：Stack,并定义基本功能
# C中按题目输出返回是小写false，但是Python中false会报错，必须写成False

class Solution:
    def isValid(self, s: str) -> bool:
        ar = Stack()

        balanced = True
        index = 0

        while index < len(s) and balanced:
            symbol = s[index]
            if symbol in "([{":
                ar.push(symbol) 
            else:
                if ar.isEmpty():   # 要防止出现空列表后还pop，空列表直接返回flase
                    balanced = False 
                else:
                    top = ar.pop()   # 列表非空就把左符号pop出，pop返回刚pop出的元素，并赋值给top
                    if matches(top, symbol) == 0:  # 将top元素与symbol元素匹配
                        balanced = False   # 如果不匹配balanced就为false，否则保持true
            
            index = index + 1
        
        # return ar.isEmpty() and balanced也可以
        if balanced and ar.isEmpty():  # isEmpty():假如A为空的话，返回的值是1 # 两者取交集
            return True
        else:   # if后一定不要忘记写else
            return False

def matches(open, close):  # 写这个匹配函数明显Python比C方便
    opens = "([{"
    closers = ")]}"

    return opens.index(open) == closers.index(close)

class Stack(): 
    def __init__(self):
        self.items = []  #这一段不可少，否则Runtime Error

    def push(self, item):
        self.items.append(item)
        
    def pop(self):
        return self.items.pop()  # pop返回刚才pop出的元素
    
    def isEmpty(self):
        return self.items == []  # 空返回1，反之返回0 

# @lc code=end

