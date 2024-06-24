import java.io.*;
import java.util.*;

public class _11054 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, answer;
    public static int[] arr = new int[1001];
    public static int[] dp1 = new int[1001];
    public static int[] dp2 = new int[1001];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        for(int i=1; i<=N; i++){
            arr[i] = Integer.parseInt(input[i-1]);
        }

        for(int i=1; i<=N; i++){
            dp1[i] = 1;
            dp2[N+1 - i] = 1;
            for(int j=1; j<i; j++){
                if(arr[j] < arr[i]){
                    dp1[i] = Math.max(dp1[i], dp1[j] + 1);
                }
                if(arr[N+1 - j] < arr[N+1 - i]){
                    dp2[N+1 - i] = Math.max(dp2[N+1 - i], dp2[N+1 - j] + 1);
                }
            }
        }

        for(int i=1; i<=N; i++){
            answer = Math.max(answer, dp1[i] + dp2[i] - 1);
        }

        System.out.println(answer);
    }
}