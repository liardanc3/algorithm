import java.io.*;
import java.util.*;

public class _1260 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, V, src, dst;
    public static ArrayList<Integer>[] list = new ArrayList[1001];
    public static int[] visited = new int[1001];

    public static void main(String[] args) throws IOException {
        for(int i=0; i<=1000; i++){
            list[i] = new ArrayList<>();
        }

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        V = Integer.parseInt(input[2]);

        for(int i=0; i<M; i++){
            input = br.readLine().split(" ");

            src = Integer.parseInt(input[0]);
            dst = Integer.parseInt(input[1]);

            list[src].add(dst);
            list[dst].add(src);
        }
        for(int i=1; i<=N; i++){
            if(!list[i].isEmpty()){
                list[i].sort((a, b) -> a > b ? 1 : -1);
            }
        }

        dfs(V);
        sb.append("\n");
        for(int i=0; i<=N; i++){
            visited[i] = 0;
        }
        bfs(V);

        System.out.println(sb);
    }

    private static void dfs(int now){
        sb.append(now).append(" ");
        visited[now] = 1;

        for (Integer next : list[now]) {
            if(visited[next] != 1){
                dfs(next);
            }
        }

    }

    private static void bfs(int now){
        visited[now] = 1;
        LinkedList<Integer> queue = new LinkedList<>();

        queue.add(now);
        while(!queue.isEmpty()){
            int next = queue.pop();

            sb.append(next).append(" ");

            for(Integer nnext : list[next]){
                if(visited[nnext] != 1){
                    visited[nnext] = 1;
                    queue.add(nnext);
                }
            }
        }
    }


}