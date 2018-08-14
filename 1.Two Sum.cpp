/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

思路：这不是一个排序数组，因此不能用双指针，只能逐个遍历。先定下第一个数，然后在后面找期望的第二个数，存在则输出。
时间复杂度O(n^2)。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int tmp=-1;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            tmp=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[tmp]+nums[j]==target){
                    res.push_back(tmp);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};

/*先排序，再双指针，时间复杂度O(nlogn)+O(n)=O(nlogn)
实现略*/
