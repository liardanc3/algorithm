package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class _17144 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int R, C, T, ans;
    public static int ay, ax, by, bx;
    public static String[] input;
    public static int[][] arr = new int[51][51];
    public static int[][] tmp = new int[51][51];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0, -1, 1, 0};

    public static void main(String[] args) throws IOException {
        input = br.readLine().split(" ");

        R = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);
        T = Integer.parseInt(input[2]);

        for (int i = 1; i <= R; i++) {
            input = br.readLine().split(" ");

            for (int j = 1; j <= C; j++) {
                arr[i][j] = Integer.parseInt(input[j - 1]);
                if (arr[i][j] == -1) {
                    if (ay == 0) {
                        ay = i;
                        ax = j;
                    } else {
                        by = i;
                        bx = j;
                    }
                }
            }
        }

        while (T-- > 0) {
            spread();
            cleanA();
            cleanB();
        }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                ans += arr[i][j];
            }
        }

        System.out.println(ans + 2);
    }

    private static void spread() {
        for (int i = 1; i <= R; i++) {
            Arrays.fill(tmp[i], 0);
        }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if(arr[i][j] == -1){
                    continue;
                }

                int dust = arr[i][j] / 5;

                for (int k = 0; k < 4; k++) {
                    int y = i + dy[k];
                    int x = j + dx[k];

                    if (1 <= y && y <= R && 1 <= x && x <= C && arr[y][x] != -1) {
                        tmp[y][x] += dust;
                        tmp[i][j] -= dust;
                    }
                }

            }
        }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                arr[i][j] += tmp[i][j];
            }
        }
    }

    private static void cleanA() {

        // top
        for (int i = ay - 1; i >= 2; i--) {
            arr[i][ax] = arr[i - 1][ax];
        }

        // right
        for (int j = ax; j <= C - 1; j++) {
            arr[1][j] = arr[1][j + 1];
        }

        // bottom
        for (int i = 1; i <= ay - 1; i++) {
            arr[i][C] = arr[i + 1][C];
        }

        // left
        for (int j = C; j >= 3; j--) {
            arr[ay][j] = arr[ay][j - 1];
        }
        arr[ay][ax + 1] = 0;

    }

    private static void cleanB() {

        // bottom
        for (int i = by + 1; i <= R - 1; i++) {
            arr[i][1] = arr[i + 1][1];
        }

        // right
        for (int j = bx; j <= C - 1; j++) {
            arr[R][j] = arr[R][j + 1];
        }

        // top
        for (int i = R; i >= by + 1; i--) {
            arr[i][C] = arr[i - 1][C];
        }

        // left
        for (int j = C; j >= 3; j--) {
            arr[by][j] = arr[by][j - 1];
        }
        arr[by][bx + 1] = 0;
    }

}

