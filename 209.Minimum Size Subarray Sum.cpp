/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的子数组。如果不存在符合条件的子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

思路：双指针，开始都指向头，然后慢慢后移，记录两个指针之间（包括指针所指）的数的和（右指针移一次后加上指针项，左指针移一次前减去指针项）
每次遍历发现大于等于s，如果当前两指针距离比缓存的最小值更小则更新最小长度。否则不动。之后左指针右移（减少值）
否则右指针右移，记录和，直到右指针超出数组时退出
如果扫完发现最小长度没更新过，代表一整个数组的和都不够s，返回0
如果数组为空，也找不到，返回0
如果最小长度更新过，代表有这个子数组，返回这个最小长度

进阶往更复杂的时间复杂度去尝试是什么梗？
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)return 0;
        int pre=0,cur=0,currentTot=nums[0],minLen=nums.size()+1;
        while(true){
            if(currentTot<s){
                cur++;
                if(cur>=nums.size())break;
                currentTot+=nums[cur];
            }
            else{
                if(cur-pre+1<minLen)minLen=cur-pre+1;
                currentTot-=nums[pre++];
            }
        }
        return minLen==nums.size()+1?0:minLen;
    }
};
