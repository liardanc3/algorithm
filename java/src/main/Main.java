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
        while(!(input = br.readLine()).equals("S")){
            String[] data = input.split(",");

            devcMac = data[0];
            a = Long.parseLong(data[1]);
            b = Long.parseLong(data[2]);

            m.compute(devcMac, (key, list) -> {
                if (list == null) {
                    list = new ArrayList<>();
                }
                list.add(new Pll(a, b));
                return list;
            });
        }

        for (String key : m.keySet()) {
            List<Pll> list = m.get(key);

            for(int i = 0; i< list.size() - 1; i++){

                long cellParent = list.get(i).a;

                if(i == 0){
                    root.add((int)cellParent);
                }

                if(list.size() != 1){
                    long cellChild = list.get(i+1).a;
                    parent[(int) cellChild] = (int) cellParent;
                }
            }
        }

        while(true){
            String input = br.readLine();

            int now = Integer.parseInt(input);
            System.out.println(now + "->");
            while(now != 0){
                System.out.print(parent[now] + "->");
                now = parent[now];
            }
            System.out.println();
        }
    }
}
