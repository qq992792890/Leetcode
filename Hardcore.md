# Some HardCore Problems
[TOC]

未完成题目  有些难度（还是从简单题开始入手比较好）  
## [53. 最大子序和]https://leetcode-cn.com/problems/maximum-subarray/)   
 /*从第一个数开始，向右加上最大的正连续子集，减去左边做大的连续负连续子集*/
        //此算法麻烦且不全，需要考虑很多情况
        /*
        只有一个数字 返回这个数字
        没有正数，全部是负数 返回最大负数
        有零或者含相加等于零的子串（其中可能未出现相加和>0 相加为零的子串中必定存在最大正子串）尚未知道如何解决
        以及更多
        该方法可以改进，因为最大子串
        */   

一开始考虑过的方法还有从中间开始向两边找   
但是实际上正确的方法是从正数开始找，因为最大的子串两边必定是正数。如果没有正数，则返回最大负数   
   比如下面这个算法非常巧妙，如果不考虑sum有可能溢出的情况下的话，可以解决大多数情况
   所有子串都是从一个正数开始的找寻所有相加和大于0的子串，并保存最大的为结果
   当所有数都是负数也能返回最大的负数
   当只有一个数是，也能正常处理
   中间包含零或者和为零的子串也不影响处理
   

```java   
class Solution {
    public int maxSubArray(int[] nums) {
        int res = nums[0];
        int sum = 0;
        for (int num : nums) {
            if (sum > 0)
                sum += num;
            else
                sum = num;
            res = Math.max(res, sum);
        }
        return res;
    }
}
```
 

···c++   
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */   
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
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


···   
   
5.最长回文子串（未完成）  6.z-字形变换（已完成190825）
## [15.Three Sum](https://leetcode-cn.com/problems/3sum/)

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

一开始容易想到的是循环求解法
```c++
int n1 = 0,n2 = 0,n3 = 0;
int temp = 0, numsmax = nums.size();
vector<vector<int>> res;
vector<int> part;
bool skip = false;
//this method can remove duplicate ones
for (int i = 0; i < numsmax - 2; i++)
{
    n1 = nums[i];
    for (int j = i + 1; j < numsmax - 1; j++)
    {
        n2 = nums[j];
        temp = n1 + n2;

        for (int k = j + 1; k < numsmax; k++)
        {
            n3 = nums[k];
            //if n1 and n2 exist in any found part
            if (temp + n3 == 0)
            {
                part.push_back(n1);
                part.push_back(n2);
                part.push_back(n3);
                res.push_back(part);
                part.clear();
            }
            
            
        }
        
    }
    
}

return res;
```
这个方法可以解决部分情况实现也比较简单，但是问题是不能排除重复的部分
然后想到在得到的结果之上去掉重复的组合，由于数据不是有序的，所以复杂度会比较高  
于是想到先将数据排序在得出结果，也比较易于在得到结果时去除重复。
联想到了Two sum中的查找方法。  
不过在此之前还想过一些其他脑洞，记录下。  
由于三个相同的数（除了零）相加不可能得零，可以把数据中的多余的数去掉每个数最多只保留两个即可，只需O(n)的运算量即可完成（不考虑顺序表删除数据的计算量的话）   
当然只有冗余非常多才需要这样计算，否则会浪费时间    
判断冗余的多少可以由序列中最大数和最小数的差与数据总量得出    
完全没有冗余的情况差值等于数值个数`max-min == size`每个数出现两次`max - min == 2 * size`基于此当`max - min`大于`size`一定的倍数时可以去掉冗余数字。非有序序列计算最大值最小值只需要进行一次循环，计算量O(n)，排序数组就无需计算了

