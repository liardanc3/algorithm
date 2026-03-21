package main;

import java.io.*;
import java.util.*;

public class _14572 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int N, K, D, M, d, a, mx, firstD, first = 1;
    public static int[] in = new int[31];   // 언제 들어갔는지(가장최신)
    public static int[] dup = new int[31];  // 전체 겹치는 알고리즘 번호(현재)
    public static int[] preDup = new int[31]; // 전체 겹치는 알고리즘 번호(1개전)
    public static int[] all = new int[31];  // 전체 알고리즘
    public static List<List<Integer>> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());

            M = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());

            List<Integer> tmp = new ArrayList<>();
            tmp.add(d);
            st = new StringTokenizer(br.readLine());
            while (M-- > 0) {
                a = Integer.parseInt(st.nextToken());
                tmp.add(a);
                assert a <= 30;
            }
            list.add(tmp);
        }
        list.sort(Comparator.comparing((a -> a.get(0))));
        firstD = list.get(0).get(0);

        for (int i = 1; i <= N; i++) {
            List<Integer> algorithms = list.get(i - 1);

            d = algorithms.get(0);
            while (d - firstD > D) {
                for (int j = 1; j <= 30; j++) {
                    if (in[j] <= first) {
                        all[j] = 0;
                        preDup[j] = 0;
                    }
                }
                first++;
                firstD = list.get(first - 1).get(0);
            }
            if (i - first == 1) {
                preDup = all.clone();
            }

            for (int j = 1; j < algorithms.size(); j++) {
                int a = algorithms.get(j);

                in[a] = i;
                all[a] = 1;
                if (preDup[a] == 1) {
                    dup[a] = 1;
                }
            }

            int allCount = 0;
            int dupCount = 0;
            for (int k = 1; k <= 30; k++) {
                allCount += all[k];
                dupCount += dup[k];
            }

            if (i != first) {
                mx = Math.max(mx, (allCount - dupCount) * (i - first + 1));
            }

            for (int k = 1; k <= 30; k++) {
                preDup[k] = dup[k];
                dup[k] = 0;
            }
        }

        System.out.println(mx);
    }
}