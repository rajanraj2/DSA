// Link - https://leetcode.com/problems/reverse-nodes-in-k-group/
// Reverse Nodes in k-Group


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
    ListNode* kNode(ListNode* node, int k) {
        k--;
        while (k-- && node) {
            node = node->next;
        }
        return node;
    }

    ListNode* reverseLL(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return node;

        ListNode* newHead = reverseLL(node->next);
        ListNode* front = node->next;
        front->next = node;
        node->next = nullptr;
        return newHead;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) return head;

        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        while (temp) {
            ListNode* kthNode = kNode(temp, k);
            if (kthNode == nullptr) {
                if (prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseLL(temp);
            if (temp == head) {
                head = kthNode;
            }
            else {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};