import java.io.*;
import java.util.*;

public class _2161 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        Queue<Integer> card = new LinkedList<>();
        Queue<Integer> trash = new LinkedList<>();
        for(int i=1; i<=N; i++)
            card.add(i);
        while(card.size() > 1){
            trash.offer(card.poll());
            card.offer(card.poll());
        }

        while(!trash.isEmpty())
            bw.write(Integer.toString(trash.poll()) + ' ');
        bw.write(Integer.toString(card.poll()));

        bw.flush();
        bw.close();
        br.close();
    }
}
