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
    int pairSum(ListNode* head) {
        if(!head) return 0;

        int count = 0;
        int size = 1;
        int maxSum = 0;
        ListNode *slow = head, *fast = head->next;
        unordered_map<int, int> sum_map;
        sum_map[count] = slow->val;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            count++;
            sum_map[count] = slow->val;
        }
        slow = slow->next;
        while(slow && count>=0){
            sum_map[count] += slow->val;
            maxSum = max(maxSum, sum_map[count]);

            count--;
            slow = slow->next;
        }

        return maxSum;
    }
};