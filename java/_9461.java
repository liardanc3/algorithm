import java.io.*;
import java.util.*;

public class _9461 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static long[] arr = new long[101];
    public static long T, N;

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        arr[1] = 1; arr[2] = 1; arr[3] = 1;
        arr[4] = 2; arr[5] = 2;
        arr[6] = 3;
        for(int i=7; i<=100; i++){
            arr[i] = arr[i-1] + arr[i-5];
        }

        T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            sb.append(arr[Integer.parseInt(br.readLine())]).append("\n");
        }

        System.out.println(sb);

    }
}