import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class _1764 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;
    public static Set<String> set = new HashSet<>();
    public static List<String> emeqhwkq = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i=0; i<N; i++){
            set.add(br.readLine());
        }

        for(int i=0; i<M; i++){
            String s = br.readLine();
            if(set.contains(s)){
                emeqhwkq.add(s);
            }
        }

        emeqhwkq.sort(String::compareTo);

        sb.append(emeqhwkq.size()).append("\n");
        emeqhwkq.forEach(name -> sb.append(name).append("\n"));

        System.out.println(sb.toString());
    }
}
