/*
221.最大正方形[Medium]（探索字节跳动——动态或贪心（3））

在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

思路（dp）：

因为是找正方形，所以可以先转化问题为求一个最大边长，返回边长平方即可

找最长边长时，如果本身是0，那么结果就是0（这里构不成正方形）

如果是1，对每一个疑似正方形的右下角点，找他左上、上方、左方三个数中最小值，最小值+1就是以自身为右下角的最大正方形边长
例：

? ? ? ? ?
? ? ? ? ?
? ? ? 3 2
? ? ? 1 x

其中x为待求项，?为其他dp结果
那么从x的角度看，根据左上、上方和左方的值，至少原matrix填充的话肯定会有以下形态（其中?为未知项）


? 1 1 1 0
? 1 1 1 1
? 1 1 1 1
? 0 0 1 x

在这里可以一眼看出来x的边长是2，和dp矩阵对比，刚好是三个数最小值+1
因为三个数最小值代表以其本身为右下角的正方形只能这么大[y]，那离y距离为y的地方肯定有0
那么这个0和x位置距离就是y+1，因此x位置正方形边长最大只能是y+1
所以x位置的正方形最大边长就是左上、上方和左方中最小值+1

每次填充dp矩阵会比较新值与最大值，如果超过最大值，则更新最大值
最后返回最大值的平方

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        if(matrix[0].size()==0)return 0;
        
        int **dp = new int*[matrix.size()];
        for(int i=0;i<matrix.size();i++)dp[i]=new int[matrix[0].size()];
        
        //初始化首行首列
        int max=0;
        for(int i=0;i<matrix.size();i++){
            dp[i][0]=matrix[i][0]-48;
            if(dp[i][0]==1)max=1;
        }
        for(int i=0;i<matrix[0].size();i++){
            dp[0][i]=matrix[0][i]-48;
            if(dp[0][i]==1)max=1;
        }
        
        //填充其他格子
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]=='0')dp[i][j]=0;
                else{
                    int neighbormin = 2147483647;
                    if(dp[i-1][j-1]<neighbormin)neighbormin=dp[i-1][j-1];
                    if(dp[i][j-1]<neighbormin)neighbormin=dp[i][j-1];
                    if(dp[i-1][j]<neighbormin)neighbormin=dp[i-1][j];
                    dp[i][j]=neighbormin+1;
                    if(dp[i][j]>max)max=dp[i][j];
                }
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        
        for(int i=0;i<matrix.size();i++)delete []dp[i];
        delete []dp;
        
        return max*max;
        
    }
};
