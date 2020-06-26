/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */
class Solution {
public:
    int dayOfYear(string date) {
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = std::stoi(date.substr(0,4));
        int month = std::stoi(date.substr(5,2));
        int day = std::stoi(date.substr(8,2));
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            days[1] += 1;
        }
        int res = 0;
        for (int  i = 0; i < month - 1; i++)
        {
            res += days[i];
        }
        res += day;
        return res;
        
        
    }
};

