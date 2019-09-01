/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
class Solution {
public:
    int mySqrt(int x) {
        //2^0-->2^15 can be display 1<<i;i++;
        //(2^x)^2 = 2^(x*2)
        //int型范围（-2^31 --- 2^31 - 1）
        //其中x非负只需考虑正数部分，找到在那两个数之间在用二分查找
        //二分查找最多次数15此，因此最多只需进行15+15次计算即可找到对应平方根
        int res;
        int temp = 0, i = 0;
        //数太小时不适合使用二分查找
        if (x == 0) return 0; 
        if (x < 4) return 1; 
        if (x < 9) return 2; 
        if (x < 16) return 3; 
        // if (x < 25) return 4;//可不要
        
        for (i = 0; i < 16; i++)
        {
            temp = 1 << (2*i);
            if (x > temp) continue;  
            else//x <= temp
            {
                break;
            }
            
        }
        int start, end, middle;
        // int temp = 0;
        if (i < 16)
        {
            //x must be in between 1 << (2 * i) and 1 << (2 * i - 2)
            //res must be in between 1 << i and 1 << (i - 1)
            start = 1 << (i - 1);//i>1
            end = 1 << i;
            
        }else //i = 16
        {
            start = 1 << 15;
            end = 46340; //sqrt((1 << 31) - 1)
        }
        int square = 0;
        while (start < end)
        {
            middle = (end + start + 1) >> 1;
            square = middle * middle;
            if (x > square)
            {
                start = middle;
                continue;
            }
            else if (x == square)
            {
                return middle;
            }
            else//x < temp
            {
                end = middle - 1;
                continue;
            }
        }
        //start > end and start = end + 1
        // if (start < 46340 && start * start > x)
        // {
        //     return end;
        // }
        return start;
        
        

        
        
        
    }
};

