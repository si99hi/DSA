class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        
        long long x = 0;
        int sum = 0;
        int temp = n;
        int digits[10];
        int count = 0;
        
        while (temp > 0) {
            int digit = temp % 10;
            if (digit != 0) {
                digits[count++] = digit;
                sum += digit;
            }
            temp /= 10;
        }
        
        for (int i = count - 1; i >= 0; i--) {
            x = x * 10 + digits[i];
        }
        
        return x * sum;
    }
};