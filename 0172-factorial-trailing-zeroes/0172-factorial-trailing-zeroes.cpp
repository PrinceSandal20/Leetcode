class Solution {
public:
    int trailingZeroes(int n) {
         //we just have to count number of 5 because zero can be formed by multiplying 5 and 2;
         return n==0?0:n/5+trailingZeroes(n/5);
    }
};