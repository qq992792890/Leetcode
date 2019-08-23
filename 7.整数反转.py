#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#
class Solution:
    def reverse(self, x: int) -> int:
        result = 0;
        #有问题的解法，暂时放置
        while x != 0:
            result = result * 10 + x % 10
            x /=10
        if result > 2147483647 or result < -2147483648:
            result = 0
        return result

