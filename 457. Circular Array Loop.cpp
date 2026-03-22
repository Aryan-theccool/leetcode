// class Solution {
// public:
//     int nextIndex(vector<int>& nums, int i) {
//         int n = nums.size();
//         return ((i + nums[i]) % n + n) % n; 
//     }

//     bool circularArrayLoop(vector<int>& nums) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0) continue;

//             int slow = i, fast = i;
//             bool isForward = nums[i] > 0;

//             while (true) {
//                 int nextSlow = nextIndex(nums, slow);

//                 int nextFast = nextIndex(nums, fast);
//                 nextFast = nextIndex(nums, nextFast);

//                 if ((nums[nextSlow] > 0) != isForward ||
//                     (nums[nextFast] > 0) != isForward) {
//                     break;
//                 }

//                 slow = nextSlow;
//                 fast = nextFast;

//                 if (slow == fast) {
                    
//                     if (slow == nextIndex(nums, slow)) {
//                         break;
//                     }
//                     return true;
//                 }
//             }

//             int j = i;
//             while ((nums[j] > 0) == isForward) {
//                 int next = nextIndex(nums, j);
//                 nums[j] = 0;
//                 j = next;
//                 if (j == i) break;
//             }
//         }

//         return false;
//     }
// };
class Solution {
public:
    int getNext(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            int slow = i, fast = i;
            bool forward = nums[i] > 0;

            while (true) {
                int nextSlow = getNext(nums, slow);

                int nextFast = getNext(nums, fast);
                if ((nums[nextFast] > 0) != forward) break;

                nextFast = getNext(nums, nextFast);

                if ((nums[nextSlow] > 0) != forward ||
                    (nums[nextFast] > 0) != forward) {
                    break;
                }

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {
                    if (slow == getNext(nums, slow)) break;
                    return true;
                }
            }

            // 🔥 FIXED marking loop
            int j = i;
            while (nums[j] != 0 && (nums[j] > 0) == forward) {
                int next = getNext(nums, j);
                nums[j] = 0;
                j = next;
            }
        }

        return false;
    }
};