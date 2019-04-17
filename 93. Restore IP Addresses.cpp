/*
93.复原IP地址[Medium]（探索字节跳动——挑战字符串（7））

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]

暴力遍历添加分隔符，如果分隔之后4个数都小于256，则是合法IP，添加一条记录
时间复杂度O(n^3)
*/

class Solution {
public:
    int getNum(vector<int> &t, int start, int end, int &mark){
        //包括start，不包括end
        int res=0;
        for(int i=start; i<end; i++){
            res=res*10+t[i];
        }
        if(t[start]==0 && (res!=0 || end-start>1) )mark++;
        return res;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()<=3 || s.size()>12)return res;
        vector<int> p;
        for(int i=0;i<s.size();i++)p.push_back(s[i]-48);
        for(int i=1;i<s.size()-2;i++){
            for(int j=i+1;j<s.size()-1;j++){
                for(int k=j+1;k<s.size();k++){
                    int mark=0;
                    int first=getNum(p, 0, i, mark), second=getNum(p, i, j,mark), third=getNum(p, j, k,mark), fourth=getNum(p, k, s.size(),mark);
                    if(mark!=0)continue;
                    if(first<256 && second<256 && third<256 && fourth<256){
                        char str[16]="...............";
                        int used=0;
                        if(first>=100){
                            str[used++]=first/100+48;
                            first%=100;
                            str[used++]=first/10+48;
                            first%=10;
                        }
                        else if(first>=10){
                            str[used++]=first/10+48;
                            first%=10;
                        }
                        str[used++]=first+48;
                        used++;
                        if(second>=100){
                            str[used++]=second/100+48;
                            second%=100;
                            str[used++]=second/10+48;
                            second%=10;
                        }
                        else if(second>=10){
                            str[used++]=second/10+48;
                            second%=10;
                        }
                        str[used++]=second+48;
                        used++;
                        if(third>=100){
                            str[used++]=third/100+48;
                            third%=100;
                            str[used++]=third/10+48;
                            third%=10;
                        }
                        else if(third>=10){
                            str[used++]=third/10+48;
                            third%=10;
                        }
                        str[used++]=third+48;
                        used++;
                        if(fourth>=100){
                            str[used++]=fourth/100+48;
                            fourth%=100;
                            str[used++]=fourth/10+48;
                            fourth%=10;
                        }
                        else if(fourth>=10){
                            str[used++]=fourth/10+48;
                            fourth%=10;
                        }
                        str[used++]=fourth+48;
                        str[used]=0;
                        string pp(str);
                        res.push_back(pp);
                    }
                }
            }
        }
        return res;
    }
};
