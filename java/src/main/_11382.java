package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.stream.IntStream;

public class _11382 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static BigInteger[] input = new BigInteger[]{new BigInteger("0"), new BigInteger("0"), new BigInteger("0")};


    public static void main(String[] args) throws IOException {
        String[] s = br.readLine().split(" ");

        input[0] = new BigInteger(s[0]);
        input[1] = new BigInteger(s[1]);
        input[2] = new BigInteger(s[2]);

        System.out.print(
                input[0].add(input[1].add(input[2]))
        );
    }
}
