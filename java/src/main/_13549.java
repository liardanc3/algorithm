import java.io.*;
import java.util.*;

public class _13549 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static Queue<Integer> q = new ArrayDeque<>();
    public static int[] visited = new int[110001];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        if(N >= M){
            System.out.println(N-M);
        } else {
            System.out.println(bfs());
        }
    }

    private static int bfs(){
        q.add(M);
        visited[M] = 1;
        while(M%2 == 0){
            M /= 2;
            q.add(M);
            visited[M] = 1;
        }

        int answer = 0;

        while(!q.isEmpty()){
            int size = q.size();

            while(size-- > 0){
                int now = q.poll();

                if(now == N){
                    return answer;
                }

                if(now - 1 >= 0 && visited[now-1] == 0){
                    int next = now - 1;

                    if(visited[next] == 0){
                        visited[next] = 1;
                        q.add(next);

                        while(next % 2 == 0){
                            next /= 2;
                            if(visited[next] == 0){
                                visited[next] = 1;
                                q.add(next);
                            } else {
                                break;
                            }
                        }
                    }
                }

                if(now + 1 <= 110000 && visited[now+1] == 0){
                    int next = now + 1;

                    if(visited[next] == 0){
                        visited[next] = 1;
                        q.add(next);

                        while(next % 2 == 0){
                            next /= 2;
                            if(visited[next] == 0){
                                visited[next] = 1;
                                q.add(next);
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
            answer++;
        }
        return answer;
    }
}