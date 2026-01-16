package introductoryproblems.WeirdAlgorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class WeirdAlgorithm {
    public static void main(String[] args) throws IOException {
        InputStreamReader r = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(r);
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());

        System.out.print(n + " ");

        while (n != 1) {
            if (n % 2 == 1) n = 3 * n + 1;
            else n /= 2;
            System.out.print(n + " ");
        }
    }
}