import java.io.*;
import java.util.*;

public class _1927 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, input;
    public static PriorityQueue<Integer> pq = new PriorityQueue<>(
            (a, b) -> a > b ? 1 : -1
    );

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        while(N-- > 0){
            input = Integer.parseInt(br.readLine());
            if(input == 0){
                if(pq.isEmpty()){
                    sb.append("0\n");
                } else{
                    sb.append(pq.poll()).append("\n");
                }
            }else{
                pq.add(input);
            }

        }

        System.out.println(sb);
    }
}