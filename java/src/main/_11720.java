package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _11720 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();

    public static int N;
    public static int answer;
    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        String input = br.readLine();
        for(int i=0; i<input.length(); i++){
            answer += Integer.parseInt(String.valueOf(input.charAt(i)));
        }

        System.out.println(answer);
    }
}

