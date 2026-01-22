#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct FenwickTree {
    int len; 
    vector<int> fenTree;

    FenwickTree(int len) : len(len + 1) {
        fenTree = vector<int>(len + 1);
    }

    void change(int idx, int val) {
        idx++;
        while (idx < len) {
            fenTree[idx] += val;
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += fenTree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> sal(n);
    for (int i = 0; i < n; i++) {
        cin >> sal[i];
    }

    vector<array<int, 3>> queries(q);
    vector<int> uniques = sal;
    for (int i = 0; i < q; i++) {
        char type; cin >> type;
        if (type == '!') {
            int k, x; cin >> k >> x; k--;
            queries[i] = {0, k, x};
            uniques.push_back(x);
        } else {
            int a, b; cin >> a >> b;
            queries[i] = {1, a, b};
        }
    }

    sort(uniques.begin(), uniques.end());
    uniques.erase(unique(uniques.begin(), uniques.end()), uniques.end());

    for (int i = 0; i < n; i++) {
        sal[i] = lower_bound(uniques.begin(), uniques.end(), sal[i]) - uniques.begin();
    }

    FenwickTree ft(uniques.size());
    for (int val : sal) ft.change(val, 1);

    for (auto& q : queries) {
        if (q[0] == 0) {
            q[2] = lower_bound(uniques.begin(), uniques.end(), q[2]) - uniques.begin();
            int k = q[1], x = q[2];
            int curSal = sal[k];
            ft.change(curSal, -1);
            ft.change(x, 1);
            sal[k] = x;        
        } else {
            q[1] = lower_bound(uniques.begin(), uniques.end(), q[1]) - uniques.begin();
            q[2] = upper_bound(uniques.begin(), uniques.end(), q[2]) - uniques.begin() - 1;
            int a = q[1], b = q[2];
            cout << ft.query(b) - ft.query(a - 1) << endl;
        }
    }

    return 0;
}