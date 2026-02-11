package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _29863 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int a, b, cnt;

    public static void main(String[] args) throws IOException {
        a = Integer.parseInt(br.readLine());
        b = Integer.parseInt(br.readLine());

        if(a>19){
            cnt = 24-a + b;
        } else {
            cnt = b-a;
        }

        System.out.println(cnt);

    }
}

