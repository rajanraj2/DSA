// Link - https://leetcode.com/problems/sort-list/description/
// Sort List


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
private:
    ListNode* findMid(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;

        while (left && right) {
            if (left->val < right->val) {
                res->next = left;
                res = left;
                left = left->next;
            }
            else {
                res->next = right;
                res = right;
                right = right->next;
            }
        }

        if (left) res->next = left;
        else res->next = right;

        return dummyNode->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* mid = findMid(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = nullptr;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return merge(leftHead, rightHead);
    }
};