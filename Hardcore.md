# Some HardCore Problems
[TOC]

未完成题目  有些难度（还是从简单题开始入手比较好）  
5.最长回文子串（未完成）  6.z-字形变换（已完成190825）   
   

## [32. 最长的有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)  
开始的想法如下：
```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        //使用堆栈实现，并维护一个最大堆栈长度大小
        //目前有问题卡在()(())这个例子
        //不能简单的用堆栈实现 未完成！！
        //碰到右括号且闭合时 size为奇数时继续想寻找 size偶数时尝试更新res
        //
        vector<char> cstack;
        vector<char> zero;
        int res = 0, size_s = s.size();
        for (int i = 0; i < size_s; i++)
        {
            if (s[i] == ')')
            {
                if (cstack.size() != 0)
                {
                    if (cstack.back() == '(')
                    {
                        cstack.push_back(s[i]);
                        if (cstack.size() > res)
                        {
                            res = cstack.size();
                        }
                    }else if (cstack.back() == ')')
                    {
                        cstack = zero;
                    }
                    
                    
                }else continue;
                
                
            }else if (s[i] == '(')
            {
                if (cstack.empty() || cstack.back() == ')')
                {
                    cstack.push_back(s[i]);
                }else if (cstack.back() == '(')
                {
                    cstack = zero;
                    cstack.push_back('(');
                }
                
                
                
            }

            
        }
        return res;
        
    }
};
```
改进后方案如下
```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        //使用堆栈实现，并维护一个最大堆栈长度大小
        //目前有问题卡在(()(((()这个例子
        //不能简单的用堆栈实现 未完成！！
        //碰到右括号且闭合时 size为奇数时继续想寻找 size偶数时尝试更新res
        //
        vector<char> cstack;
        vector<char> zero;
        int res = 0, size_s = s.size(), csize = 0;
        int cdepth = 0;
        int insidesize = 0;//嵌套括号的大小
        for (int i = 0; i < size_s; i++)
        {
            if (s[i] == ')')
            {
                if (!cstack.empty())
                {
                    if (cstack.back() == '(')
                    {
                        cstack.pop_back();
                        //括号深度未清零时左括号打断连续括号
                        if (cdepth == 1)
                        {
                            csize += 2;
                            if (insidesize != 0)
                            {
                                csize += insidesize;
                                insidesize = 0;
                            }
                            
                            insidesize = 0;
                            if (csize > res)
                            {
                                res = csize;
                            }
                            cdepth --;
                        }else//cdepth != 0
                        {
                            insidesize += 2;
                            if (insidesize > res)
                            {
                                res = insidesize;
                            }
                            cdepth--;
                            // if (cdepth == 1)
                            // {
                            //     csize+=insidesize;
                            // }
                            
                        }
                        
                        

                        // if (cstack.empty())
                        // {
                        //     csize = 0;
                        // }
                                        
                    }
                    //else if (cstack.back() == ')')
                    // {
                    //     cstack = zero;
                    // }
                    
                    
                }else {
                    csize = 0;//右括号打断连续括号
                    continue;
                }//i++
                
                
            }else if (s[i] == '(')
            {
                cstack.push_back('(');
                cdepth++;

            }

            
        }
        return res;
        
    }
};
```
但是仍然只能通过168/230个测试样例
赞最多的答案是这个 不太理解其含义
```c++
 int longestValidParentheses(string s) {
        int cnt = 0; // count of "("
        vector<int> dp(s.size()+1, 0);
        
        for (size_t i = 1; i <= s.size(); i++) {
            if (s[i-1] == '(') {
                cnt++;
            } else {
                if (cnt > 0) {  // there exists an unclosed "(" to match ")"
                    cnt--;
                    dp[i] = 2;
                    if (s[i-2] == ')')  // add the length of previous closed ")" neighbor
                        dp[i] += dp[i-1];                        
                    dp[i] += dp[i-dp[i]]; // add the length of previous valid parentheses
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
```
## [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/)  
为什么说求平方根硬核呢，因为虽然这个题目能用其他方法解出来但是万万没想到还有这么简单的方法就可以解出来   
那就是！！！！   
牛顿迭代法   
求平方根也就是说```x^2 = a so that x = sqrt(a)```   
而要求解```x^2 = a```实际上是```x^2 - a = y```在x轴上的根
这个怎么算呢在不知道平方根怎么计算的情况下，我们已知直线在坐标轴上的根的求法 在```x^2 - a = y```的图像上在任意一点x处做出切线求与坐标轴交点即可慢慢逼近   
思路如下   
```
计算x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解，如左图所示。

   首先取x0，如果x0不是解，做一个经过(x0,f(x0))这个点的切线，与x轴的交点为x1。    
   
   同样的道理，如果x1不是解，做一个经过(x1,f(x1))这个点的切线，与x轴的交点为x2。   
   
   以此类推。   
     
   以这样的方式得到的xi会无限趋近于f(x)=0的解。   
   
   判断xi是否是f(x)=0的解有两种方法：   
   
   一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi和xi-1是否无限接近。   
经过(xi, f(xi))这个点的切线方程为f(x) = f(xi) + f’(xi)(x - xi)，其中f'(x)为f(x)的导数，本题中为2x。令切线方程等于0   
```
即可算出x[i+1] = {a/x[i] + x}/2


