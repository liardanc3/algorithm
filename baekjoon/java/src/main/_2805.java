import java.io.*;
import java.util.*;

public class _2805 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static long N,M, right, answer;
    public static long[] arr = new long[1000000];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(input[i]);
            right = Math.max(arr[i], right);
        }

        int left = 1;
        while (left <= right) {
            int mid = (int) ((left+right)/2);

            long tmp = 0;
            for(int i=0; i<N; i++){
                if(arr[i] > mid){
                    tmp += (int) (arr[i] - mid);
                }
            }

            if(tmp >= M){
                answer = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        System.out.println(answer);

    }
}