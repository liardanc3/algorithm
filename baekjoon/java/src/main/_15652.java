package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _15652 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static int[] arr = new int[9];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        dfs(1, 0);
        System.out.println(sb);
    }

    private static void dfs(int now, int len){
        if(len == M){
            for(int i=1; i<=N; i++){
                for(int j=0; j<arr[i]; j++){
                    sb.append(i).append(" ");
                }
            }
            sb.append("\n");
            return;
        }

        for(int i=now; i<=N; i++){
            arr[i]++;
            dfs(i, len+1);
            arr[i]--;
        }
    }
}
