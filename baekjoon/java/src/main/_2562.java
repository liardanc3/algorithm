import java.io.*;
import java.util.*;

public class _2562 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int answer, idx;
    public static void main(String[] args) throws IOException {
        for(int i=0; i<9; i++){
            int input = Integer.parseInt(br.readLine());

            answer = Math.max(answer, input);

            if(input == answer){
                idx = i+1;
            }
        }

        System.out.println(answer + "\n" + idx);

    }
}