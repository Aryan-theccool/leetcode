Explore
Problems
Contest
Discuss
More


0
0Streaks
Get Started Early!
DCC Badge

avatar
Avatar
aryanbhadoria111111
Access all features with our Premium subscription!
myLists
My Lists
notebook
Notebook
progress
Progress
points
Points
Try New Features
Orders
My Playgrounds
Settings
Appearance
Sign Out
Submissions Detail -
Reverse Linked List II
Accepted
44 / 44 testcases passed
aryanbhadoria111111
aryanbhadoria111111
submitted at Feb 17, 2026 11:13

Editorial

Solution
Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
11.16
MB
Beats
71.19%
Analyze Complexity
Code
C++
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if(head==nullptr){
//             return nullptr;
//         }
//         if(left==right){
//             return head;
//         }
//         ListNode* t=head;
//         ListNode* before=nullptr;
//         int pos=1;
//         ListNode* curr=t;
//         ListNode* prev=nullptr;
//         int time=right-left+1;
//         while(t!=nullptr){
//           if(pos<left){
//             pos++;
//             t=t->next;
//             before=t;
//           }
//         }
//           while(time--){    
//   ListNode*nex=curr->next;
//            curr->next=prev;
//            prev=curr;
//            curr=nex;
          
//           }
//              t->next=curr;
//         before->next=prev;
    
//         return head;
      
//     }
// };
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (!head || left == right)
            return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        int pos = 1;

        while (pos < left) {
            prev = curr;
            curr = curr->next;
            pos++;
        }

    

        ListNode* before = prev;        
        ListNode* start = curr;         

        ListNode* next = nullptr;
        ListNode* tempPrev = nullptr;

        int count = right - left + 1;

        while (count--) {
            next = curr->next;
            curr->next = tempPrev;
            tempPrev = curr;
            curr = next;
        }


        if (before != nullptr)
            before->next = tempPrev;
        else
            head = tempPrev;   

        start->next = curr;

        return head;
    }
};

View less
 
Write your notes here
Select related tags
0/5
Back to Problem
Copyright © 2026 LeetCode
Help Center
Jobs
Bug Bounty
Assessment
Students
Terms
Privacy Policy
United States
United States
