/*
将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：

P   A   H   N
A P L S I I G
Y   I   R
之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:

string convert(string s, int numRows);
示例 1:

输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"
示例 2:

输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P     I    N
A   L S  I G
Y A   H R
P     I

思路：其实这个排列可以再歪一下
P     I     N
 A   L S   I G
  Y A   H R
   P     I
这样貌似好读多了
第一行出现过的字母在原串分布：0，2n-2，4n-4，……（n=numRows）
最后一行出现过的字母在原串分布：n-1，3n-3,5n-5，……
中间行（第i行）出现过的字母在原串分布：i-1，2n-2-(i-1)，2n-2+(i-1)，4n-4-(i-1)，4n-4+(i-1)，……
重排字符串即可
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        char *arr=new char[s.length()+1];
        int arrCount=0,n=numRows;
        //1st Line: 0, 2n-2, 4n-4, ……
        for(int i=0;i<s.length();i+=2*n-2){
            arr[arrCount++]=s[i];
        }
        //2nd Line-(n-1)Line: Line, 2n-2-Line, 2n-2+Line, 4n-4-Line, ……
        for(int i=1;i<n-1;i++){
            int cross=0;
            for(int j=i;j<s.length();){
                arr[arrCount++]=s[j];
                if(cross==0){
                    j+=2*n-2-2*i;
                    cross=1;
                }
                else
                {
                    j+=2*i;
                    cross=0;
                }
            }
        }
        //n Line: n-1, 3n-3, 5n-5, ……
        for(int i=n-1;i<s.length();i+=2*n-2){
            arr[arrCount++]=s[i];
        }
        arr[s.length()]='\0';
        string t(arr);
        delete []arr;
        return t;
    }
};
