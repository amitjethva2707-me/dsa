/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        if(k == 0){
            return head;
        }
        ListNode* tail = head;
        int len =1 ;
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }
        if(k%len == 0){
            return head;
        }
        k = k%len;
        tail->next = head;
        ListNode* newtail = head;
        for(int i =0;i<len-k-1;i++){
            newtail = newtail->next;
        }
        head = newtail->next;
        newtail->next = NULL;
        return head;
    }
};