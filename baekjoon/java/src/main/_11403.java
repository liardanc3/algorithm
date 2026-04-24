import java.io.*;
import java.util.*;

public class _11403 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N;
    public static int[][] arr = new int[101][101];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        for(int i=1; i<=N; i++){
            String[] input = br.readLine().split(" ");

            for(int j=1; j<=N; j++){
                arr[i][j] = Integer.parseInt(input[j-1]);
            }
        }

        for(int k=1; k<=N; k++){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(arr[i][k] == 1 && arr[k][j] == 1){
                        arr[i][j] = 1;
                    }
                }
            }
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                sb.append(arr[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }
}