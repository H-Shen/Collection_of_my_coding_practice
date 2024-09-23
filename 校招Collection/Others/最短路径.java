// https://www.nowcoder.com/practice/a29d0b5eb46b4b90bfa22aa98cf5ff17
//

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static final int MAXN = 102;
    public static final int MAX_ROADS = 505;
    public static final BigInteger INF = new BigInteger("4149515568880992958512407863691161151012446232242436899995657329690652811412908146399707048947103794288197886611300789182395151075411775307886874834113963687061181803401509523685376");
    public static final BigInteger TWO = new BigInteger("2");
    public static final BigInteger      MOD          = new BigInteger("100000");
    public static BigInteger [][]       dist         = new BigInteger[MAXN][MAXN];
    public static ArrayList<BigInteger> POWER_OF_TWO = new ArrayList<>();

    public static void main(String[] args) {
        // pre
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                if (i == j) {
                    dist[i][j] = BigInteger.ZERO;
                } else {
                    dist[i][j] = INF;
                }
            }
        }
        POWER_OF_TWO.add(BigInteger.ONE);
        while (POWER_OF_TWO.size() < MAX_ROADS) {
            POWER_OF_TWO.add(POWER_OF_TWO.get(POWER_OF_TWO.size() - 1).multiply(TWO));
        }
        // input
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int K = 0;
        for (int i = 0; i < m; ++i) {
            int u = in.nextInt();
            int v = in.nextInt();
            if (u != v && dist[u][v].compareTo(INF) == 0) {
                dist[u][v] = POWER_OF_TWO.get(K);
                dist[v][u] = POWER_OF_TWO.get(K);
            }
            ++K;
        }
        // process
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][j].compareTo(dist[i][k].add(dist[k][j])) > 0) {
                        dist[i][j] = dist[i][k].add(dist[k][j]);
                    }
                }
            }
        }
        // output
        for (int i = 1; i < n; ++i) {
            if (dist[0][i].compareTo(INF) == 0) {
                System.out.println(-1);
            } else {
                System.out.println(dist[0][i].mod(MOD));
            }
        }
    }
}
