import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class _2108 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static int[] answer3List = new int[8080];
    public static int answer3Order = 0;
    public static int answer3Count = 0;
    public static int answer3 = 0;
    public static List<Integer> list = new ArrayList<>();
    public static int sum = 0;

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        for(int i=0; i<N; i++){
            int input = Integer.parseInt(br.readLine());
            sum += input;
            list.add(input);
            answer3List[input+4000]++;
        }

        list.sort(Integer::compareTo);

        for(int i=0; i<=8001; i++){
            if(answer3List[i] > answer3Count){
                answer3 = i - 4000;
                answer3Count = answer3List[i];
                answer3Order = 1;
            } else if(answer3List[i] == answer3Count){
                if(answer3Order < 2){
                    answer3 = i - 4000;
                    answer3Count = answer3List[i];
                    answer3Order++;
                }
            }
        }

        sb.append(Math.round((float) sum / list.size()))
                .append("\n")
                .append(list.get(list.size()/2))
                .append("\n")
                .append(answer3)
                .append("\n")
                .append(list.get(list.size()-1) - list.get(0));

        System.out.println(sb.toString());
    }
}
