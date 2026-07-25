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
        int len1 = 0;
        ListNode* temp1 = headA;
        while(temp1 != NULL){
            len1++;
            temp1 = temp1->next;
        }
        int len2 = 0;
        ListNode* temp2 = headB;
        while(temp2 != NULL){
            len2++;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        int skip = abs(len1-len2);
        if(len1 < len2){
            while(skip){
                skip--;
                temp2 = temp2->next;
            }
        } else {
            while(skip){
                skip--;
                temp1 = temp1->next;
            }
        }
        while(temp1 && temp2){
            if(temp1 == temp2){
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;

    }
};