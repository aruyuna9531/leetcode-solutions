/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/
/*
思路1：回溯法，假设先偷第1家，那么第2家不能偷，下一个目标是第3或第4家（不会是第5家，因为偷第1和第5家肯定偷第3家，3和1、5不相邻）
假设下一个偷第3家，那么下一个目标就是第5或第6家
即假设每次你选择偷第x家，下一个目标就是x+2或x+3家
每次偷下一家之前记录一下当前路径偷得的金额，然后比较下一个目标偷x+2家和偷x+3家最终获得金额哪个较大，加上当前路径偷得的，得到总和并返回。
如果假设偷了第1家，那么不能偷最后一家，因此计算下一家时，如果是最后一家则跳过
偷第1家计算完成后，计算偷第2、3家，返回三者的最大值
时间复杂度O(……)好像是指数级别Σ(ﾟдﾟlll)

第一次编码结果：第65个用例超时
*/
class Solution {
public:
    int firstSteal;
    int rob(vector<int>& nums, int CurrentRob, int startAt){
        int highRob=0;
        if(startAt+2<nums.size()){
            if(startAt+2!=nums.size()-1 || firstSteal!=0)highRob=rob(nums, CurrentRob+nums[startAt+2], startAt+2);
        }
        if(startAt+3<nums.size()){
            if(startAt+3!=nums.size()-1 || firstSteal!=0){
                int s3=rob(nums, CurrentRob+nums[startAt+3], startAt+3);
                if(s3>highRob)highRob=s3;
            }
        }
        return highRob>CurrentRob?highRob:CurrentRob;
    }
    int rob(vector<int>& nums) {
        if(nums.size()<=0)return 0;
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return nums[0]>nums[1]?nums[0]:nums[1];
        firstSteal=0;
        int robA=rob(nums, nums[0], 0);
        firstSteal=1;
        int robB=rob(nums, nums[1], 1);
        firstSteal=2;
        int robC=rob(nums, nums[2], 2);
        int bigger=robA>robB?robA:robB;
        return robC>bigger?robC:bigger;
    }
};
/*
思路2：
动态规划，依次记录偷第x家之前的可偷最大值
假设偷第1家，dp[0]记录第1家的金额。第2家不能偷记为0，偷第3家时因为可以偷第1家（只要一共不是3家），记录为第3家加第1家之和
从第4家开始，dp[x]记录为dp[x]和dp[x-2]与dp[x-3]较大值之和，表示偷到第x+1家时可偷最大值。
一直算到dp[n-2]（n为总户数）。因为最后一家不能偷所以dp[n-1]=0。dp[n-2]和dp[n-3]的较大值就是结果。
然后假设不偷第1家，那么dp[0]=0，从第2家开始偷起，dp[1]=nums[1]，dp[2]=nums[2]。
从第4家开始和上面一样，只是可以偷最后一家了，一直算到dp[n-1]。dp[n-1]和dp[n-2]较大值为结果。
把上面得到的两个结果比较，较大值就是最终答案。

如果户数不足4家，那么你只能偷1家，返回整个数组里的较大值即可。
*/
class Solution {
public:
    int robFirstHouse(vector<int>& nums){
        //偷第1家时，金额最优策略。最后1家需要去除，从0算到nums.size()-2
        int *house=new int[nums.size()];
        house[0]=nums[0];
        house[1]=0;
        house[2]=nums[0]+nums[2];
        for(int i=3;i<nums.size()-1;i++){
            house[i]=nums[i]+(house[i-2]>house[i-3]?house[i-2]:house[i-3]);
        }
        int res=house[nums.size()-2]>house[nums.size()-3]?house[nums.size()-2]:house[nums.size()-3];
        delete []house;
        return res;
    }
    int notRobFirstHouse(vector<int>& nums){
        //不偷第1家时，金额最优策略。最后1家不需要去除，从1算到nums.size()-1
        int *house=new int[nums.size()];
        house[0]=0;
        house[1]=nums[1];
        house[2]=nums[2];
        for(int i=3;i<nums.size();i++){
            house[i]=nums[i]+(house[i-2]>house[i-3]?house[i-2]:house[i-3]);
        }
        int res=house[nums.size()-1]>house[nums.size()-2]?house[nums.size()-1]:house[nums.size()-2];
        delete []house;
        return res;
        
    }
    int rob(vector<int>& nums) {
        if(nums.size()<=0)return 0;
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return nums[0]>nums[1]?nums[0]:nums[1];
        if(nums.size()==3){
            int max=nums[0]>nums[1]?nums[0]:nums[1];
            return nums[2]>max?nums[2]:max;
        }
        int robA=robFirstHouse(nums);
        int robB=notRobFirstHouse(nums);
        return robA>robB?robA:robB;
    }
};
