class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long ans = 0;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            int T = target - arr[i];
            int j = i + 1, k = n - 1;

            while (j < k) {
                if (arr[j] + arr[k] < T) {
                    j++;
                } 
                else if (arr[j] + arr[k] > T) {
                    k--;
                } 
                else {
                    // arr[j] + arr[k] == T
                    if (arr[j] != arr[k]) {
                        int leftCount = 1, rightCount = 1;

                        while (j + 1 < k && arr[j] == arr[j + 1]) {
                            leftCount++;
                            j++;
                        }
                        while (k - 1 > j && arr[k] == arr[k - 1]) {
                            rightCount++;
                            k--;
                        }

                        ans += (long long)leftCount * rightCount;
                        ans %= MOD;

                        j++;
                        k--;
                    } 
                    else {
                        int count = k - j + 1;
                        ans += (long long)count * (count - 1) / 2;
                        ans %= MOD;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
