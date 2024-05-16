import java.io.*;
import java.util.*;

public class _11724 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, cnt;
    public static List<Integer>[] list = new ArrayList[1001];
    public static int[] visited = new int[1001];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        for(int i=1; i<=N; i++){
            list[i] = new ArrayList<>();
        }

        for(int i=0; i<M; i++){
            input = br.readLine().split(" ");

            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);

            list[src].add(dst);
            list[dst].add(src);
        }

        for(int i=1; i<=N; i++){
            if(visited[i] == 0){
                dfs(i);
                cnt++;
            }
        }

        System.out.println(cnt);

    }

    private static void dfs(int now){
        visited[now] = 1;

        for(int i=0; i<list[now].size(); i++){
            int next = list[now].get(i);

            if(visited[next] == 0){
                dfs(next);
            }
        }
    }
}