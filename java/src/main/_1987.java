package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1987 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int R, C;
    public static int[] visited = new int[91];
    public static int[][] arr = new int[21][21];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        R = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);

        for(int i=1; i<=R; i++){
            input = br.readLine().split(" ");

            for(int j=1; j<=C; j++){
                arr[i][j] = input[j-1].charAt(0);
            }
        }


    }
}

