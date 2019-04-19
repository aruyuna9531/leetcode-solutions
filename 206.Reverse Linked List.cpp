/*
206.反转链表[Easy]（探索字节跳动——链表与树（2））

反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

三个指针，pre代表前一个节点，cur代表当前结点，nxt代表下一个节点

每次操作，cur的next指向pre，然后三个指针分别移到其下一个节点。

（目前Leetcode有疑似时间超限的bug，在return前面一行debug是有stdout的）

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
        ListNode *pre = head, *cur = head, *nxt = head->next;
        while(nxt!=NULL){
            cur->next = pre;
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = pre;
        return cur;
    }
};
