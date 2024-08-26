// Link - https://leetcode.com/problems/linked-list-cycle/description/
// Linked List Cycle 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Alternate method 2 : fast & slow pointer

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }

        return false;
    }
};




// Alternate method 1 : hashing

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if (head == nullptr || head->next == nullptr) return false;

//         map<ListNode*, int> mpp;

//         ListNode* temp = head;

//         while (temp) {
//             if (mpp.find(temp) != mpp.end()) {
//                 return true;
//             }
//             mpp[temp] = 1;
//             temp = temp->next;
//         }

//         return false;
//     }
// };