## [53.最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)   
 从第一个数开始，向右加上最大的正连续子集，减去左边做大的连续负连续子集
        此算法麻烦且不全，需要考虑很多情况
        只有一个数字 返回这个数字
        没有正数，全部是负数 返回最大负数
        有零或者含相加等于零的子串（其中可能未出现相加和>0 相加为零的子串中必定存在最大正子串）尚未知道如何解决
        以及更多
        该方法可以改进，因为最大子串
        

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
 

```c++   
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


``` 
   

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

## [67. 二进制求和](https://leetcode-cn.com/problems/add-binary/)    
最不硬核的题目之一 采用加法器原理轻松解决   
0ms或4ms 算法加法器原理   
先把两个字符串中短的一个前面补零，使的长度一致   
从后往前按位相加，再加上进位（溢出）。相加溢出进位置为1   
最后判断一溢出位   
有溢出位则在结果前面插入‘1’即可   
```c++
class Solution {
public:
    string addBinary(string a, string b) {
        //加法器原理
        //1 转为二进制相加后用字符串表示
        //2 直接对二进制字符串进行运算，以较长的字符串作为循环体
        int size_a = a.size();
        int size_b = b.size();
        string res;
        char sum;
        int overflow;
        if (size_a > size_b)
        {
            b.insert(b.begin(), size_a - size_b, '0');
        }else if (size_a < size_b)
        {
            a.insert(a.begin(), size_b - size_a, '0');
        }
        
        size_a = a.size();
        overflow = 0;
        for (int i = size_a - 1; i >= 0; i--)
        {
            sum = char(a[i] - '0' + b[i] + overflow);
            if (sum > '1')
            {
                sum = char(sum - 2);
                overflow = 1;
                res.insert(res.begin(), sum);

            }else
            {
                overflow = 0;
                res.insert(res.begin(), sum);
            }
        }
        if (overflow == 1)
        {
            res.insert(res.begin(), '1');
        }
        return res;
        
        
    }
};
```

## [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)    
这个问题让人想到上来就递归，但是出题者显然不是让你这么做的，45个case过了21个就超出时间限制   
因为递归需要大量出栈入栈操作及其浪费时间   
因此将递归改为循环推演法比较合适   
```c++
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
class Solution {
public:
    int climbStairs(int n) {
        //走一级台阶后剩下台阶的总可能数 + 走两级台阶后剩下台阶的走法
        if (n == 0) return 0; 
        if (n == 1) return 1; 
        if (n == 2) return 2;  
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};   
```
改为循环推演

   
   88.合并两个有序数组
已知
我的垃圾方法 还没通过
```c++
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j =0;
        for (int i = 0; i < n; i++)
        {
            while (nums2[i] < nums1[0])//插入头部
            {
                nums1.insert(nums1.begin(),nums2[i]);
                continue;
            }
            
            for (j = 0; j < m + n; j++)//插入中间
            {
                if (nums2[i] >= nums1[j])
                {
                    continue;
                }
                //nums2[i] < nums1[j];
                nums1.insert(nums1.begin() + j, nums2[i]);
                break;
            }
            if (j <= n + m && i < n)//插入尾部 未完成
            {
                for ( ; i < n; i++)
                {
                    nums1.insert(nums1.begin() + j, nums2[i]);
                }
                
            }
            
            
            
        }
        
    }
};


```
   
   很快我就想到了新的方法，数组最总形态是长度m+n且给出的nums1长度是m+n那么直接在nums1的尾部插入两者尾部最大值即可，只需比较两者的尾部谁最大，插入nums1的形成新的尾部即可
   参考高票回答就是这样子
   ```c++
   class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};
   ```
   多么简洁的解决方案
   下面是看起来相似的一个解决方案却不能通过因为i>=0不满足时仍会访问nums1[i]导致内存溢出 所以出错必须修改到上述版本才可通过，时间在8-12ms 看起来还不错
   ```c++
   class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int tail = m + n - 1;
        while (j >= 0)
        {
            nums1[tail--] = i >= 0 && nums2[j] >= nums1[i] ? nums2[j--] : nums1[i--];
        }

    }
};
   ```