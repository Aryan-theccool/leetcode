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
//  void reverse(ListNode* head,int times){
//  ListNode* curr=head;
//  ListNode* prev=nullptr;
//  while(times--){
//     ListNode* nex=curr->next;
//     curr->next=prev;
//     prev=curr;
//     curr=nex;
//  }
//  return ;

// }
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head==nullptr){
//             return nullptr;
//         }
//         int size=2;
//         ListNode* left=head;
//         ListNode* res=nullptr;
//         ListNode* prevleft=nullptr;
//         ListNode* right;

//         while(true){
//             right=left;
//            for(int i=0;i<size-1;i++){
//             if(right==nullptr){
// break;
// right=right->next;  

//             }
//       if(right){
//         ListNode* nextleft=right->next;
//         reverse(left,size);
      
//         if(prevleft)
//             prevleft->next=right;
//             prevleft=left;
        
//       if(res==nullptr){
//         res=right;
//         left=nextleft;

//       }
//         }else{
//             if(prevleft){
//                 prevleft->next=left;
//             }
//             if(res==nullptr){
//                 res=left;
//             }
//          }
//          break;
//            }
        
//         return res;
//     }
// };
void reverse(ListNode* head, int times){
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while(times-- && curr){
        ListNode* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        int size = 2;
        ListNode* left = head;
        ListNode* res = nullptr;
        ListNode* prevleft = nullptr;
        ListNode* right;

        while(left){

            right = left;

            // check if 2 nodes exist
            for(int i = 1; i < size; i++){
                if(right == nullptr){
                    break;
                }
                right = right->next;
            }

            if(right == nullptr){
                if(prevleft){
                    prevleft->next = left;
                }
                if(res == nullptr){
                    res = left;
                }
                break;
            }

            ListNode* nextleft = right->next;

            reverse(left, size);

            if(prevleft){
                prevleft->next = right;
            }

            if(res == nullptr){
                res = right;
            }

            left->next = nextleft;

            prevleft = left;
            left = nextleft;
        }

        return res;
    }
};
