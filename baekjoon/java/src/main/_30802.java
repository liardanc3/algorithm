import java.io.*;
import java.util.*;

public class _30802 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, T, P, t, p1, p2;
    public static int[] arr = new int[6];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        for(int i=0; i<6; i++){
            arr[i] = Integer.parseInt(input[i]);
        }

        input = br.readLine().split(" ");
        T = Integer.parseInt(input[0]);
        P = Integer.parseInt(input[1]);

        for(int i=0; i<6; i++){
            t += (arr[i]+T-1) / T;
        }
        p1 = N / P;
        p2 = N % P;

        System.out.println(t + "\n" + p1 + " " + p2);
    }
}