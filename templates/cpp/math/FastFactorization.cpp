#include <bits/stdc++.h>

using namespace std;

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

int main() {
    prep();
    int a = 30;
    while (a > 1) {
        int noOcc = 0;
        int curP = largestPrime[a];
        while (a % curP == 0) {
            noOcc++;
            a /= curP;
        }
        cout << curP << " occurs " << noOcc << " times." << endl;
    }
}