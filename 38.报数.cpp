/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */
class Solution {
public:
    string countAndSay(int n) {
        vector<string> res;
        char count, digit;
        int p1 = 0, p2 = 0;
        int length_res;
        switch (n)
        {
        case 1:
            return "1";
            break;
        case 2:
            return "11";
            break;
        case 3:
            return "21";
            break;
        case 4:
            return "1211";
            break;
        case 5:
            return "111221";
            break;

        default:
            break;
        }
        res[5].push_back("111221");
        for (int i = 6; i <= n; i++)
        {
            p1 = 0, p2 = 0;
            length_res = res[i-1].length();
            while(p2 < length_res){
                while(p2 + 1 <length_res && res[i-1][p2 + 1] == res[i-1][p1]){
                    p2++;
                }
                digit =res[i-1][p1];
                count = 48 + p2 - p1 + 1;
                res[i].push_back(count);
                res[i].push_back(digit);
                p1 = p2 + 1;
                p2 = p1;
                
                
            }
            
            
        }
        return res[n];
        
        
    }
};

