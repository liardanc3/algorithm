package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _2577 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int a,b,c;
    public static int[] count = new int[10];

    public static void main(String[] args) throws IOException {
        a = Integer.parseInt(br.readLine());
        b = Integer.parseInt(br.readLine());
        c = Integer.parseInt(br.readLine());

        int result = a*b*c;

        String str = String.valueOf(result);
        for(int i=0; i<str.length(); i++){
            int n = Integer.parseInt(String.valueOf(str.charAt(i)));

            count[n]++;
        }

        for(int i=0; i<=9; i++){
            System.out.println(count[i]);
        }
    }
}

