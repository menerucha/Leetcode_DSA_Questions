<<<<<<< HEAD
class Solution
{
public:
    bool isPowerOfTwo(int n)
    { // Since C++20
        return n > 0 && countl_zero((unsigned)n) + countr_zero((unsigned)n) == 31;
    }
=======
class Solution
{
public:
    bool isPowerOfTwo(int n)
    { // Since C++20
        return n > 0 && countl_zero((unsigned)n) + countr_zero((unsigned)n) == 31;
    }
>>>>>>> 09e55041003f5eaf0f7cdd521aa3af4aee03d086
};