/*
148.排序链表[Medium]（探索字节跳动——链表与树（4））

在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

思路：
O(nlogn)复杂度的排序算法有快速排序、堆排序、归并排序。
快速排序需要一个后往前的辅助指针，单链表无法反向查找，所以不能使用快排
堆排序需要构堆，而构堆需要树，单链表没有2个指针无法构树
归并排序是可以使用的

首先找中点，使用快慢指针找中点，然后从中点处将链表一分为二，然后对着两条链表分别再拆分进行归并，拆到不能拆为止
合并过程就是2个有序链表的合并，第21题原题，可直接引用代码

时间复杂度O(nlogn)，空间复杂度O(1)（只增加了快慢指针）

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
    ListNode* sortList(ListNode* head) {
        return diverse(head);
    }
    ListNode* diverse(ListNode *head){
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
        ListNode *fast = head, *slow = head;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                if(fast!=NULL)slow = slow->next;
            }
        }
        //退出循环后从slow后面分割链表
        ListNode *tmp = slow->next;
        slow->next = NULL;
        slow = tmp;
        head = diverse(head);
        slow = diverse(slow);
        return merge(head, slow);
    }
    
    ListNode* merge(ListNode *l1, ListNode *l2){
        //合并2个有序链表（第21题代码）
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
