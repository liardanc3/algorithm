package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class _15666 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static List<Integer> list = new ArrayList<>();
    public static List<String> answer = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        for(int i=0; i<N; i++){
            list.add(Integer.parseInt(input[i]));
        }
        list.sort(Integer::compareTo);

        dfs(0, 0, "");

        answer.stream().distinct().forEach(str -> sb.append(str).append("\n"));
        System.out.println(sb);
    }

    private static void dfs(int now, int len, String str){
        if(len == M){
            answer.add(str);
            return;
        }

        for(int i=now; i<N; i++){
            dfs(i,len + 1, str + list.get(i) + " ");
        }
    }
}

