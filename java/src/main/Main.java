package main;

import java.io.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static String inputA, inputB, inputC;
    public static int a, b, c, d;

    public static void main(String[] args) throws IOException {
        inputA = br.readLine();
        inputB = br.readLine();
        inputC = br.readLine();

        if (!inputA.contains("zz")) {
            d = Integer.parseInt(inputA) + 3;
        } else if (!inputB.contains("zz")) {
            d = Integer.parseInt(inputB) + 2;
        } else if (!inputC.contains("zz")) {
            d = Integer.parseInt(inputC) + 1;
        } else {
            assert (true);
        }

        if (d % 3 == 0 && d % 5 == 0) {
            System.out.println("FizzBuzz");
        } else if (d % 3 == 0 && d % 5 != 0) {
            System.out.println("Fizz");
        } else if (d % 3 != 0 && d % 5 == 0) {
            System.out.println("Buzz");
        } else {
            System.out.println(d);
        }
    }
}
