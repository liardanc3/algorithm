import java.io.*;
import java.util.*;

public class _11659 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static long[] sum = new long[100_001];
    public static int N, M;

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        for(int i=1; i<=N; i++){
            sum[i] = sum[i-1] + Integer.parseInt(input[i-1]);
        }

        for(int i=0; i<M; i++){
            input = br.readLine().split(" ");

            sb.append(sum[Integer.parseInt(input[1])] -
                            sum[Math.max(0,Integer.parseInt(input[0])-1)])
                    .append("\n");
        }

        System.out.println(sb);

    }
}