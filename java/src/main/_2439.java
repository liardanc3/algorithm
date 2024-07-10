package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _2439 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int[][] arr = new int[101][101];

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        for(int i=1; i<=n; i++){
            for(int j=n; j>n-i; j--){
                arr[i][j] = 1;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                sb.append(arr[i][j] == 1 ? '*' : ' ');
            }
            sb.append("\n");
        }

        System.out.println(sb);

    }
}

