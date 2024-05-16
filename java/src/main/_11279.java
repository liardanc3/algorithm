import java.io.*;
import java.util.*;

public class _11279 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, x;
    public static PriorityQueue<Integer> pq = new PriorityQueue<>(
            (a,b) -> a < b ? 1 : -1
    );

    public static void main(String[] args) throws IOException { 
        N = Integer.parseInt(br.readLine());

        while(N-- > 0){
            x = Integer.parseInt(br.readLine());

            if(x==0){
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