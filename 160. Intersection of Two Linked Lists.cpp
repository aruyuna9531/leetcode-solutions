/*
160. 相交链表[Easy]（探索字节跳动——链表与树（6））

编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。

 

示例 1：



输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

思路：
如果两链相交，把尾巴和某条链表头部拼接，就变成了寻找有环链表的环入口问题（第142题）
环入口就是链的第一个交点，找到后把原来拼上去的尾巴拆回来

时间复杂度O(n)，空间复杂度O(1)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL)return NULL;
        if(headB==NULL)return NULL;
        ListNode *tail = headA;
        while(tail->next!=NULL)tail=tail->next;
        //随便连个头部
        tail->next=headA;
        //变成了带环链表，用寻找环入口的方式找到相交节点。（第142题原题）
        ListNode *tmp = detectCycle(headB);
        //A链需要恢复原状
        tail->next=NULL;
        //如果返回了NULL，表示链表B探到了NULL，此时两条链表没有相交节点，A链恢复原状后返回NULL，否则tmp指向了相交节点，返回tmp（总之就是返回tmp）
        return tmp;
    }
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
