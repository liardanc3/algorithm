import java.io.*;
import java.util.*;

public class _15654 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static List<Integer> list = new ArrayList<>();
    public static int[] arr = new int[9];
    public static int[] visited = new int[9];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        for(int i=0; i<N; i++){
            list.add(Integer.parseInt(input[i]));
        }
        list.sort(Comparator.naturalOrder());

        dfs(0);
        System.out.println(sb);
    }

    private static void dfs(int len){
        if(len == M){
            for(int i=0; i<M; i++){
                sb.append(arr[i]).append(" ");
            }
            sb.append("\n");

            return;
        }

        for(int i=0; i<N; i++){
            if(visited[i] == 0){
                arr[len] = list.get(i);
                visited[i] = 1;
                dfs(len+1);
                visited[i] = 0;
            }
        }
    }
}