/*
21.合并两个有序链表[Easy]（探索字节跳动——链表与树（1））

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

思路：
放两根指针扫两个链表然后拼接就行，每次比较两个头结点，较小值拿出来接在新的链表上。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode *head = new ListNode(-1);
        ListNode *l1ptr = l1, *l2ptr = l2, *tmpptr = head;
        while(l1ptr!=NULL && l2ptr!=NULL){
            if(l1ptr->val<l2ptr->val){
                tmpptr->next = l1ptr;
                l1ptr = l1ptr->next;
                tmpptr = tmpptr->next;
            }
            else{
                tmpptr->next = l2ptr;
                l2ptr = l2ptr->next;
                tmpptr = tmpptr->next;
            }
        }
        if(l1ptr==NULL){
            tmpptr->next = l2ptr;
        }
        else if(l2ptr==NULL){
            tmpptr->next = l1ptr;
        }
        l1 = head->next;
        delete head;
        return l1;
    }
};
