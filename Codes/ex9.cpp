#include <iostream>
#include <string>
using namespace std;
// Function to find all occurrences of pattern P in string S
void findPattern(string S, string P)
{
    int n = S.length(); // Length of string S
    int m = P.length(); // Length of pattern P
    // Loop through the string and check for pattern matches
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        // Check for pattern match
        for (j = 0; j < m; j++)
        {
            if (S[i + j] != P[j])
            {
                break;
            }
        }
        // If the pattern matches, print the starting index
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
        }
    }
}
int main()
{
    string S, P;
    // Input the main string and the pattern
    cout << "Enter the main string S: ";
    getline(cin, S);
    cout << "Enter the pattern P: ";
    getline(cin, P);
    // Find all occurrences of the pattern
    findPattern(S, P);
    return 0;
}