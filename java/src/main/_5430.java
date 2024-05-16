import java.io.*;
import java.util.*;

public class _5430 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int T, n;
    public static boolean isFirst;
    public static String p, input;
    public static Deque<Integer> deque = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            deque.clear();
            isFirst = true;

            p = br.readLine();
            n = Integer.parseInt(br.readLine());
            input = br.readLine();
            if(n != 0){
                Arrays.stream(input.substring(1, input.length() - 1).split(","))
                        .forEach(x -> deque.addLast(Integer.parseInt(x)));
            }

            try {
                for(int i=0; i<p.length(); i++) {
                    char ch = p.charAt(i);

                    if(ch == 'R'){
                        isFirst = !isFirst;
                    } else {
                        if(deque.isEmpty()){
                            throw new RuntimeException();
                        }
                        if(isFirst){
                            deque.pollFirst();
                        } else {
                            deque.pollLast();
                        }
                    }
                }

                sb.append("[");
                while(!deque.isEmpty()){
                    if(isFirst){
                        sb.append(deque.pollFirst());
                    } else {
                        sb.append(deque.pollLast());
                    }

                    if(!deque.isEmpty()){
                        sb.append(",");
                    }
                }
                sb.append("]\n");
            } catch (RuntimeException e) {
                sb.append("error\n");
            }
        }

        System.out.println(sb);

    }
}