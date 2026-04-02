class Solution {
    int mod = 1000000007;
public:
    int countGoodNumbers(long long n) {
        if (n == 1) return 5;
        
        long long even = (n+1)/2;
        long long odd = n/2;
        long long num = (power(5, even) * power(4, odd)) % mod;

        return num;
    }

    long long power(long long x, long long n){
        if (n == 0) return 1;

        long long half = power(x, n / 2);
        long long result = (half * half) % mod;

        if (n % 2 == 1)
            result = (result * x) % mod;

        return result;
    }
};