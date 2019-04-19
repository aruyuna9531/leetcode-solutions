/*
120.三角形最小路径和[Medium]（探索字节跳动——动态或贪心（5））

三角形最小路径和

给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

思路：
自底向上dp，使用n的额外空间先保存最后一行的数，表示以该数字为顶部的最小路径和（长度只有1）
然后上一行在额外空间里原地修改，针对每个下标i的数，先比较额外空间里的该下标与下一个下标的值，较小者和自身值之和记为以自身为顶点的最小路径和，写到额外空间的对应下标位置
一直到扫完第一行

最后额外空间里的第1个数就是结果
时间复杂度O(n^2)，空间复杂度O(n)

*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)return 0;
        int *tmp = new int[triangle.size()];
        
        //初始化为最后一行
        for(int i=0;i<triangle.size();i++){
            tmp[i]=triangle[triangle.size()-1][i];
                printf("%d ",tmp[i]);
        }
        printf("\n");
        //检索上面行， 记录这些行每个位置开始检索的最小值
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                tmp[j]=triangle[i][j]+(tmp[j]>tmp[j+1]?tmp[j+1]:tmp[j]);
                printf("%d ",tmp[j]);
            }
            printf("\n");
        }
        
        int res = tmp[0];
        
        delete []tmp;
        
        return res;
    }
};
