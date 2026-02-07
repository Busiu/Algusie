// Link - https://codeforces.com/contest/1349/problem/A
// Source - https://usaco.guide/gold/divisibility
// Date - 2026-01-31

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define INF 2147483647
#define LL_INF 9223372036854775807

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int MAX_VAL = 2e5 + 10;

int largestPrime[MAX_VAL];

void prep() {
    memset(largestPrime, 0, sizeof(largestPrime));
    for (int i = 2; i < MAX_VAL; i++) {
        if (largestPrime[i] != 0) continue;
        for (int j = i; j < MAX_VAL; j += i) {
            largestPrime[j] = i;
        }
    }
}

int pow(int base, int power) {
    int ans = 1;
    for (int i = 0; i < power; i++) ans *= base;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    prep();

    int n; cin >> n;
    map<int, int> primes;
    vector<map<int, int>> factorizations(n);

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        while (a > 1) {
            int noOcc = 0;
            int curP = largestPrime[a];
            while (a % curP == 0) {
                noOcc++;
                a /= curP;
            }
            factorizations[i][curP] = noOcc;
            primes[curP]++;
        }
    }

    ll ans = 1;
    for (auto [p, val] : primes) {
        if (val < n - 1) continue;
        int smallest[2] = {INT_MAX, INT_MAX};
        for (int i = 0; i < n; i++) {
            int occ;
            if (factorizations[i].count(p) > 0) occ = factorizations[i][p];
            else occ = 0;
            if (smallest[1] > occ) {
                smallest[1] = occ;
                if (smallest[0] > smallest[1]) {
                    swap(smallest[0], smallest[1]);
                }
            }
        }

        ans *= pow(p, smallest[1]);
    }
    cout << ans << endl;

    return 0;
}


ll a, b;
// a stores minimum exponents (gcd of all numbers seen so far)
// b stores second minimum exponents
int n;

void red() {  // restore invariant mentioned above
	ll g = __gcd(a, b);
	tie(a, b) = make_pair(g, a / g * b);  // a/g*b = lcm(a,b)
}

int main() {
	cin >> n >> a >> b;
	red();
	for (int i = 2; i < n; i++) {
		ll x;
		cin >> x;
		b = __gcd(b, x);
		red();
	}
	cout << b << endl;
}