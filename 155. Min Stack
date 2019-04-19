/*
155.最小栈[Easy]（探索字节跳动——数据结构（1））

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

    push(x) -- 将元素 x 推入栈中。
    pop() -- 删除栈顶的元素。
    top() -- 获取栈顶元素。
    getMin() -- 检索栈中的最小元素。

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

思路：用2个栈，一个原始栈，一个记录当前最小值的栈
每次push值，原始栈按栈一般功能那样push值，最小栈则用来push当前的最小记录，方法是待push的值和最小栈栈顶元素比较，push较小的元素进最小栈
每次pop值，两个栈一起弹一个数出栈
top函数返回原始栈的值
getMin直接取最小栈的栈顶元素，时间复杂度O(1)

*/

class MinStack {
    vector<int> originStack;
    vector<int> min;
public:
    
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        originStack.push_back(x);
        if(min.empty())min.push_back(x);
        else if(x<min[min.size()-1])min.push_back(x);
        else min.push_back(min[min.size()-1]);
    }
    
    void pop() {
        originStack.erase(originStack.begin()+originStack.size()-1);
        min.erase(min.begin()+min.size()-1);
    }
    
    int top() {
        return originStack[originStack.size()-1];
    }
    
    int getMin() {
        return min[min.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
