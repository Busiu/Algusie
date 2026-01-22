#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    indexed_set<int> s;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s.insert(i);
    }

    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        auto it = s.find_by_order(a);
        int idx = *it;
        cout << v[idx] << " ";
        s.erase(it);
    }

    return 0;
}