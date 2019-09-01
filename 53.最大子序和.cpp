/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*从第一个数开始，向右加上最大的正连续子集，减去左边做大的连续负连续子集*/
        //此算法麻烦且不全，需要考虑很多情况
        /*
        只有一个数字 返回这个数字
        没有正数，全部是负数 返回最大负数
        有零或者含相加等于零的子串（其中可能未出现相加和>0 相加为零的子串中必定存在最大正子串）尚未知道如何解决
        以及更多

        该方法可以改进，因为最大子串可能
        */
        int left = 0, right = 0;
        int maxpos = 0;//向右最大正子集 //必须有初始化，否则会内存溢出
        int minneg = 0;//左边小负子集
        int sum = 0,sumright = 0, sumleft = 0;
        int size_nums = nums.size();
        int i = 0;
        int poscount = 0;//计算所有正数个数
        if (size_nums == 1)//2.only one digit in list
        {
            return nums[0];
        }

        //initial
        sumright = nums[0];
        maxpos = 0;
        for (i = 0; i < size_nums; i++)
        {
            sum += nums[i];
            if (sum > sumright)
            {
                sumright = sum;
                maxpos = i;
            }
            if (nums[i] > 0)//count positive digit
            {
                poscount ++;
            }
            
            
        }
        if (sumright > 0)
        {
            right = maxpos;
        }else if (i >= size_nums)
        {//if biggest sumright no bigger than 0 and check to the end
            right = maxpos;
        }//there might be all the digit in the list less than 0
        sum = nums[0];
        if (poscount <= 0)//3.third changes
        {
            for (int k = 0; k < size_nums; k++)
            {
                if (nums[k] > sum)
                {
                    sum = nums[k];
                }
                
            }
            return sum;//return the biggedt negtive digit
            
        }
        
        
        
        right = maxpos;
        sum = 0;
        sumleft = nums[0];
        minneg = 0;
        for (int j = 0; j < right; j++)
        {
            sum += nums[j];
            if (sum < sumleft)
            {
                sumleft = sum;
                minneg = j;
            }
            
        }
        if (sumleft < 0)
        {
            left = minneg + 1;
        }

        sum = 0;
        for (int i = left; i <= right; i++)
        {
            sum += nums[i];
        }
        
        return sum;
        
        

    }
};

