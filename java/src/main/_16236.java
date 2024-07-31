package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class _16236 {

    public static class Pair {
        int a;
        int b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static class Tuple {
        int depth;
        Pair p;

        public Tuple(int depth, Pair p) {
            this.depth = depth;
            this.p = p;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, y, x, answer, size = 2, cnt;
    public static int[][] arr = new int[21][21];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0, -1, 1, 0};
    public static int[][] visited = new int[21][21];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for (int i = 1; i <= N; i++) {
            String[] input = br.readLine().split(" ");

            for (int j = 1; j <= N; j++) {
                arr[i][j] = Integer.parseInt(input[j - 1]);
                if (arr[i][j] == 9) {
                    arr[i][j] = 0;
                    y = i;
                    x = j;
                }
            }
        }

        while (y != -1 && x != -1) {
            bfs();
        }

        System.out.println(answer);

    }

    private static void bfs() {
        for (int i = 1; i <= N; i++) {
            Arrays.fill(visited[i], 0);
        }

        visited[y][x] = 1;
        PriorityQueue<Tuple> q = new PriorityQueue<>(
                (t1, t2) -> {
                    if (t1.depth != t2.depth)
                        return t1.depth > t2.depth ? 1 : -1;
                    else {
                        if(t1.p.a != t2.p.a){
                            return t1.p.a > t2.p.a ? 1 : -1;
                        }
                        if(t1.p.b != t2.p.b){
                            return t1.p.b > t2.p.b ? 1 : -1;
                        }
                    }
                    return 0;
                }
        );
        q.add(new Tuple(0, new Pair(y, x)));

        int step = 0;
        while (!q.isEmpty()) {
            int sz = q.size();

            while (sz-- > 0) {
                Tuple t = q.poll();

                int nowY = t.p.a;
                int nowX = t.p.b;

                if (arr[nowY][nowX] > 0 && arr[nowY][nowX] < size) {
                    cnt++;
                    arr[nowY][nowX] = 0;
                    if (cnt == size) {
                        cnt = 0;
                        size++;
                    }
                    y = nowY;
                    x = nowX;
                    answer += step;
                    return;
                }

                for (int i = 0; i < 4; i++) {
                    int ddy = nowY + dy[i];
                    int ddx = nowX + dx[i];

                    if (1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && visited[ddy][ddx] == 0 && arr[ddy][ddx] <= size) {
                        visited[ddy][ddx] = 1;
                        q.add(new Tuple(t.depth + step, new Pair(ddy, ddx)));
                    }
                }
            }

            step++;

        }

        y = -1;
        x = -1;
    }
}

