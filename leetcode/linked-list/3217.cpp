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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hash(nums.begin(), nums.end());
        ListNode dummy(0, head);
        ListNode* cur = &dummy;

        while (cur->next) {
            ListNode* nxt = cur->next;
            if (hash.contains(nxt->val))
                cur->next = nxt->next;
            else
                cur = nxt;
        }
        return dummy.next;
    }
};