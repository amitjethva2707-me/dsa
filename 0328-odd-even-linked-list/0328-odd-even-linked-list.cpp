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
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL)
            return head;

        vector<int> arr;

        ListNode* temp = head;
        int pos = 1;

        // Store odd positions
        while(temp){
            if(pos % 2 == 1)
                arr.push_back(temp->val);

            temp = temp->next;
            pos++;
        }

        temp = head;
        pos = 1;

        // Store even positions
        while(temp){
            if(pos % 2 == 0)
                arr.push_back(temp->val);

            temp = temp->next;
            pos++;
        }

        temp = head;
        int i = 0;

        // Copy back
        while(temp){
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};