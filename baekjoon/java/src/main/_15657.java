import java.io.*;
import java.util.*;

public class _15657 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static List<Integer> list = new ArrayList<>();
    public static int[] arr = new int[9];

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        for(int i=0; i<N; i++){
            list.add(Integer.parseInt(input[i]));
        }
        list.sort(Integer::compareTo);

        dfs(0, 0);
        System.out.println(sb);
    }

    private static void dfs(int now, int len){
        if(len == M){
            for(int i=0; i<N; i++){
                for(int j=0; j<arr[i]; j++){
                    sb.append(list.get(i)).append(" ");
                }
            }
            sb.append("\n");
            return;
        }

        for(int i=now; i<N; i++){
            arr[i]++;
            dfs(i, len+1);
            arr[i]--;
        }
    }
}