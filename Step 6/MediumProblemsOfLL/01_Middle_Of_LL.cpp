// Link - https://leetcode.com/problems/middle-of-the-linked-list/
// Middle of the Linked List


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

// Alternative method 2 

// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while (fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
// };




// Aternative method 1 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        int mid = (n / 2) + 1;

        temp = head;
        while (mid--) {
            if (mid == 0) break;
            temp = temp->next;
        }
        return temp;

    }
};