package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Math.*;

public class _2096 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int[][] dpMx = new int[3][2];
    public static int[][] dpMn = new int[3][2];
    public static int N;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for (int i = 1; i <= N; i++) {
            String[] input = br.readLine().split(" ");

            dpMx[0][1] = Integer.parseInt(input[0]);
            dpMn[0][1] = Integer.parseInt(input[0]);
            dpMx[0][1] += max(dpMx[0][0], dpMx[1][0]);
            dpMn[0][1] += min(dpMn[0][0], dpMn[1][0]);

            dpMx[1][1] = Integer.parseInt(input[1]);
            dpMn[1][1] = Integer.parseInt(input[1]);
            dpMx[1][1] += max(dpMx[0][0], max(dpMx[1][0], dpMx[2][0]));
            dpMn[1][1] += min(dpMn[0][0], min(dpMn[1][0], dpMn[2][0]));

            dpMx[2][1] = Integer.parseInt(input[2]);
            dpMn[2][1] = Integer.parseInt(input[2]);
            dpMx[2][1] += max(dpMx[1][0], dpMx[2][0]);
            dpMn[2][1] += min(dpMn[1][0], dpMn[2][0]);

            for(int j=0; j<3; j++){
                dpMx[j][0] = dpMx[j][1];
                dpMn[j][0] = dpMn[j][1];
            }
        }
        
        System.out.print(max(dpMx[0][1], max(dpMx[1][1], dpMx[2][1])));
        System.out.println(" " + min(dpMn[0][1], min(dpMn[1][1], dpMn[2][1])));
    }
}

