package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static class Pll {
        long a;
        long b;

        public Pll(long a, long b) {
            this.a = a;
            this.b = b;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static String devcMac, input;
    public static long a, b;
    public static int[] parent = new int[500];
    public static Map<String, List<Pll>> m = new HashMap<>();
    public static List<Integer> root = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        int cnt = 0;
        while(!(input = br.readLine()).equals("S")){

            sb.append(input).append(" ");
        }

        System.out.println("SADD MAC " + sb);
    }
}
