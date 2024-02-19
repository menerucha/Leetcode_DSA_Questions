class Solution
{
public:
    bool isPowerOfTwo(int n)
    { // Since C++20
        return n > 0 && countl_zero((unsigned)n) + countr_zero((unsigned)n) == 31;
    }
};