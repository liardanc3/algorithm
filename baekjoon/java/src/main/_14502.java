package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class _14502 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, answer, total;
    public static int[][] arr = new int[8][8];
    public static int[][] visited = new int[8][8];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0, -1, 1, 0};

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");

            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(input[j]);
                if(arr[i][j] != 1){
                    total++;
                }
            }
        }

        for (int i = 0; i < N * M - 2; i++) {
            if (arr[i / M][i % M] != 0) {
                continue;
            }
            for (int j = i + 1; j < N * M - 1; j++) {
                if (arr[j / M][j % M] != 0) {
                    continue;
                }
                for (int k = j + 1; k < N * M; k++) {
                    if (arr[k / M][k % M] != 0) {
                        continue;
                    }
                    func(i, j, k);
                }
            }
        }

        System.out.println(answer);
    }

    private static void func(int p1, int p2, int p3) {
        int count = 0;

        int y1 = p1 / M;
        int x1 = p1 % M;
        int y2 = p2 / M;
        int x2 = p2 % M;
        int y3 = p3 / M;
        int x3 = p3 % M;

        arr[y1][x1] = 1;
        arr[y2][x2] = 1;
        arr[y3][x3] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 2 && visited[i][j] == 0) {
                    spread(i, j);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 1) {
                    count++;
                }
                visited[i][j] = 0;
            }
        }
        arr[y1][x1] = 0;
        arr[y2][x2] = 0;
        arr[y3][x3] = 0;

        answer = Math.max(answer, total - 3 - count);
    }

    private static void spread(int y, int x) {
        visited[y][x] = 1;

        for (int i = 0; i < 4; i++) {
            int ddy = y + dy[i];
            int ddx = x + dx[i];

            if (0 <= ddy && ddy < N && 0 <= ddx && ddx < M && visited[ddy][ddx] == 0 && arr[ddy][ddx] != 1) {
                spread(ddy, ddx);
            }
        }
    }
}

