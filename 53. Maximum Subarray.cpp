/*
53.最大子序和[Easy]（探索字节跳动——动态或贪心（4））

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

思路（非进阶）：

全负数组就挑一个最大的负数即可

含有0以上自然数的数组，用变量保存最大值和当前值，每扫一个数，累加到当前值，如果导致当前值大于最大值，更新最大值，如果导致当前值小于零，重置回零（表示前方没有比max更大的子数组存在并且后面最大的子数组（假设有）不会包含前面任何一个元素）

时间复杂度O(n)

代码如下（优化为一次扫描）

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int max=-1, current=0, maxMinus=-2147483648;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0 && nums[i]>maxMinus)maxMinus=nums[i];
            current+=nums[i];
            if(current<0)current=0;
            else if(current>max)max=current;
        }
        return max<0?maxMinus:max;
    }
};

/*
进阶：

*/
