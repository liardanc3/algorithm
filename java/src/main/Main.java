package main;

import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static String input;
    public static int n, m, nIdx = -1, mIdx = -1, len;
    public static Map<Integer, Queue<Integer>> nNumber2IdxMap = new HashMap<>();
    public static Map<Integer, Queue<Integer>> mNumber2IdxMap = new HashMap<>();
    public static int[] arrN = new int[100];
    public static int[] arrM = new int[100];
    public static int[] answer = new int[100];

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        arrN = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for (int i = 0; i < n; i++) {
            Queue<Integer> idx = nNumber2IdxMap.getOrDefault(arrN[i], new ArrayDeque<>());
            idx.add(i);
            nNumber2IdxMap.put(arrN[i], idx);
        }

        m = Integer.parseInt(br.readLine());
        arrM = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for (int i = 0; i < m; i++) {
            Queue<Integer> idx = mNumber2IdxMap.getOrDefault(arrM[i], new ArrayDeque<>());
            idx.add(i);
            mNumber2IdxMap.put(arrM[i], idx);
        }

        for (int i = 100; i >= 1; i--) {
            if (nNumber2IdxMap.containsKey(i) && mNumber2IdxMap.containsKey(i)) {
                Queue<Integer> nIdxQ = nNumber2IdxMap.get(i);
                Queue<Integer> mIdxQ = mNumber2IdxMap.get(i);

                while (!nIdxQ.isEmpty()) {
                    Integer nIdxNow = nIdxQ.poll();

                    while (nIdxNow > nIdx && !mIdxQ.isEmpty()) {
                        Integer mIdxNow = mIdxQ.poll();

                        if (mIdxNow > mIdx) {
                            answer[len++] = i;
                            mIdx = mIdxNow;
                            nIdx = nIdxNow;
                        }
                    }
                }
            }
        }

        bw.write(len + "\n");
        for (int i = 0; i < len; i++) {
            bw.write(answer[i] + " ");
        }
        bw.flush();
        bw.close();
    }
}
