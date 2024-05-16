import java.io.*;
import java.util.*;

public class _6064 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int T;
    public static long M, N, x, y, k = -1;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        for(int i=0; i<T; i++){
            k = -1;
            String[] input = br.readLine().split(" ");

            M = Integer.parseInt(input[0]);
            N = Integer.parseInt(input[1]);
            x = Integer.parseInt(input[2]);
            y = Integer.parseInt(input[3]);

            long mx = lcm(Math.max(M, N), Math.min(M, N));
            if(M==x && N==y){
                sb.append(mx).append("\n");
            } else {
                x %= M;
                y %= N;

                for(int j=0;; j++){
                    long tmp = j*M+x;
                    if(tmp>mx){
                        break;
                    }
                    if(tmp%N==y){
                        k = tmp;
                        break;
                    }
                }

                sb.append(k).append("\n");
            }
        }

        System.out.println(sb);
    }

    private static long lcm(long a, long b){
        return (a*b) / (gcd(a,b));
    }

    private static long gcd(long a, long b){
        return b==0 ? a : gcd(b, a%b);
    }
}