#include <bits/stdc++.h>

using namespace std;

vector<int> computeLPS(string& pattern) {
    int n = pattern.size();
    vector<int> lps(n);
    int prefLen = 0;
    lps[0] = 0;

    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[prefLen]) {
            lps[i] = ++prefLen;
            i++;
        } else {
            if (prefLen != 0) prefLen = lps[prefLen - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> kmp(string& text, string& pattern) {
    if (pattern.empty()) return {};
    
    vector<int> indexes;
    auto lps = computeLPS(pattern);
    
    int textIdx = 0, patIdx = 0;
    while (textIdx < text.size()) {
        if (pattern[patIdx] == text[textIdx]) {
            patIdx++;
            textIdx++;
            if (patIdx == pattern.size()) {
                indexes.push_back(textIdx - patIdx);
                patIdx = lps[patIdx - 1];
            }
        } else {
            if (patIdx != 0) {
                patIdx = lps[patIdx - 1];
            } else {
                textIdx++;
            }
        }
    }

    return indexes;
}

int main() {
    // --- Test Case 1: Standard Match ---
    string t1 = "ABCABCDABABCDABCDABDE";
    string p1 = "ABCDABD";
    vector<int> res1 = kmp(t1, p1);
    assert(res1.size() == 1);
    assert(res1[0] == 13);
    cout << "Test Case 1 Passed: Standard single match confirmed." << endl;

    // --- Test Case 2: Multiple Overlapping Matches ---
    string t2 = "AAAAA";
    string p2 = "AAA";
    vector<int> res2 = kmp(t2, p2);
    assert(res2.size() == 3);
    assert(res2[0] == 0 && res2[1] == 1 && res2[2] == 2);
    cout << "Test Case 2 Passed: Overlapping matches handled correctly." << endl;

    // --- Test Case 3: No Match Present ---
    string t3 = "MISSISSIPPI";
    string p3 = "MISTER";
    vector<int> res3 = kmp(t3, p3);
    assert(res3.empty());
    cout << "Test Case 3 Passed: Correctly returned empty for no match." << endl;

    // --- Test Case 4: Pattern is Longer than Text ---
    string t4 = "Short";
    string p4 = "LongerThanShort";
    vector<int> res4 = kmp(t4, p4);
    assert(res4.empty());
    cout << "Test Case 4 Passed: Handled pattern > text safely." << endl;

    // --- Test Case 5: Prefixes that Repeat (LPS Stress Test) ---
    string t5 = "ABACABACABACABA";
    string p5 = "ABACABA";
    vector<int> res5 = kmp(t5, p5);
    assert(res5.size() == 3);
    assert(res5[0] == 0 && res5[1] == 4 && res5[2] == 8);
    cout << "Test Case 5 Passed: Repeating prefix logic (LPS) verified." << endl;

    // --- Test Case 6: Empty Strings ---
    string t6 = "Anything";
    string p6 = "";
    vector<int> res6 = kmp(t6, p6);
    assert(res6.empty());
    cout << "Test Case 6 Passed: Empty pattern edge case handled." << endl;

    cout << "\nAll KMP Test Cases Passed Successfully!" << endl;

    return 0;
}