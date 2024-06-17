import java.io.*;
import java.util.*;

public class _9935 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static String src, target;
    public static Deque<Character> deque = new ArrayDeque<>();
    public static Stack<Character> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        src = br.readLine();
        target = new StringBuilder(br.readLine()).reverse().toString();

        for(int i=0; i < src.length(); i++){
            deque.addLast(src.charAt(i));

            boolean isEqual = deque.size() >= target.length();
            for(int j=0; j<target.length() && isEqual; j++){
                Character ch = deque.pollLast();

                stack.add(ch);
                if(ch.charValue() != target.charAt(j)){
                    isEqual = false;
                }
            }

            if(!isEqual){
                while(!stack.isEmpty()){
                    deque.addLast(stack.pop());
                }
            } else {
                stack.clear();
            }
        }

        StringBuilder answer = new StringBuilder();
        while(!deque.isEmpty()){
            answer.append(deque.pollFirst());
        }
        System.out.println(answer.isEmpty() ? "FRULA" : answer);
    }

}
