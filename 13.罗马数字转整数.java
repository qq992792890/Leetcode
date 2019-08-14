/*
 * @lc app=leetcode.cn id=13 lang=java
 *
 * [13] 罗马数字转整数
 */
class Solution {
    public int romanToInt(String str) {
        //this is a method taken from the top ranked
    int[] a = new int[26];
    a['I' - 'A'] = 1;
    a['V' - 'A'] = 5;
    a['X' - 'A'] = 10;
    a['L' - 'A'] = 50;
    a['C' - 'A'] = 100;
    a['D' - 'A'] = 500;
    a['M' - 'A'] = 1000;
    char prev = 'A';
    int sum = 0;
    for(char s : str.toCharArray()) {
        if(a[s - 'A'] > a[prev - 'A']) {
            sum = sum - 2 * a[prev - 'A'];
        }
        sum = sum + a[s - 'A'];
        prev = s;
    }
    return sum;
    }
}

