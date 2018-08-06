/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
     
思路：有了II的动态规划思想，非环形的还不用加条件，方便得很……
只有2家以下返回较大值，3家以上时用数组记录当前可获得最大金额
第3家记录第1家和第3家之和
第4家开始，x家的最大金额为第x家本身金额加上x-2,x-3家最大金额的较大值。
最后比较倒数两个值，返回较大值
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=0)return 0;
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return nums[0]>nums[1]?nums[0]:nums[1];
        int *house=new int[nums.size()];
        house[0]=nums[0];
        house[1]=nums[1];
        house[2]=nums[0]+nums[2];
        for(int i=3;i<nums.size();i++){
            house[i]=nums[i]+(house[i-2]>house[i-3]?house[i-2]:house[i-3]);
        }
        int res=house[nums.size()-1]>house[nums.size()-2]?house[nums.size()-1]:house[nums.size()-2];
        delete []house;
        return res;
    }
};
