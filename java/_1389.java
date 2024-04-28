import java.io.*;
import java.util.*;

public class _1389 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N,M,a,b, mn=Integer.MAX_VALUE, mnIdx;
    public static int[][] arr = new int[101][101];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i!=j){
                    arr[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        M = Integer.parseInt(input[1]);

        for(int i=0; i<M; i++){
            input = br.readLine().split( " ");

            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);

            arr[a][b] = 1;
            arr[b][a] = 1;
        }

        for(int k=1; k<=N; k++){
            for(int i=1; i<=N; i++){
                if(i==k){
                    continue;
                }
                for(int j=1; j<=N; j++){
                    if(arr[i][k] != Integer.MAX_VALUE && arr[k][j] != Integer.MAX_VALUE){
                        arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
                    }
                }
            }
        }

        int tmp = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                tmp += arr[i][j];
            }
            if(tmp < mn){
                mn = tmp;
                mnIdx = i;
            }
            tmp = 0;
        }

        System.out.println(mnIdx);
    }
}