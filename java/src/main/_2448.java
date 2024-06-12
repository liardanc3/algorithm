package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _2448 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N;
    public static int[][] arr = new int[1024*3+1][1024*3*2+1];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        fun(1, N*2-1, N, 1);

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N*2; j++){
                if(arr[i][j] == 1){
                    sb.append("*");
                } else {
                    sb.append(" ");
                }
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }

    public static void fun(int xl, int xr, int yb, int yt){
        System.out.println(xl + " " + xr + " " + yb + " " + yt);
        if(xr-xl < 4 || yb-yt < 2){
            return;
        }

        int count = 0;
        for(int i=xl; i<=xr; i++){
            if(count == 5){
                count = 0;
                continue;
            }
            arr[yb][i] = 1;
            count++;
        }

        int aX = (xr+xl)/2;
        for(int i=yt; i<=yb; i++){
            arr[i][aX++] = 1;
        }
        int bX = xl;
        for(int i=yb; i>=yt; i--){
            arr[i][bX++] = 1;
        }

        fun(xl, (xl+xr)/2, yb, (yb+yt)/2);
        fun((xl+xr)/2 + 1, xr, yb, (yb+yt)/2);
        fun((xl+xr)/4 , (3*(xr+xl))/4 , yb/2, yt);
    }
}

