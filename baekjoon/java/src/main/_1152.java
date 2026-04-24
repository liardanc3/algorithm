package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _1152 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int cnt;

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        for (String s : input) {
            if(!s.equals("")){
                cnt++;
            }
        }
        System.out.println(cnt);

    }
}

