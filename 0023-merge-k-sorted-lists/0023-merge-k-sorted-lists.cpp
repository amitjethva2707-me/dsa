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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minheap;

        for (auto list : lists) {
            if (list != nullptr) {
                minheap.push(list);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!minheap.empty()) {
            ListNode* node = minheap.top();
            minheap.pop();
            temp->next = node;
            temp = temp->next;
            if (node->next != NULL) {
                minheap.push(node->next);
            }
        }

        return dummy->next;
    }
};