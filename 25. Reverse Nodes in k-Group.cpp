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
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* curr=head;
//         ListNode* temp=curr;
//         for(int i=0;i<k;i++){
//             if(k==nullptr){
//                 return head;
//             }
//             temp=temp->next;
//         }
//         ListNode* prev=nullptr;
//         ListNode* next=nullptr;
//         ListNode* temp=curr;
//         for(int i=0;i<k;i++){
//             next=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=next;
//         }


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (!head || k == 1)
            return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;          // same role as before
        ListNode* newHead = head;         // to update head after first reversal

        while (curr != nullptr) {

            // Step 1: Check if k nodes exist
            ListNode* temp = curr;
            int count = 0;

            while (temp != nullptr && count < k) {
                temp = temp->next;
                count++;
            }

            if (count < k)
                break;   // not enough nodes

            // Step 2: Reverse k nodes (same as reverseBetween)
            ListNode* before = prev;      // node before group
            ListNode* start = curr;       // first node of group

            ListNode* tempPrev = nullptr;
            ListNode* next = nullptr;

            count = k;

            while (count--) {
                next = curr->next;
                curr->next = tempPrev;
                tempPrev = curr;
                curr = next;
            }

            // Step 3: Reconnect

            if (before != nullptr)
                before->next = tempPrev;
            else
                newHead = tempPrev;   // first group updates head

            start->next = curr;

            // Move prev forward
            prev = start;
        }

        return newHead;
    }
};
