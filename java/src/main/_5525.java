import java.io.*;
import java.util.*;

public class _5525 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, answer, now = 1;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        String input = br.readLine();

        int len = 0;
        for(int i=0; i<input.length(); i++){
            char ch = input.charAt(i);

            if(ch == 'I'){
                if(now == 1){
                    len++;
                    now = 0;
                } else {
                    answer += Math.max(0, len-N);
                    len = 1;
                    now = 0;
                }
            } else {
                if(now == 0){
                    now = 1;
                } else {
                    answer += Math.max(0, len-N);
                    len = 0;
                    now = 1;
                }
            }

        }
        answer += Math.max(0, len-N);
        System.out.println(answer);

    }
}