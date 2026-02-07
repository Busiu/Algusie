int add(int a, int b) {
    while (b > 0) {
        int y = (a & b) << 1;
        a ^= b;
        b = y;
    }
    return a;
}

int prod(int a, int b) {
    int ans = 0;
    while (b > 0) {
        if ((b & 1) == 1) ans = add(ans, a);
        a <<= 1;
        b >>= 1;
    }
    return ans;
}

int clearRightMostBit(int bitmask) {
    if (bitmask == 0) return 0;
    return (bitmask & (bitmask - 1));
}

int clearAllTrailingOnes(int bitmask) {
    return (bitmask & (bitmask + 1));
}

int setLastZeroBit(int bitmask) {
    return (bitmask | (bitmask + 1));
}

int extractLastSetBit(int bitmask) {
    return (bitmask & -bitmask);
}

// Brian Kernighan's algorithm
int countSetBits(int bitmask) {
    int count = 0;
    while (bitmask > 0) {
        bitmask = bitmask & (bitmask - 1);
        count++;
    }
    return count;
}