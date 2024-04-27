import java.io.*;
import java.util.*;

public class _1074 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, C, R, answer, st;

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        R = Integer.parseInt(input[1]);
        C = Integer.parseInt(input[2]);

        fun(N, 0, 0, 0);
        System.out.println(answer);
    }

    private static void fun(int n, int start, int y, int x){
        int len = (int) Math.pow(2, n);

        if(n == 0){
            answer = start;
            return;
        }

        boolean top = R < len/2 + y;
        boolean left = C < len/2 + x;

        if(top && left){
            fun(n-1, start, y, x);
        } else if(top && !left){
            fun(n-1, start+(len*len/4), y, x + len/2);
        } else if(!top && left){
            fun(n-1, start+2*(len*len/4), y + len/2, x);
        } else {
            fun(n-1, start+3*(len*len/4), y+len/2, x+len/2);
        }
    }
}