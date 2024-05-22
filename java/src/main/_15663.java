import java.io.*;
import java.util.*;

public class _15663 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static List<String> list = new ArrayList<>();
    public static List<Integer> num = new ArrayList<>();
    public static int[] visited = new int[9];

    public static void main(String[] args) throws IOException { 
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        for(int i=1; i<=N; i++){
            num.add(Integer.parseInt(input[i-1]));
        }
        num.sort(Integer::compareTo);

        dfs(0, "");
        list.stream().distinct().forEach(
                str -> sb.append(str).append("\n")
        );
        System.out.println(sb);
    }

    private static void dfs(int len, String str){
        if(len == M){
            list.add(str);
            return;
        }

        for(int i=1; i<=N; i++){
            if(visited[i-1] == 0){
                visited[i-1] = 1;
                dfs(len+1, str+String.valueOf(num.get(i-1))+" ");
                visited[i-1] = 0;
            }
        }
    }
}