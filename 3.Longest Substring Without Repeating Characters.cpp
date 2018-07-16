/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。

思路：
用两个指针扫，头指针和当前指针，当前指针直接扫一遍表比较字母，头指针则指向到当前指针为止没有重复字符的子串的第一个字母。
用一个哈希表存储某字母最近一次出现的下标。
cNext数组表示如果cList对应下标的字符再次被扫描到，那么就会视情况把头指针指向的下一个下标（因为当前指针所指的字母只有在那个下标开始才不会出现）
例如：abcabcbb，一开始头指针指向的第一个a，当前指针也指a，a在哈希表里未出现，因此加入，并把a的值设为1（表示一旦以后当前指针扫到了a，如果头指针在1之前，则设为1，表示从1开始到当前指针之前这部分才没有字符a）
哈希表存储(a,1)(b,2)(c,3)后，当前指针扫到了第2个a，a在哈希表里有出现，因此头指针需要移动到1这个位置，当前指针不用变，新的子串变成了"bca"。
在移动头指针之前，需要统计之前子串的长度，如果比临时存储的最大值大则更新，否则不更新。新的子串长度设为当前指针减去头指针加1，然后当前指针继续扫。
与此同时，当前指针指向的字符也要在哈希表上将下一个头指针指向更新为当前指针的下一个下标。
这里用indexOfChar()来查哈希表。

像"abcdcba"这种字符串，哈希表里存储键(a,1)(b,2)(c,3)(d,4)后，第2次遇到c更新为(c,5)，头指针指向了3
但下一个遇到b时，b在表中存储的值为2，然而头指针已经走在了2的前面，这里不能把头指针更为2，因为更了后子串就出现了重复字符c。
此时头指针不变，哈希表的b要更为6。下一个a同理。

一直扫到结束，返回所存储的最大值。
空串返回0。

时间复杂度O(n)
【下面的代码是O(n^2)因为哈希寻键函数占去O(n)真哈希表这里是O(1)】
*/
class Solution {
public:
    int indexOfChar(char target, char *list, int length){
        for(int i=0;i<length;i++){
            if(list[i]==target)return i;
        }
        return -1;
    }
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;
        char cList[100]={0};
        int cNext[100]={0};
        int cUsed=0;
        int maxLen=0;
        int tmpLen=0;
        int xMin=0;
        for(int i=0;i<s.length();i++){
            int ind=indexOfChar(s[i], cList, cUsed);
            if(ind==-1){
                //第一次出现
                cList[cUsed]=s[i];
                cNext[cUsed]=i+1;
                cUsed++;
                tmpLen++;
            }
            else{
                //重复字符，重新计算长度
                if(cNext[ind]<xMin){
                    tmpLen++;
                    cNext[ind]=i+1;
                    continue;
                }
                if(maxLen<tmpLen)maxLen=tmpLen;
                tmpLen=i-cNext[ind]+1;
                xMin=cNext[ind];
                cNext[ind]=i+1;
            }
        }
        if(tmpLen>maxLen)maxLen=tmpLen;
        return maxLen;
    }
};
