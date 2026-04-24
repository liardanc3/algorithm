package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1629 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static long a,b,c;

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        a = Long.parseLong(input[0]);
        b = Long.parseLong(input[1]);
        c = Long.parseLong(input[2]);

        System.out.println(fun(a,b));
    }

    public static long fun(long a, long b) {
        if(b == 1){
            return a % c;
        }
        if(b == 0){
            return 1;
        }

        long half = fun(a, b/2) % c;

        if(b%2 == 0){
            return (half * half) % c;
        }else {
            return (((half * half) % c) * a) % c;
        }
    }
}
