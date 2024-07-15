package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _9610 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, q1, q2, q3, q4, axis;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        while (N-- > 0) {
            String[] input = br.readLine().split(" ");

            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);

            if (x > 0) {
                if (y > 0) {
                    q1++;
                } else if (y < 0) {
                    q4++;
                } else {
                    axis++;
                }
            } else if (x < 0) {
                if (y > 0) {
                    q2++;
                } else if (y < 0) {
                    q3++;
                } else {
                    axis++;
                }
            } else {
                axis++;
            }
        }

        System.out.println("Q1: " + q1);
        System.out.println("Q2: " + q2);
        System.out.println("Q3: " + q3);
        System.out.println("Q4: " + q4);
        System.out.println("AXIS: " + axis);
    }
}
