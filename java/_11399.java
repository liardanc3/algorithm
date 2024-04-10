import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class _11399 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N, p, answer;
    public static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        for(int i=0; i<input.length; i++){
            list.add(Integer.parseInt(input[i]));
        }

        list.sort(Integer::compareTo);

        for(int i=0; i<list.size(); i++){
            answer += (list.get(i) * (list.size() - i));
        }

        System.out.println(answer);

    }
}
