/*
14.最长公共前缀[Easy]（探索字节跳动——挑战字符串（2））

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"

示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:

所有输入只包含小写字母 a-z 。

思路：
用一个数字length记录当前公共前缀的长度（反正大家都共用公共前缀所以这个数字是通用的），初始化为第1个字符串的长度
从第2个字符串开始，从第1个字母开始和第1个字符串（实际上前面任意一个字符串都可以）比较前length个字符是否一致，碰到不一致时，length更新为不一致位置的下标
最后截取任意一个字符串的0到length位置的子串返回

时间复杂度O(n^2)（有剪枝）

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        if(strs.size()==0)return s;
        int currentLongestLength=2147483647;            //记录当前公共前缀的长度
        for(int i=0;i<strs.size();i++){
            if(i==0){
                //第一个字符串直接把其长度记为暂时公共子串最大长度
                currentLongestLength=strs[i].size();
            }
            else{
                //第2个字符串开始扫当前前缀，和第1个字符串比较，碰到不同的就截掉
                for(int j=0;j<currentLongestLength;j++){
                    if(strs[0][j]!=strs[i][j]){
                        currentLongestLength=j;
                        break;
                    }
                }
            }
        }
        //从strs[0]处截下最长前缀返回
        return strs[0].substr(0, currentLongestLength);
    }
};
