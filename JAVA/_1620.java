import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class _1620 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N,M;
    public static Map<Object, Object> m = new HashMap<>();

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i=1; i<=N; i++){
            String poke = br.readLine();

            m.put(poke, i);
            m.put(Integer.valueOf(i), poke);
        }

        for(int i=1; i<=M; i++){
            String tag = br.readLine();
            if(tag.matches("-?\\d+")){
                sb.append(m.get(Integer.parseInt(tag)));
            } else {
                sb.append(m.get(tag));
            }
            sb.append("\n");
        }

        System.out.println(sb.toString());
    }
}
