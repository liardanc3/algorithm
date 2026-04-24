package main;

import java.io.*;
import java.util.*;

public class _1017 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int n, matching, fixed;
    public static boolean isOdd;
    public static boolean[] prime = new boolean[2001];
    public static List<Integer> input = new ArrayList<>();
    public static List<Integer>[] graph = new ArrayList[2001];
    public static List<Integer> fixedRights = new ArrayList<>();
    public static boolean[] used = new boolean[2001];
    public static int[] left = new int[1001];
    public static int[] right = new int[2001];
    public static List<Integer> answer = new ArrayList<>();
    public static int[] dist = new int[2001];
    public static final int INF = Integer.MAX_VALUE;
    public static Set<Integer> leftList = new HashSet<>();

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int l : leftList) {
            if (input.get(0) == l) {
                continue;
            }
            if (left[l] == 0) {
                dist[l] = 0;
                q.add(l);
            } else {
                dist[l] = INF;
            }
        }

        dist[0] = INF;

        while (!q.isEmpty()) {
            int left = q.poll();

            if (dist[left] < dist[0]) {
                for (int r : graph[left]) {
                    if (r == fixed) {
                        continue;
                    }
                    int matchedLeft = right[r];
                    if (matchedLeft == input.get(0)) {
                        continue;
                    }

                    if (dist[matchedLeft] == INF) {
                        dist[matchedLeft] = dist[left] + 1;
                        q.add(matchedLeft);
                    }
                }
            }
        }

        return dist[0] != INF;
    }

    public static boolean connectedAugmentPathEnd(int l) {
        if (l == 0) {
            return true;
        }

        for (int r : graph[l]) {
            if (r == fixed) {
                continue;
            }
            int matchedLeft = right[r];

            if (dist[l] + 1 == dist[matchedLeft] && connectedAugmentPathEnd(matchedLeft)) {
                left[l] = r;
                right[r] = l;
                return true;
            }
        }

        dist[l] = INF;
        return false;
    }

    public static void bipartite() {
        while (hasAugmentPathEnd()) {
            for (int l : leftList) {
                if (l == input.get(0)) {
                    continue;
                }
                if (left[l] == 0 && connectedAugmentPathEnd(l)) {
                    matching++;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        prime[1] = false;
        prime[2] = true;
        for (int i = 3; i <= 2000; i++) {
            prime[i] = true;
        }
        for (int i = 2; i * i <= 2000; i++) {
            if (prime[i]) {
                for (int j = i * 2; j <= 2000; j += i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 0; i <= 2000; i++) {
            graph[i] = new ArrayList<>();
        }

        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            input.add(Integer.parseInt(st.nextToken()));
        }
        isOdd = input.get(0) % 2 == 1;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = input.get(i);
                int b = input.get(j);

                if (prime[a + b]) {
                    if (isOdd) {
                        if (a % 2 == 1) {
                            graph[a].add(b);
                            leftList.add(a);
                        } else {
                            graph[b].add(a);
                            leftList.add(b);
                        }
                    } else {
                        if (a % 2 == 0) {
                            graph[a].add(b);
                            leftList.add(a);
                        } else {
                            graph[b].add(a);
                            leftList.add(b);
                        }
                    }
                }
            }
        }

        for (int i = 1; i < n; i++) {
            int left = input.get(0);
            int right = input.get(i);

            if (prime[left + right]) {
                fixedRights.add(right);
            }
        }

        for (int r : fixedRights) {
            Arrays.fill(left, 0);
            Arrays.fill(right, 0);
            Arrays.fill(dist, 0);
            matching = 1;
            fixed = r;

            bipartite();

            if (matching == n / 2) {
                answer.add(r);
            }
        }

        answer.sort(Comparator.naturalOrder());
        for (Integer ans : answer) {
            bw.write(ans + " ");
        }
        if (answer.isEmpty()) {
            bw.write("-1");
        }
        bw.flush();
    }
}