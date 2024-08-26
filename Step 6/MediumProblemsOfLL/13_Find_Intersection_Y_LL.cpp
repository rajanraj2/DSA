// Link - https://leetcode.com/problems/intersection-of-two-linked-lists/
// Intersection of Two Linked Lists


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Alternative 3 - optimised

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (temp1 == temp2) return temp1;
            if (temp1 == nullptr) temp1 = headB;
            if (temp2 == nullptr) temp2 = headA;
        }
        return temp1;
    }
};




// Alternative 2 - move greater equal to smaller head

// class Solution {
// private:
//     ListNode* collisionPoint(ListNode* temp1, ListNode* temp2, int d) {
//         while (d--) {
//             temp2 = temp2 ->next;
//         }

//         while (temp1 != temp2) {
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }

//         return temp1;
//     }

// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if (headA == nullptr || headB == nullptr) return nullptr;

//         ListNode* temp1 = headA;
//         ListNode* temp2 = headB;
//         int l1 = 0, l2 = 0;
//         while (temp1) {
//             l1++;
//             temp1 = temp1->next;
//         }
//         while (temp2) {
//             l2++;
//             temp2 = temp2->next;
//         }

//         if (l1 < l2) {
//             return collisionPoint(headA, headB, l2 - l1);
//         }
//         else {
//             return collisionPoint(headB, headA, l1 - l2);
//         }
//     }
// };




// Alternative 3 - brute

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         map<ListNode*, int> mpp;

//         ListNode* temp1 = headA;
//         ListNode* temp2 = headB;

//         while (temp1) {
//             mpp[temp1] = 1;
//             temp1 = temp1->next;
//         }

//         while (temp2) {
//             if (mpp.find(temp2) != mpp.end()) return temp2;
//             temp2 = temp2->next;
//         }

//         return nullptr;
//     }
// };
