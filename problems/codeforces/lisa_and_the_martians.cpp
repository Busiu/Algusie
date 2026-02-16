// Link - https://codeforces.com/contest/1851/problem/F
// Source - https://usaco.guide/silver/intro-bitwise
// Date - 2026-02-11

#include <bits/stdc++.h>

#define ll long long
using namespace std;

// TODO: Trie that uses int[] instead of vector
// TODO: Trie implementation from USACO -> no pointers! Let's see how memory will change
struct TrieNode {
    int idx;
    vector<TrieNode*> children;
    TrieNode() {
        idx = -1;
        children.assign(2, nullptr);
    }

    void put(int num, int k, int idx) {
        TrieNode* tmp = this;
        for (int i = k - 1; i >= 0; i--) {
            int ch = ((num >> i) & 1);
            if (tmp->children[ch] == nullptr) tmp->children[ch] = new TrieNode();
            tmp = tmp->children[ch]; 
        }
        tmp->idx = idx;
    }

    int findBest(int num, int k) {
        TrieNode* tmp = this;
        for (int i = k - 1; i >= 0; i--) {
            int ch = ((num >> i) & 1);
            if (tmp->children[ch] != nullptr) tmp = tmp->children[ch];
            else tmp = tmp->children[(ch + 1) % 2];
        }
        return tmp->idx;
    }
};

string toBinary(int n, int k) {
    // TODO: write down easy method to change int to binary representation of length k.
    string s = bitset<32>(n).to_string();

    // cout << s.substr(s.size() - k) << endl;

    return s.substr(s.size() - k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<int, int> bestPair = {0, 1};
        int minXor = (1 << k);

        TrieNode* trie = new TrieNode();        
        trie->put(a[0], k, 0);

        for (int i = 1; i < n; i++) {
            int idx = trie->findBest(a[i], k);
            // TODO : if ((a[i] ^ a[idx]) < minXor) is different than if (a[i] ^ a[idx] < minXor)
            if ((a[i] ^ a[idx]) < minXor) {
                minXor = a[i] ^ a[idx];
                bestPair = {idx, i};
            }
            trie->put(a[i], k, i);
        }

        int x = (1 << k) - 1;
        for (int i = 0; i < k; i++) {
            x ^= a[bestPair.first] & (1 << i);
        }

        cout << bestPair.first + 1 << " " << bestPair.second + 1 << " " << x << endl;
    }

    return 0;
}