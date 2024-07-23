import java.io.*;
import java.util.*;

public class _30009 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, x, y, r, A, B;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");

        x = Integer.parseInt(input[0]);
        y = Integer.parseInt(input[1]);
        r = Integer.parseInt(input[2]);

        while(N-- > 0){
            int x1 = Integer.parseInt(br.readLine());

            if(x-r < x1 && x1 < x+r){
                A++;
            }
            if(x-r == x1 || x+r == x1){
                B++;
            }
        }

        System.out.println(A + " " + B);
    }
}