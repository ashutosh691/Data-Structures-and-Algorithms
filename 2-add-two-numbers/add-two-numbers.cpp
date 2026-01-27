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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        queue<int> q;
        while(head1) {
            q.push(head1->val);
            head1 = head1->next;
        }
        ListNode dummy(0);
        ListNode* new_head = &dummy;
        int carry = 0;
        while (head2 || !q.empty()) {
            int val1 = 0, val2 = 0;
            if (!q.empty()) {
                val1 = q.front();
                q.pop();
            }
            if (head2) {
                val2 = head2->val;
                head2 = head2->next;
            }
            int temp = val1 + val2 + carry;
            carry = temp / 10;
            new_head->next = new ListNode(temp % 10);
            new_head = new_head->next;
        }
        if (carry) new_head->next = new ListNode(carry);
        return dummy.next;
    }
};