class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        std::string str1;
        for (const auto &word : word1)
        {
            str1 += word;
        }
        std::string str2;
        for (const auto &word : word2)
        {
            str2 += word;
        }
        return str1 == str2;
    }
    int main()
    {
        std::vector<std::string> word1 = {"ab", "c"};
        std::vector<std::string> word2 = {"a", "bc"};
        bool result = arrayStringsAreEqual(word1, word2);
        if (result)
        {
            std::cout << "The two arrays represent the same string.\n";
        }
        else
        {
            std::cout << "The two arrays do not represent the same string.\n";
        }
        return 0;
    }
};