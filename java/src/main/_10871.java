package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _10871 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();


    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        for (int i = 1; i <= a; i++) {
            int n = Integer.parseInt(input[i - 1]);

            if(n<b){
                sb.append(n).append(" ");
            }
        }

        System.out.println(sb);
    }
}
