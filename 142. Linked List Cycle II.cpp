/*
142.环形链表II[Medium]（探索字节跳动——链表与树（5））

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

pos只是示例输入，不是函数的入口参数 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

原图-4节点指向2

示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

原图2节点指向1

示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

原图没有任何箭头

思路：
先用快慢指针判有没有环，快指针每次走2步，慢指针走1步，如果有环那么快慢指针迟早会指向同一个节点，如果没有环那快指针最后会指向NULL

→如果有环那么快慢指针迟早会指向同一个节点？
如果有环，快慢指针都会走到环内，在环内由于每次步数只差1，那么慢指针一定会被快指针追上并来到同一个节点处

有环的时候，先走到两指针相遇的地方。

→第一次相遇时慢指针一定没有绕完环一圈
当慢指针来到入口时，假设快指针刚好不在入口（在入口的话直接相遇了还是没绕一圈），那么
快指针会在环内某个位置，设环长度s，快指针离环入口距离为d（d<s），那它离慢指针的距离就是d，要追上慢指针就要走2*d步
此时慢指针走了d步，d<s，因此慢指针没有走完一圈，他们第一次相遇的位置距离环入口距离为s-d

假设head到环入口的距离为a，环长度为s，第一次相遇时慢指针在环内走了d步（0<=d<s）
那么第一次相遇时，慢指针走过的距离为a+d，快指针走过的距离就是2*(a+d)=a+d+ks（k是正整数，快指针在与慢指针相遇时已经绕环圈数）→a+d=ks
慢指针离环入口距离为s-d，由于a=ks-d=(k-1)s+(s-d)，那么有a的长度等于s的倍数加上慢指针离环入口的距离
那么把快指针拿到头结点，每次走1步，走到环入口时走了a=(k-1)s+(s-d)步，慢指针也走了a步
慢指针走s-d步时来到环入口，然后和快指针相遇时又走了(k-1)s步，刚好绕环k-1圈，所以慢指针走a步也是走到环入口
所以快慢指针此时相遇的地方就是环入口

时间复杂度O(2a+d),a为head到环入口距离，d为快慢指针第一次相遇位置与环入口的偏移量（可近似看成环长度）

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return NULL;
        if(head->next->next==NULL)return NULL;
        ListNode *fast=head->next->next, *slow=head->next;
        while(fast!=NULL && fast!=slow){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        if(fast==NULL)return NULL;
        //来到这的话就是有环
        fast=head;
        while(fast!=slow){
            //可以肆无忌惮地走不用判NULL
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
