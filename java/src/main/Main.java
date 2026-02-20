package main;

import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static String input;
    public static String[] inputArr;
    public static int n, m, k, conn;
    public static int[] owner = new int[100001];
    public static int[] tree = new int[100001];
    public static long[] companyPoint = new long[100001];
    public static Map<Integer, Map<Integer, Integer>> rootAndCompanyCntMap = new HashMap<>();
    public static PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> -a[0]));

    public static int getRoot(int i) {
        return (tree[i] == i) ? i : (tree[i] = getRoot(tree[i]));
    }

    public static void mst() {
        for (int i = 1; i <= n; i++) {
            tree[i] = i;
            int finalI = i;
            rootAndCompanyCntMap.put(i, new HashMap<>() {{
                put(owner[finalI], 1);
            }});
        }

        while (!pq.isEmpty() && conn < n - 1) {
            int[] edge = pq.poll();

            int w = edge[0];
            int a = edge[1];
            int b = edge[2];

            int ra = getRoot(a);
            int rb = getRoot(b);

            if (ra != rb) {
                conn++;

                Map<Integer, Integer> aCompanyAndCntMap = rootAndCompanyCntMap.getOrDefault(ra, new HashMap<>());
                Map<Integer, Integer> bCompanyAndCntMap = rootAndCompanyCntMap.getOrDefault(rb, new HashMap<>());

                if (aCompanyAndCntMap.size() < bCompanyAndCntMap.size()) {
                    int tmp = ra;
                    ra = rb;
                    rb = tmp;
                }
                tree[rb] = ra;

                Map<Integer, Integer> bigMap = rootAndCompanyCntMap.getOrDefault(ra, new HashMap<>());
                Map<Integer, Integer> smallMap = rootAndCompanyCntMap.getOrDefault(rb, new HashMap<>());

                for (int company : smallMap.keySet()) {
                    int smallCount = smallMap.get(company);

                    if (bigMap.containsKey(company)) {
                        int bigCount = bigMap.get(company);
                        companyPoint[company] += (long) w * smallCount * bigCount;
                        bigMap.put(company, smallCount + bigCount);
                    } else {
                        bigMap.put(company, smallCount);
                    }
                }

                rootAndCompanyCntMap.put(ra, bigMap);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input = br.readLine();
        inputArr = input.split(" ");

        n = Integer.parseInt(inputArr[0]);
        k = Integer.parseInt(inputArr[1]);
        m = Integer.parseInt(inputArr[2]);

        input = br.readLine();
        inputArr = input.split(" ");
        for (int i = 1; i <= n; i++) {
            owner[i] = Integer.parseInt(inputArr[i - 1]);
        }

        for (int i = 0; i < m; i++) {
            input = br.readLine();
            inputArr = input.split(" ");

            int a = Integer.parseInt(inputArr[0]);
            int b = Integer.parseInt(inputArr[1]);
            int w = Integer.parseInt(inputArr[2]);

            pq.add(new int[]{w, a, b});
        }

        mst();

        for (int i = 1; i <= k; i++) {
            bw.write(companyPoint[i] + "\n");
        }
        bw.flush();
    }
}