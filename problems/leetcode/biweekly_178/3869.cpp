// Source - https://leetcode.com/contest/biweekly-contest-178/
// Date - 2026-04-28

#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution {
private:
    vector<vector<vector<ll>>> memo;
    int MAX = 150;

    set<int> isGood;
    vector<ll> mono;
    bool isPrepared = false;

    bool isGoodInc(int num) {
        int prev = 10;
        while (num > 0) {
            int curDigit = num % 10;
            if (curDigit >= prev) return false;
            num /= 10;
            prev = curDigit;
        }
        return true;
    }

    bool isGoodDec(int num) {
        int prev = -1;
        while (num > 0) {
            int curDigit = num % 10;
            if (curDigit <= prev) return false;
            num /= 10;
            prev = curDigit;
        }
        return true;
    }

    void prepare() {
        for (int i = 1; i <= MAX; i++) {
            if (isGoodInc(i) || isGoodDec(i)) isGood.insert(i);  
        }

        vector<vector<ll>> dec(10);
        dec[9] = {9};
        for (int i = 8; i >= 0; i--) {
            for (int j = i + 1; j < 10; j++) {
                for (ll val : dec[j]) {
                    dec[i].push_back(val * 10 + i);
                    mono.push_back(val * 10 + i);
                }
            }
            dec[i].push_back(i);
        }

        vector<vector<ll>> inc(10);
        inc[1] = {1};
        for (int i = 2; i < 10; i++) {
            for (int j = i - 1; j > 0; j--) {
                for (ll val : inc[j]) {
                    inc[i].push_back(val * 10 + i);
                    mono.push_back(val * 10 + i);
                }
            }
            inc[i].push_back(i);
        }

        sort(mono.begin(), mono.end());
    }

    ll ddp(string& num, int idx, int digitSum, bool tight) {
        if (idx == num.size()) {
            if (isGood.find(digitSum) != isGood.end()) return 1;
            return 0;
        }

        if (memo[tight][idx][digitSum] != -1) return memo[tight][idx][digitSum];

        ll ans = 0;
        int limit = tight ? num[idx] - '0' : 9;
        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && d == limit;
            ans += ddp(num, idx + 1, digitSum + d, newTight);
        }

        return memo[tight][idx][digitSum] = ans;
    }

    ll digit(ll val) {
        string valS = to_string(val);
        memo.assign(2, vector<vector<ll>>(valS.size(), vector<ll>(150, -1)));
        return ddp(valS, 0, 0, true);
    }

public:
    ll countFancy(ll l, ll r) {
        if (!isPrepared) {
            isPrepared = true;
            prepare();
        }

        // digitSum + mono - (mono i digitsum)
        ll ans = digit(r) - digit(l - 1);
        int start = lower_bound(mono.begin(), mono.end(), l) - mono.begin();
        int end = upper_bound(mono.begin(), mono.end(), r) - mono.begin() - 1;

        for (int i = start; i <= end; i++) {
            int num = mono[i];
            int ds = 0;
            while (num > 0) {
                ds += num % 10;
                num /= 10;
            }

            if (isGood.find(ds) == isGood.end()) {
                ans++;
            }
        }
        return ans;
    }
};