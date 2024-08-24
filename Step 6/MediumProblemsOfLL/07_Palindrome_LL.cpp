// Link - https://leetcode.com/problems/palindrome-linked-list/description/
// Palindrome Linked List


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
    ListNode* reverseLL(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return node;

        ListNode* newHead = reverseLL(node->next);
        ListNode* front = node->next;
        front->next = node;
        node->next = nullptr;
        return newHead;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* firstHalf = head;
        ListNode* secondHalf = reverseLL(slow);
        ListNode* secondHalfCopy = secondHalf;

        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                reverseLL(slow);
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        reverseLL(slow);
        return true;
    }
};