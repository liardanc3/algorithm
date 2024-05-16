import java.io.*;
import java.sql.Array;
import java.util.*;

public class _16928 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int[] visited = new int[101];
    public static Map<Integer, Integer> m = new HashMap<>();
    public static Queue<Integer> q = new ArrayDeque<>();
    public static int N, M, x, y;

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i = 0; i < N + M; i++){
            input = br.readLine().split(" ");

            x = Integer.parseInt(input[0]);
            y = Integer.parseInt(input[1]);

            m.put(x,y);
        }

        System.out.println(bfs());
    }

    private static int bfs(){
        visited[1] = 1;
        q.add(1);

        int answer = 1;

        while(!q.isEmpty()){
            int size = q.size();

            while(size-- > 0){
                int now = q.poll();

                for(int i=1; i<=6; i++){
                    int next = now + i;

                    if(next <= 100 && visited[next] == 0){
                        visited[next] = 1;
                        if(m.containsKey(next)){
                            next = m.get(next);
                            visited[next] = 1;
                        }
                        q.add(next);
                    }
                }
            }

            if(visited[100] == 1){
                return answer;
            }
            answer++;
        }
        return answer;

    }
}