以上为脑洞，最后参照评论中的一个Python解法提交了
```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        '''
        算法思路：最外层控制一个元素的循环，
                内层用双指针，一个从头到尾扫描，另一个从尾到头扫描，判断三个元素的值之和是否为零
                
        注意：相同的元素需要跳过
        '''
        # 对列表进行排序
        nums.sort()
        res, k = [], 0
        for k in range(len(nums) - 2):
            # 如果出现最小元素为正数，则不存在和为0的情况，直接返回
            if nums[k] > 0:
                break
            # 如果出现第一个元素重复的情况，为避免重复结果，跳过后续执行
            if k > 0 and nums[k] == nums[k - 1]:
                continue
            # 定义接下来的两个元素的双指针
            i, j = k + 1, len(nums) - 1
            while i < j:
                s = nums[k] + nums[i] + nums[j]
                if s < 0:
                    i += 1
                    # 跳过重复元素
                    while i < j and nums[i] == nums[i - 1]:
                        i += 1
                elif s > 0:
                    j -= 1
                    # 跳过重复元素
                    while i < j and nums[j] == nums[j + 1]:
                        j -= 1
                else:
                    # 当出现元素满足条件是，将结果加入到列表
                    res.append([nums[k], nums[i], nums[j]])
                    # 接着更新索引（注意跳过相同元素）
                    i += 1
                    j -= 1
                    while i < j and nums[i] == nums[i - 1]:
                        i += 1
                    while i < j and nums[j] == nums[j + 1]:
                        j -= 1
        return res
```

我基于此给出的方案
```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n1 = 0,n2 = 0,n3 = 0;
        int temp = 0, numsmax = nums.size();
        vector<vector<int>> res ;
        vector<int> part;
        bool skip = false;
        std::sort(nums.begin(),nums.end());

        
        for (int i = 0; i < numsmax -2; i++)
        {
            n1 = nums[i];
            if (n1 > 0)
            {//if first digit > 0 there is no more answer after that
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {//skip same digits
                continue;
            }
            //then it becomes two sum problems
            int j = i + 1,k = numsmax - 1;
            while (j < k)
            {
                temp = nums[i] + nums[j] + nums[k];
                if (temp < 0)
                {
                    j += 1;
                    while (nums[j] == nums[j - 1] && j < k)
                    {
                        j += 1;
                    }
                    
                }else
                {
                    if (temp > 0)
                    {
                        k -= 1;
                        while (nums[k] == nums[k + 1] && j < k)
                        {
                            k -= 1;
                        }
                        
                    }else
                    {
                        //temp = 0
                        part.push_back(nums[i]);
                        part.push_back(nums[j]);
                        part.push_back(nums[k]);
                        res.push_back(part);
                        part.clear();

                        j += 1;
                        while (nums[j] == nums[j - 1] && j < k)
                        {
                            j += 1;
                        }
                        k -= 1;
                        while (nums[k] == nums[k + 1] && j < k)
                        {
                            k -= 1;
                        }
                    }
                    
                    
                }
                
                
            }

        }

        return res;
        
    }
};
```

   
## [5.最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)   
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
   
马拉车算法Manacher 算法   
是一种解法，为了便于处理，将给出的串统一转化为奇数回文串   
我们将每一个字符的左边和右边都添加一个字符（这个字符是输入中所没有的）。一般都为#。比如说abc和abcd这两个串转化后就为#a#b#c#和#a#b#c#d#。长度分别为7和9这样无论奇偶都能被转换成奇数回文串了. 其实在我看来,Manacher就是优化后的中心检测法,和KMP算法类似,Manacher的思想也是避免”匹配”失败后的下标回退   
转载注明出自 bestsort.cn,谢谢合作

## [6.Z字形变换](https://leetcode-cn.com/problems/zigzag-conversion/)  
方法一：按行排序    我想到和使用的方法
思路

通过从左向右迭代字符串，我们可以轻松地确定字符位于 Z 字形图案中的哪一行。

算法

我们可以使用 \text{min}( \text{numRows}, \text{len}(s))min(numRows,len(s)) 个列表来表示 Z 字形图案中的非空行。

从左到右迭代 ss，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。

只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。

作者：LeetCode
链接：https://leetcode-cn.com/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

方法二：按行访问   
思路

按照与逐行读取 Z 字形图案相同的顺序访问字符串。

算法

首先访问 行 0 中的所有字符，接着访问 行 1，然后 行 2，依此类推...

对于所有整数 kk，

行 00 中的字符位于索引 k \; (2 \cdot \text{numRows} - 2)k(2⋅numRows−2) 处;
行 \text{numRows}-1numRows−1 中的字符位于索引 k \; (2 \cdot \text{numRows} - 2) + \text{numRows} - 1k(2⋅numRows−2)+numRows−1 处;
内部的 行 ii 中的字符位于索引 k \; (2 \cdot \text{numRows}-2)+ik(2⋅numRows−2)+i 以及 (k+1)(2 \cdot \text{numRows}-2)- i(k+1)(2⋅numRows−2)−i 处;

作者：LeetCode
链接：https://leetcode-cn.com/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。