/*
56.合并区间（探索字节跳动——数组与排序（9））

给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

思路（原地修改数组）：
先给数组们排个序，按起始值从小到大排，起始值相同的按终止值小到大排
然后设个指针，每次尝试合并指针指向的区间和它的下一个区间
如果指针指向的终止值大于等于下一个区间起始值，那么这两个区间可以合并，将下一个区间的终止值移到指针指向的区间的终止值，同时删掉后面那个区间
如果不能合并，直接将指针挪到下一个区间继续尝试合并
时间复杂度O(n)，空间复杂度O(1)

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool intervalCompare(Interval a, Interval b){
        if(a.start==b.start)return a.end<b.end;
        return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()<=1)return intervals;
        sort(intervals.begin(), intervals.end(), intervalCompare);
        int ptr=0;
        while(ptr<intervals.size()-1){
            //ptr指向的区间和它前面那个比较，如果能合就合
            if(intervals[ptr].end>=intervals[ptr+1].start){
                if(intervals[ptr].end<intervals[ptr+1].end)intervals[ptr].end=intervals[ptr+1].end;
                intervals.erase(intervals.begin()+ptr+1);
            }
            //不能合就往下挪一个指针
            else ptr++;
        }
        return intervals;
    }
};
