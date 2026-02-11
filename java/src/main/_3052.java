package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class _3052 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static Set<Integer> s = new HashSet<>();

    public static void main(String[] args) throws IOException {
        for(int i=0; i<10; i++){
            int n = Integer.parseInt(br.readLine());

            s.add(n%42);
        }

        System.out.println(s.size());

    }
}
