/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

//解法一

// class Solution {
// public:
//     int romanToInt(string s) {
//         if (s.empty())
//         {
//             return 0;
//         }
        
//         int result = 0;
//         switch (s.back())
//         {
//         case 'I': result += 1; break;
//         case 'V': result += 5; break;
//         case 'X': result += 10; break;
//         case 'L': result += 50; break;
//         case 'C': result += 100; break;
//         case 'D': result += 500; break;
//         case 'M': result += 1000; break;
//         default: break;
//         }
//         int last = s.size()-1;
//         for (int now = s.size() -2; now >= 0; now--)
//         {
//             switch (s[now])
//             {
//             case 'I': result -= (s[last] == 'V') || (s[last] == 'X') ? 1 : -1;
//                 last = now;
//                 break;
//             case 'V': result += 5;
//                 last = now;
//                 break;
//             case 'X': result -= (s[last] == 'L') || (s[last] == 'C') ? 10 : -10;
//                 last = now;
//                 break;
//             case 'L': result += 50;
//                 last = now;
//                 break;
//             case 'C': result -= (s[last] == 'D') || (s[last] == 'M') ? 100 : -100;
//                 last = now;
//                 break;
//             case 'D': result += 500;
//                 last = now;
//                 break;
//             case 'M': result += 1000;
//                 last = now;
//                 break;
//             default:
//                 break;
//             }
//         }
//         return result;

        
//     }
// };

//解法一结束

/* another method in cpp

        if (s.empty()) { return 0; }
        unordered_map<char, int> mp { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int sum = mp[s.back()];
        for (int i = s.size() - 2; i >= 0; --i) {
            sum += mp[s[i]] >= mp[s[i + 1]] ? mp[s[i]] : -mp[s[i]];
        }
        return sum;
*/



//英文版Leetcode热门解法一

// class Solution {
// public:
//     int romanToInt(string s) {
//         int sum=0;
//     if(s.indexOf("IV")!=-1){sum-=2;}
//     if(s.indexOf("IX")!=-1){sum-=2;}
//     if(s.indexOf("XL")!=-1){sum-=20;}
//     if(s.indexOf("XC")!=-1){sum-=20;}
//     if(s.indexOf("CD")!=-1){sum-=200;}
//     if(s.indexOf("CM")!=-1){sum-=200;}
    
//     char c[]=s.toCharArray();
//     int count=0;
    
//    for(;count<=s.length()-1;count++){
//        if(c[count]=='M') sum+=1000;
//        if(c[count]=='D') sum+=500;
//        if(c[count]=='C') sum+=100;
//        if(c[count]=='L') sum+=50;
//        if(c[count]=='X') sum+=10;
//        if(c[count]=='V') sum+=5;
//        if(c[count]=='I') sum+=1;
       
//    }
   
//    return sum;
//     }
// };

//英文版Leetcode热门解法一结束




//英文版Leetcode热门解法一 我的优化

class Solution {
public:
    int romanToInt(string s) {
    int sum=0;
    int len = s.length();
    string tmp="";
    for (int i = 0; i < len-1; i++)
    {
        tmp=s.substr(i,2);
        // switch (tmp)
        // {
        // case 'IV': 
        // case 'IX': sum-=2; break;
        // case 'XL': 
        // case 'XC': sum-=20; break;
        // case 'CD': 
        // case 'CM': sum-=200; break;

        // default:
        //     break;
        // }
        if (tmp == "IV" || tmp == "IX")
        {
            sum -= 2; i++; continue;
        }
        if (tmp == "XL" || tmp == "XC")
        {
            sum -= 20; i++; continue;
        }
        if (tmp == "CD" || tmp == "CM")
        {
            sum -= 200; i++; continue;
        }
        
    }
    
    
    // char c[]=s.toCharArray();
    int count=0;
    
    for(;count<=len-1;count++) {//似乎还能优化暂时没想法
    switch (s[count])
    {
    case 'M': sum+=1000; break;
    case 'D': sum+=500; break;
    case 'C': sum+=100; break;
    case 'L': sum+=50; break;
    case 'X': sum+=10; break;
    case 'V': sum+=5; break;
    case 'I': sum+=1; break;

    default:
        break;
    }
    //    if(s[count]=='M') {sum+=1000;continue;}
    //    if(s[count]=='D') {sum+=500;continue;}
    //    if(s[count]=='C') {sum+=100;continue;}
    //    if(s[count]=='L') {sum+=50;continue;}
    //    if(s[count]=='X') {sum+=10;continue;}
    //    if(s[count]=='V') {sum+=5;continue;}
    //    if(s[count]=='I') {sum+=1;continue;}
       
   }
   
   return sum;
    }
};

//英文版Leetcode热门解法一 优化结束