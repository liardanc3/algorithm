import java.io.*;
import java.util.*;

public class _11725 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N;
    public static List<List<Integer>> list = new ArrayList<>();
    public static int[] visited = new int[100001];
    public static int[] parent = new int[100001];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        for(int i=0; i<=100000; i++){
            list.add(new ArrayList<>());
        }

        for(int i=0; i<N-1; i++){
            String[] input = br.readLine().split(" ");

            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);

            list.get(src).add(dst);
            list.get(dst).add(src);
        }

        dfs(1);
        for(int i=2; i<=N; i++){
            sb.append(parent[i]).append("\n");
        }
        System.out.println(sb);
    }

    private static void dfs(int now){
        visited[now] = 1;

        for(int i=0; i<list.get(now).size(); i++){
            int next = list.get(now).get(i);

            if(visited[next] == 0){
                parent[next] = now;
                dfs(next);
            }
        }
    }
}