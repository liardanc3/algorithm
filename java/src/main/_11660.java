package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _11660 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static int[][] arr = new int[1025][1025];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i=1; i<=N; i++) {
            input = br.readLine().split(" ");

            for(int j=1; j<=N; j++){
                arr[i][j] = Integer.parseInt(input[j-1]);
                arr[i][j] = arr[i][j] + (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
            }
        }

        for(int i=1; i<=M; i++){
            input = br.readLine().split(" ");

            int y1 = Integer.parseInt(input[0]);
            int x1 = Integer.parseInt(input[1]);
            int y2 = Integer.parseInt(input[2]);
            int x2 = Integer.parseInt(input[3]);

            sb.append(arr[y2][x2] - arr[y1-1][x2] - arr[y2][x1-1] + arr[y1-1][x1-1]).append("\n");
        }

        System.out.println(sb);
    }
}

