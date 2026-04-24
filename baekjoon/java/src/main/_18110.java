import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class _18110 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static List<Long> list = new ArrayList<>();
    public static Long answer = 0L;

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        for(int i=0; i<N; i++){
            list.add(Long.parseLong(br.readLine()));
        }

        list.sort((a, b) -> {
            return a > b ? 1 : a < b ? -1 : 0;
        });

        long cut = Math.round((((list.size() * 15.f) / 100.f)));

        for(long i = cut; i < list.size() - cut; i++){
            answer += list.get((int) i);
        }

        float result = (float) answer / (list.size() - 2 * cut);
        System.out.println(Math.round(result));

    }
}
