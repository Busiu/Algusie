package java.search;

import java.util.ArrayList;
import java.util.List;

public class KMPSearch {
    static int[] getLPS(String pattern) {
        var n = pattern.length();
        var lps = new int[n];

        var i = 1;
        var prefIndex = 0;
        while (i < n) {
            if (pattern.charAt(i) == pattern.charAt(prefIndex)) {
                prefIndex++;
                lps[i] = prefIndex;
                i++;
            } else {
                if (prefIndex != 0) {
                    prefIndex = lps[prefIndex - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    static List<Integer> kmp(String text, String pattern) {
        var result = new ArrayList<Integer>();

        var lps = getLPS(pattern);
        var patIndex = 0;
        var txtIndex = 0;
        while (txtIndex < text.length()) {
            if (text.charAt(txtIndex) == pattern.charAt(patIndex)) {
                patIndex++;
                txtIndex++;
                if (patIndex == pattern.length()) {
                    result.add(txtIndex - patIndex);
                    patIndex = lps[patIndex - 1];
                }
            } else {
                if (patIndex != 0) {
                    patIndex = lps[patIndex - 1];
                } else {
                    txtIndex++;
                }
            }
        }
        return result;
    }
}
