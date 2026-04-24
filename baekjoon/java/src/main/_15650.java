import java.io.*;
import java.util.*;

public class _15650 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N,M;
    public static int[] arr = new int[9];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i=1; i<=N; i++){
            dfs(i, 1);
        }
        System.out.println(sb);
    }

    private static void dfs(int now, int len){
        arr[len] = now;
        if(len == M){
            for(int i=1; i<=M; i++){
                sb.append(arr[i]).append(" ");
            }
            sb.append("\n");

            return;
        }

        for(int i=now+1; i<=N; i++){
            dfs(i, len+1);
        }
    }
}