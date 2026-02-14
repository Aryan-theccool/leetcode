class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        sort(arr, arr + n);
        long long ans = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                long long currSum = arr[i] + arr[left] + arr[right];

                if (currSum < sum) {
                    ans += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }

        return ans;
    }
};