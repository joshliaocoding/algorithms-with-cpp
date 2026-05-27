#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function to find the length of the Longest Common Subsequence
int lcs(const std::string &text1, const std::string &text2)
{
    int m = text1.length();
    int n = text2.length();

    // Create a 2D vector to store the dp table
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Build the dp table in bottom-up fashion
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    std::string s1 = "AGGTAB";
    std::string s2 = "GXTXAYB";

    std::cout << "String 1: " << s1 << std::endl;
    std::cout << "String 2: " << s2 << std::endl;

    int length = lcs(s1, s2);

    std::cout << "Length of Longest Common Subsequence: " << length << std::endl;

    return 0;
}