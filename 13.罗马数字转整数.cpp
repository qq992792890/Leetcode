/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
class Solution {
public:
    int romanToInt(string s) {
        if (s.empty())
        {
            return 0;
        }
        
        int result = 0;
        switch (s.back())
        {
        case 'I': result += 1; break;
        case 'V': result += 5; break;
        case 'X': result += 10; break;
        case 'L': result += 50; break;
        case 'C': result += 100; break;
        case 'D': result += 500; break;
        case 'M': result += 1000; break;
        default: break;
        }
        int last = s.size()-1;
        for (int now = s.size() -2; now >= 0; now--)
        {
            switch (s[now])
            {
            case 'I': result -= (s[last] == 'V') || (s[last] == 'X') ? 1 : -1;
                last = now;
                break;
            case 'V': result += 5;
                last = now;
                break;
            case 'X': result -= (s[last] == 'L') || (s[last] == 'C') ? 10 : -10;
                last = now;
                break;
            case 'L': result += 50;
                last = now;
                break;
            case 'C': result -= (s[last] == 'D') || (s[last] == 'M') ? 100 : -100;
                last = now;
                break;
            case 'D': result += 500;
                last = now;
                break;
            case 'M': result += 1000;
                last = now;
                break;
            default:
                break;
            }
        }
        return result;

        
    }
};

/* another method in cpp
        if (s.empty()) { return 0; }
        unordered_map<char, int> mp { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int sum = mp[s.back()];
        for (int i = s.size() - 2; i >= 0; --i) {
            sum += mp[s[i]] >= mp[s[i + 1]] ? mp[s[i]] : -mp[s[i]];
        }
        return sum;
*/


