class Solution {
public:
   int nthUglyNumber(int n) {
    vector<long long> ugly(n);  
    ugly[0] = 1; // First ugly number

    int i2 = 0, i3 = 0, i5 = 0;

    for (int i = 1; i < n; i++) {
        long long next2 = ugly[i2] * 2;
        long long next3 = ugly[i3] * 3;
        long long next5 = ugly[i5] * 5;

        long long nextUgly = min({next2, next3, next5});
        ugly[i] = nextUgly;

        if (nextUgly == next2) i2++;
        if (nextUgly == next3) i3++;
        if (nextUgly == next5) i5++;
    }

    return ugly[n - 1];
}
};