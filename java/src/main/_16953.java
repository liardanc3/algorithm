package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class _16953 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static Map<Integer, Integer> dp = new HashMap<>();

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        dynamic(M, 0);
        System.out.println(dp.containsKey(N) ? dp.get(N) + 1 : "-1");
    }

    private static void dynamic(int n, int depth) {
        if(n==0) return;
        if(n == N){
            if(dp.containsKey(n) && dp.get(n) > depth){
                dp.put(n, depth);
            } else if(!dp.containsKey(n)){
                dp.put(n, depth);
            }
            return;
        }
        if(n%10 == 1){
            if(dp.containsKey(n/10) && dp.get(n/10) <= depth + 1){
                return;
            }
            dynamic(n/10, depth + 1);
        }
        if(n%2 == 0){
            if(dp.containsKey(n/2) && dp.get(n/2) <= depth + 1){
                return;
            }
            dynamic(n/2, depth + 1);
        }
    }
}

