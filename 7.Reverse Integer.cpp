/*
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

思路：如果不是10位数，直接反就行
如果是10位数，看是否溢出，末尾超3肯定溢出，否则先试着反转，2开头大于MAX_INT的由于转换int后全部落到负数区，可以以负数作为溢出判定
如果不溢出（反转后是正数）就返回反转结果
原来是负数作一定处理
*/
class Solution {
public:
    int revPlus(int x){
        int rev=0,xtmp=x;
        if(x<1000000000){
            while(xtmp>0){
                rev=rev*10+xtmp%10;
                xtmp=xtmp/10;
            }
        }
        else{
            if(xtmp%10>=3)return 0; //int型十亿位不能超过2
            else{
                while(xtmp>0){
                    rev=rev*10+xtmp%10;
                    xtmp=xtmp/10;
                }
                //有可能溢出也可能不溢出，先按照反转规则反转再判断
                if(rev<0)return 0;  //现在溢出值范围只可能是2147483648到2999999991之间用int表示肯定是负数
            }
        }
        return rev;
    }
    int reverse(int x) {
        if(x>0){
            return revPlus(x);
        }
        else{
            return -revPlus(-x);
        }
        return 0;
    }
};
