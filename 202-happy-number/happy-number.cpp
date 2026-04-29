class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            n = sumofsq(n);
        }
        return n == 1;
    }

    int sumofsq(int n) {
        int sum = 0;

        while (n != 0) {
            int r = n % 10;      // get last digit
            sum = sum + r * r;   // add square
            n = n / 10;          // remove last digit
        }

        return sum;
    }
};