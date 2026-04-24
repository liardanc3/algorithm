import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class _10816 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static HashMap<String, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        Arrays.stream(br.readLine().split(" "))
                .forEach(number -> map.merge(number, 1, Integer::sum));

        N = Integer.parseInt(br.readLine());

        Arrays.stream(br.readLine().split(" "))
                .iterator()
                .forEachRemaining(number -> sb.append(map.containsKey(number) ? map.get(number) : "0").append(" "));

        System.out.println(sb.toString());
    }
}
