/*
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

思路：两条老链的两个数拿出来相加，加上进位值，把结果的个位加入新链的值里，如果结果超过9就把进位记录为1，否则记录为0。进位值最初为0，代表个位相加之前没有进位。用例：5555+6666
如果有一条链指针指向了空，那么代表该链已经计算完毕，此时如果另一个链还有结点，直接把这个结点值加上进位接到新链上，然后这条链剩余部分也一样。用例：240+40，899+1
如果两条链的指针都指向了空，但进位还是1的时候，新链应该在结尾补上一个1结点。用例：9999+1，5000+5000
如果有一条输入链为空，返回另一条（加0结果为0）。用例：999+（空）
时间复杂度O(n)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode *head=new ListNode((l1->val+l2->val)%10);
        ListNode *resPointer=head,*l1P=l1,*l2P=l2;
        int up=(l1P->val+l2P->val>=10?1:0);
        while(l1P->next!=NULL && l2P->next!=NULL){
            resPointer->next=new ListNode((l1P->next->val+l2P->next->val+up)%10);
            resPointer=resPointer->next;
            l1P=l1P->next;
            l2P=l2P->next;
            up=(l1P->val+l2P->val+up>=10?1:0);
        }
        if(l1P->next==NULL)while(l2P->next!=NULL){
            resPointer->next=new ListNode((l2P->next->val+up)%10);
            resPointer=resPointer->next;
            l2P=l2P->next;
            up=(l2P->val+up>=10?1:0);
        }
        if(l2P->next==NULL)while(l1P->next!=NULL){
            resPointer->next=new ListNode((l1P->next->val+up)%10);
            resPointer=resPointer->next;
            l1P=l1P->next;
            up=(l1P->val+up>=10?1:0);
        }
        if(up==1)resPointer->next=new ListNode(1);
        return head;
    }
};
