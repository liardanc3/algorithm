package main;

import java.io.*;
import java.util.*;

public class _3683 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static String love, hate;
    public static int t, c, d, v;
    public static int[] left = new int[501];
    public static int[] right = new int[501];
    public static int[] dist = new int[501];
    public static final int AUGMENT_PATH_END = 0;
    public static final int NOT_VISITED = Integer.MAX_VALUE;
    public static List<int[]> animals = new ArrayList<>();
    public static List<Integer>[] graph = new ArrayList[501];
    public static List<Integer> cat = new ArrayList<>();
    public static List<Integer> dog = new ArrayList<>();

    public static boolean hasAugmentPathEnd() {
        Queue<Integer> q = new ArrayDeque<>();

        for (int l : cat) {
            if (left[l] == 0) {
                dist[l] = 0;
                q.add(l);
            } else {
                dist[l] = NOT_VISITED;
            }
        }

        dist[AUGMENT_PATH_END] = NOT_VISITED;

        while (!q.isEmpty()) {
            int l = q.poll();

            if (dist[l] < dist[AUGMENT_PATH_END]) {
                for (int r : Optional.ofNullable(graph[l]).orElseGet(ArrayList::new)) {
                    int matchedLeft = right[r];

                    if (dist[matchedLeft] == NOT_VISITED) {
                        dist[matchedLeft] = dist[l] + 1;
                        q.add(matchedLeft);
                    }
                }
            }
        }

        return dist[AUGMENT_PATH_END] != NOT_VISITED;
    }

    public static boolean connectAugmentPathEnd(int l) {
        if (l == AUGMENT_PATH_END) {
            return true;
        }

        for (int r : Optional.ofNullable(graph[l]).orElseGet(ArrayList::new)) {
            int matchedLeft = right[r];

            if (dist[matchedLeft] == dist[l] + 1 && connectAugmentPathEnd(matchedLeft)) {
                left[l] = r;
                right[r] = l;
                return true;
            }
        }

        dist[l] = NOT_VISITED;
        return false;
    }

    public static void bipartite() {
        while (hasAugmentPathEnd()) {
            for (int l : cat) {
                if (left[l] == 0) {
                    connectAugmentPathEnd(l);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());

            c = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            cat.clear();
            dog.clear();
            animals.clear();
            animals.add(new int[]{0, 0});
            for (int i = 1; i <= v; i++) {
                st = new StringTokenizer(br.readLine());

                love = st.nextToken();
                hate = st.nextToken();

                int lv = Integer.parseInt(love.substring(1)) + ((love.charAt(0) == 'C') ? 0 : 100);
                int ht = Integer.parseInt(hate.substring(1)) + ((hate.charAt(0) == 'C') ? 0 : 100);

                animals.add(new int[]{lv, ht});
                if (lv <= 100) {
                    cat.add(i);
                } else {
                    dog.add(i);
                }
            }

            for (int i = 1; i <= v; i++) {
                if (graph[i] != null) {
                    graph[i].clear();
                }
            }
            for (int i : cat) {
                for (int j : dog) {
                    boolean disagree = animals.get(i)[0] == animals.get(j)[1] || animals.get(i)[1] == animals.get(j)[0];
                    if (disagree) {
                        if (graph[i] == null) {
                            graph[i] = new ArrayList<>();
                        }
                        graph[i].add(j);
                    }
                }
            }

            Arrays.fill(left, 0);
            Arrays.fill(right, 0);
            Arrays.fill(dist, 0);

            bipartite();

            int answer = v;
            for (int l : cat) {
                if (left[l] != 0) {
                    answer--;
                }
            }

            bw.write(answer + "\n");
        }
        bw.flush();
    }
}