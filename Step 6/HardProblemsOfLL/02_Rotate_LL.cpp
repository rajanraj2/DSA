// Link - https://leetcode.com/problems/rotate-list/description/
// Rotate List


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
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            len++;
            tail = tail->next;
        }
        k = k % len;
        tail->next = head;

        ListNode* temp = head;
        int step = len - k - 1;
        while (step != 0) {
            temp = temp->next;
            step--;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};