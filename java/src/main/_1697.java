import java.io.*;
import java.util.*;

public class _1697 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int a,b;
    public static int[] visited = new int[200001];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        a = Integer.parseInt(input[0]);
        b = Integer.parseInt(input[1]);

        if(a>=b){
            System.out.println(Math.abs(a-b));
        } else {
            System.out.println(bfs());
        }

    }

    private static int bfs(){
        int answer = 0;
        Queue<Integer> q = new ArrayDeque<>();

        q.add(a);
        visited[a] = 1;
        while(!q.isEmpty()){
            int size = q.size();

            while(size-- > 0){
                int now = q.poll();

                if(now == b){
                    return answer;
                }

                if(now-1 >= 0 && visited[now-1] == 0){
                    visited[now-1] = 1;
                    q.add(now - 1);
                }
                if(now+1 <= 200000 && visited[now+1] == 0){
                    visited[now+1] = 1;
                    q.add(now + 1);
                }
                if(now*2 <= 200000 && visited[now*2] == 0){
                    visited[now*2]=1;
                    q.add(now * 2);
                }
            }

            answer++;
        }
        return answer;
    }

}