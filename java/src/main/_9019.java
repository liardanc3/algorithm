import java.io.*;
import java.util.*;

public class _9019 {

    static class Pair {
        int now;
        String cmd;

        public Pair(int now, String cmd) {
            this.now = now;
            this.cmd = cmd;
        }
    }
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int T, A, B;
    public static int[] visited = new int[10000];
    public static Queue<Pair> q = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            String[] input = br.readLine().split(" ");

            A = Integer.parseInt(input[0]);
            B = Integer.parseInt(input[1]);

            bfs();
            for(int i = 0; i < 10000; i++){
                visited[i] = 0;
            }
            q.clear();
        }

        System.out.println(sb);
    }

    private static void bfs() {
        visited[A] = 1;
        q.add(new Pair(A, ""));

        while(!q.isEmpty()){
            Pair p = q.poll();
            int now = p.now;
            String cmd = p.cmd;

            if(now == B){
                sb.append(cmd).append("\n");
                return;
            }

            // D
            int next = (now*2) % 10000;
            if(visited[next] == 0){
                visited[next] = 1;
                q.add(new Pair(next, cmd + "D"));
            }

            // S
            next = (10000 + now - 1) % 10000;
            if(visited[next] == 0){
                visited[next] = 1;
                q.add(new Pair(next, cmd + "S"));
            }

            // L
            next = (now * 10 + now / 1000) % 10000;
            if(visited[next] == 0){
                visited[next] = 1;
                q.add(new Pair(next, cmd + "L"));
            }

            // R
            next = (now / 10 + now % 10 * 1000);
            if(visited[next] == 0){
                visited[next] = 1;
                q.add(new Pair(next, cmd + "R"));
            }
        }
    }
}
