class Solution {
public:
    /*
        possible maximum amplified number 10^n - 1 = 999999...99 ---> 81 * n
        solve 10^n - 1 == 81 * (n-1), if n-->larget then lhs is greater than rhs.
        the solutions are x = 0, x = 2.266.
        if n < 3 then  999 > 81 * 3 = 243
         n = 2, 99 < 162
         --> this operation is not diverse. --> convergent or oscilate.
         
    */
    bool isHappy(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        int fast = n;
        int slow = n;
        do {
          slow = tmp(slow);
          fast = tmp(tmp(fast));
          
        } while(slow != fast);
        return slow == 1;　// convergent 
    }   
    
    int tmp(int n) {
        int ret = 0;
        while (n != 0) {
            int x = n % 10;
            ret += x * x;
            n /= 10;
        }
        return ret;
    }
};
