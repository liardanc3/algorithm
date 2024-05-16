import java.io.*;
import java.util.*;

public class _2606 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M, a, b, cnt;
    public static int[] visited = new int[101];
    public static List<Integer>[] list = new List[101];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        for(int i=1; i<=N; i++){
            list[i] = new ArrayList<>();
        }
        for(int i=0; i<M; i++){
            String[] input = br.readLine().split(" ");
            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);

            list[a].add(b);
            list[b].add(a);
        }
        dfs(1);

        System.out.println(cnt);
    }

    private static void dfs(int now){
        visited[now] = 1;

        for(int i=0; i<list[now].size(); i++){
            int next = list[now].get(i);

            if(visited[next] != 1){
                cnt++;
                dfs(next);
            }
        }
    }
}
