package main;

import java.io.*;
import java.util.*;

public class _27866 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        String input = br.readLine();
        int idx = Integer.parseInt(br.readLine()) - 1;

        System.out.println(input.charAt(idx));
    }
}