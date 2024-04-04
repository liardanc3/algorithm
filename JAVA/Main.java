import java.io.*;
import java.sql.SQLOutput;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static Stack<Integer> st = new Stack<>();

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        int K = Integer.parseInt(br.readLine());

        for(int i=0; i<K; i++){
            int input = Integer.parseInt(br.readLine());

            if(input == 0){
                st.pop();
            } else {
                st.push(input);
            }
        }

        int answer = 0;
        while(!st.empty()){
            answer += st.pop();
        }

        System.out.println(answer);
    }
}
