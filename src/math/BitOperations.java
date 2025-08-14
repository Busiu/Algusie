package math;

public class BitOperations {
    int setIthBit(int bitmask, int idx) {
        return bitmask | (1 << idx);
    }

    int clearIthBit(int bitmask, int idx) {
        return bitmask & ~(1 << idx);
    }

    int flipIthBit(int bitmask, int idx) {
        return bitmask ^ (1 << idx);
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

    boolean isIthBitSet(int bitmask, int idx) {
        return ((bitmask >> idx) & 1) == 1;
    }

    boolean isPowerOfTwo(int n) {
        if (n < 0) return false;
        if (n == 1) return true;
        return !((n & (n - 1)) > 0);
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
}
