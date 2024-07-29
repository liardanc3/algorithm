package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class _2638 {

    public static class Pair {
        int y;
        int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, answer;
    public static String[] input;
    public static int[][] arr = new int[102][102];
    public static int[][] tmp = new int[102][102];
    public static int[][] visited = new int[102][102];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0, -1, 1, 0};

    public static void main(String[] args) throws IOException {
        input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for (int i = 1; i <= N; i++) {
            input = br.readLine().split(" ");

            for (int j = 1; j <= M; j++) {
                arr[i][j] = Integer.parseInt(input[j - 1]);
            }
        }

        fun();
        System.out.println(answer);
    }

    private static void fun() {
        boolean isExists = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (arr[i][j] == 1) {
                    isExists = true;
                    break;
                }
            }
        }

        if (isExists) {
            answer++;
            for (int i = 1; i <= N; i++) {
                Arrays.fill(tmp[i], 0);
            }

            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (arr[i][j] == 1) {

                        int cnt = 0;
                        if(arr[i-1][j] != 1){
                            for (int a = 1; a <= N; a++) {
                                Arrays.fill(visited[a], 0);
                            }
                            cnt += check(i-1, j);
                        }
                        if(arr[i][j-1] != 1){
                            for (int a = 1; a <= N; a++) {
                                Arrays.fill(visited[a], 0);
                            }
                            cnt += check(i, j-1);
                        }
                        if(arr[i+1][j] != 1){
                            for (int a = 1; a <= N; a++) {
                                Arrays.fill(visited[a], 0);
                            }
                            cnt += check(i+1, j);
                        }
                        if(arr[i][j+1] != 1){
                            for (int a = 1; a <= N; a++) {
                                Arrays.fill(visited[a], 0);
                            }
                            cnt += check(i, j+1);
                        }

                        if (cnt >= 2) {
                            tmp[i][j] = 1;
                        }
                    }
                }
            }

            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (tmp[i][j] == 1) {
                        arr[i][j] = 0;
                    }
                }
            }
            fun();
        }
    }

    private static int check(int y, int x) {
        visited[y][x] = 1;

        int result = 0;
        if (x < 1 || x > M || y < 1 || y > N) {
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int ddy = y + dy[i];
            int ddx = x + dx[i];

            if (visited[ddy][ddx] == 0 && arr[ddy][ddx] == 0) {
                result = check(ddy, ddx);
                if(result == 1){
                    return result;
                }
            }
        }

        return 0;
    }
}
