/*
234.回文链表[Easy]

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false

示例 2:

输入: 1->2->2->1
输出: true

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

思路（非进阶）：
使用一个缓存数组，扫描链表时把值放到缓存数组中，同时调整链表方向，一遍扫描后，缓存数组中按顺序保存了原链表的值，同时链表被完全反转
第二次扫描新链表，扫描时将值和缓存数组中的值逐一比对，有不同的返回false。扫到最后完全一致则返回true。

时间复杂度O(n)，空间复杂度O(n)。

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)return true;     //长为0的链表true
        if(head->next==NULL)return true;//长为1的链表true
        
        //长为2以上的链表？
        
        vector<int> valueList;
        ListNode *cur = head, *pre = head, *nxt = head->next;
        while(nxt!=NULL){
            pre=cur;
            valueList.push_back(cur->val);
            cur=nxt;
            nxt=cur->next;
            cur->next=pre;
        }
        head->next=NULL;
        head=cur;
        //链表已反转
        
        cur = head, pre = head, nxt = head->next;
        int counter=0;
        while(nxt!=NULL){
            pre=cur;
            if(cur->val!=valueList[counter++])return false;
            cur=nxt;
            nxt=cur->next;
            cur->next=pre;
        }
        head->next=NULL;
        return true;
    }
};

/*
进阶思路：
如果是回文链表，那么在中点处往前和往后扫应该会得到相同的结果
使用快慢指针找到链表的中点，快慢指针扫描的同时也要反转前半部分链表。
当快指针去到NULL时，如果链表节点数是奇数，慢指针会来到正中间，如果是偶数，将来到下标n/2-1的位置（n为节点个数，下标初始0）

然后判断回文，如果是奇数，前半部分的指针先挪一个位置（正中间的数对判断回文无意义）
然后双指针同时移动，比较大小，有不同的返回false。当双方都指向NULL时表示完全回文，返回true;

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)return true;     //长为0的链表true
        if(head->next==NULL)return true;//长为1的链表true
        
        //长为2以上的链表？
        
        ListNode *fast = head, *slow = head;
        ListNode *pre = head, *cur = head, *nxt = head->next;
        bool odd = false;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                if(fast!=NULL){
                    slow = slow->next;
                
                    pre = cur;
                    cur = nxt;
                    nxt = nxt->next;
                    cur->next = pre;
                }
            }
            else odd=true;
            //画图可知如果链表节点数量为奇数，最终slow会指到正中间的节点。如果为偶数会指到下标为n/2-1的节点（从0开始）
            //链表被一分为二，cur往后是前半截，nxt往后是后半截。
        }
        head->next=NULL;
        if(odd)cur=cur->next;
        while(cur!=NULL && nxt!=NULL){
            printf("cur=%d,nxt=%d\n",cur->val,nxt->val);
            if(cur->val != nxt->val)return false;
            cur=cur->next;
            nxt=nxt->next;
        }
        return true;
    }
};
