import java.io.*;
import java.util.*;

public class _11286 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static PriorityQueue<Integer> pq = new PriorityQueue<>(
            (a, b) -> {
                if(Math.abs(a) > Math.abs(b)){
                    return 1;
                } else if(Math.abs(a) == Math.abs(b) && a > b){
                    return 1;
                } else{
                    return -1;
                }
            }
    );
    public static int N, x;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        while(N-- > 0){
            x = Integer.parseInt(br.readLine());

            if(x == 0){
                if(pq.isEmpty()){
                    sb.append(0).append("\n");
                } else {
                    sb.append(pq.poll()).append("\n");
                }
            } else {
                pq.add(x);
            }
        }

        System.out.println(sb);
    }
}