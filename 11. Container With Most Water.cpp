/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。画 n 条垂直线，使得垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

注意：你不能倾斜容器，n 至少是2。

思路：拆水缸
先从两边的两根柱子开始（这两个宽最大有可能水最多），计算容积（宽度×两块板较短的），如果大于目前最大值则更新
然后缩小板，哪边的板是较短的它就往里缩一块（因为如果是缩较长的那个容积只会少不会多，因为高顶多不变（还可能减少），宽度直接就减1，所以容积一定减少）
继续算容积，多者替换最大值
一直到两块板是隔壁为止

*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int front=height.size()-1,back=0,res=(height[front]>height[back]?height[back]:height[front])*(height.size()-1);
        while(front>back){
            if(height[front]>height[back])back++;
            else if(height[front]==height[back]){
                if(height[front-1]>height[back+1])front--;
                else back++;
            }
            else front--;
            int tmp=(height[front]>height[back]?height[back]:height[front])*(front-back);
            if(tmp>res)res=tmp;
        }
        return res;
    }
};
