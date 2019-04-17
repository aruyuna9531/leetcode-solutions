/*
42.接雨水[Hard]（探索字节跳动——数组与排序（10））

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

思路：
每根挡板上可承载的雨水高度是它前面最高的挡板和后面最高的挡板中，较矮的那一块，和该挡板自己的高度差
因此对每根挡板，找出前后最高挡板高度，取较小值减去自身的高度就是该挡板承受的雨水量（负数则归零）
时间复杂度O(n(扫描每根挡板)*n(扫出前后最高挡板))=O(n^2)，空间复杂度O(1)
代码略（因为直接想到了下面优化方法）

→由于寻找前后挡板时挡板高度数据会被重复使用，因此借两个数组记录每一根挡板的前后最高挡板高度
记录前方最高挡板从后往前扫，最后一个挡板的前方最高记为0（前方无挡板），倒数第二个记为最后一个挡板的高度
然后倒数第3个开始前方最高挡板高度记为前方挡板和最后一条记录里的较大值，直到第一根挡板
后方最高挡板记录同理，方向是从前往后扫
然后再扫一遍Height，从两个最高挡板的数组中直接取前后最高值，取较小值后减去自身高度累加到积水总和
时间复杂度O(n)[扫前方最高挡板]+O(n)[扫后方最高挡板]+O(n)[扫height]=O(n)，空间复杂度O(n)[记录前方最高挡板]+O(n)[记录后方最高挡板]=O(n)

*/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2)return 0;
        int total=0;
        //记录某个下标前面的最高挡板高度（逆序）
        vector<int> frontMaxList;
        frontMaxList.push_back(0);
        frontMaxList.push_back(height[height.size()-1]);
        for(int i=height.size()-2;i>=1;i--){
            frontMaxList.push_back(height[i]>frontMaxList[frontMaxList.size()-1]?height[i]:frontMaxList[frontMaxList.size()-1]);
        }
        //后面的最高挡板高度
        vector<int> backMaxList;
        backMaxList.push_back(0);
        backMaxList.push_back(height[0]);
        for(int i=1;i<height.size()-1;i++){
            backMaxList.push_back(height[i]>backMaxList[backMaxList.size()-1]?height[i]:backMaxList[backMaxList.size()-1]);
        }
        //扫描每个挡板，找到其前后各自最大值，积水量为较小一方和自身高度的差
        for(int i=0;i<height.size();i++){
            int maxRHeight=(frontMaxList[height.size()-1-i]>backMaxList[i]?backMaxList[i]:frontMaxList[height.size()-1-i]);
            if(height[i]<maxRHeight)total+=maxRHeight-height[i];
        }
        return total;
    }
};
