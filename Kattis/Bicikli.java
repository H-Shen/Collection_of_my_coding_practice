// https://open.kattis.com/problems/bicikli

import java.io.*;
import java.math.BigInteger;
import java.util.BitSet;
import java.util.LinkedList;
import java.util.Queue;

public class Bicikli {

    private static int                   MAXN                  = 10005;
    private static LinkedList<Integer>[] adj                   = new LinkedList[MAXN];
    private static LinkedList<Integer>[] adjRev                = new LinkedList[MAXN];
    private static int[]                 inDegree              = new int[MAXN];
    private static BitSet                visFrom1              = new BitSet(MAXN);
    private static BitSet                visFrom2              = new BitSet(MAXN);
    private static BigInteger[]          dp                    = new BigInteger[MAXN];
    private static int                   elementsVisitedByBoth = 0;

    public static void bfsFrom1() {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        visFrom1.set(1, true);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (Integer v : adj[u]) {
                if (!visFrom1.get(v)) {
                    visFrom1.set(v, true);
                    q.add(v);
                }
            }
        }
    }

    public static void bfsFrom2() {
        Queue<Integer> q = new LinkedList<>();
        q.add(2);
        visFrom2.set(2, true);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (Integer v : adjRev[u]) {
                if (!visFrom2.get(v)) {
                    visFrom2.set(v, true);
                    q.add(v);
                }
            }
        }
    }

    public static void topoSort() {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        dp[1] = BigInteger.ONE;
        while (!q.isEmpty()) {
            int u = q.poll();
            ++elementsVisitedByBoth;
            for (Integer v : adj[u]) {
                if (visFrom1.get(v) && visFrom2.get(v)) {
                    dp[v] = dp[v].add(dp[u]);
                    --inDegree[v];
                    if (inDegree[v] == 0) {
                        q.add(v);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    out = new PrintWriter(new OutputStreamWriter(System.out));
        String[]       s   = br.readLine().split(" ");
        int            n   = Integer.parseInt(s[0]);
        int            m   = Integer.parseInt(s[1]);
        for (int i = 1; i <= n; ++i) {
            adj[i] = new LinkedList<>();
            adjRev[i] = new LinkedList<>();
        }

        for (int i = 0; i < m; ++i) {
            s = br.readLine().split(" ");
            int u = Integer.parseInt(s[0]);
            int v = Integer.parseInt(s[1]);
            adj[u].addFirst(v);
            adjRev[v].addFirst(u);
        }
        bfsFrom1();
        bfsFrom2();
        int counter = 0;
        for (int i = 1; i <= n; ++i) {
            if (visFrom1.get(i) && visFrom2.get(i)) {
                ++counter;
                for (Integer j : adj[i]) {
                    ++inDegree[j];
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            dp[i] = BigInteger.ZERO;
        }
        topoSort();
        if (elementsVisitedByBoth != counter) {
            out.println("inf");
        } else {
            StringBuilder sb = new StringBuilder(dp[2].toString());
            if (sb.length() > 9) {
                for (int i = sb.length() - 9; i < sb.length(); ++i) {
                    out.print(sb.charAt(i));
                }
                out.println();
            } else {
                out.println(dp[2]);
            }
        }
        out.flush();
    }
}
