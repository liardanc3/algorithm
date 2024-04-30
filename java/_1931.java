import java.io.*;
import java.util.*;

class Pair {
    int a;
    int b;

    Pair(int a, int b){
        this.a=a;
        this.b=b;
    }
}
public class _1931 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N,a,b, cnt;
    public static PriorityQueue<Pair> pq = new PriorityQueue<>(
            (p1, p2) -> {
               if(p1.a != p2.a){
                   return p1.a > p2.a ? 1 : -1;
               } else {
                   return p1.b > p2.b ? 1 : -1;
               }
            });

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        while(N-- > 0){
            String[] input = br.readLine().split(" ");

            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);

            pq.add(new Pair(a,b));
        }

        Pair p = pq.poll();
        cnt++;
        int s = p.a;
        int d = p.b;
        while(!pq.isEmpty()){
            Pair now = pq.poll();

            int src = now.a;
            int dst = now.b;

            if(src >= d){
                cnt++;
                d = dst;
            } else if(dst < d){
                d = dst;
            }
        }

        System.out.println(cnt);
    }
}