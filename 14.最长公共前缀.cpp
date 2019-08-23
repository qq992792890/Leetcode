/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // my plan that originally come from myself
        //and after fix runtime error it just passed
        //amazing!! i forget to
        //try more time it can be run in less than 4ms
        int number = strs.size(); //number of words
        //if
        if (number == 0)
        {
            return "";
        }
        if (number == 1)
        {
            return strs[0];
        }
        int charlength = strs[0].size(); //length of first word
        int i = 0, j = 0;
        //bool finish = false; //this can use less memory
        //string error="";
        for (i = 0; i < charlength; i++)
        {
            for (j = 1; j < number; j++)
            {
                //strs[j].size() >= i is absolutely not less than i
                if (strs[j].size() >= i && strs[j - 1][i] == strs[j][i])
                { //
                    // if (strs[j - 1][i] == strs[j][i])
                    // {
                        continue; //to compare next sting
                    // }
                    // else
                    // { //one of the string do not match at charlength
                    //     finish = true;
                    //     //error="1";
                    //     break;
                    // }
                }
                else
                {
                    //one of current string's size is less than charlength
                    //finish = true;
                    //error="2";
                    if (i)
                    {
                        return strs[0].substr(0, i);
                    }
                    else
                    {
                        return "";
                    }
                    // break;
                }
            }
            // if (finish)
            // { //if at which charlength that do not match || one of string's size is less than charlength
            //     break;
            // }
        }

        if (i)
        {
            return strs[0].substr(0, i);
        }
        else
        {
            return "";
        }
    }
};

