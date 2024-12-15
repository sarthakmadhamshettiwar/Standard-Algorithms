// For "AABAACAABAA"
// [0, 1, 0, 1, 2, 0, 1, 2, 0, 1, 2]

vector<int> computeLPS(const string& s) {
    int n = s.length();
    vector<int> lps(n, 0); // Initialize LPS array with zeros

    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            // Characters match
            len++;
            lps[i] = len;
            i++;
        } else {
            // Characters do not match
            if (len != 0) {
                // Fall back to the previous LPS value
                len = lps[len - 1];
            } else {
                // No previous LPS, set to 0
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

/*
Key Observations:
Fallback happens when a mismatch occurs.

Example: At index 8 (AABAACAAB), len=2 (from previous matching). When s[8]='B' mismatches s[2]='B', fallback occurs to lps[len-1] = lps[0] = 0.
lps[len-1] provides the next position to check.

This ensures that we don't start comparing from the beginning of the string but from the next possible prefix-suffix match.
Efficient handling of mismatches:

Instead of comparing the whole prefix again, fallback reduces the unnecessary comparisons.


Why This Example Helps?
The string contains repetitive patterns (AABA) that illustrate multiple successful matches and mismatches.
Fallbacks happen at various positions, showing how len reduces systematically.
It demonstrates the balance between direct matches and fallback during the computation of the LPS array.
*/
