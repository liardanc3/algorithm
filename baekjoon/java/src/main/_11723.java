import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _11723 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int M, x;
    public static int[] arr = new int[21];
    public static String cmd;

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        int M = Integer.parseInt(br.readLine());

        while(M-- > 0){
            String[] input = br.readLine().split(" ");
            if(input[0].equals("add")){
                x = Integer.parseInt(input[1]);

                arr[x] = 1;
            } else if (input[0].equals("remove")){
                x = Integer.parseInt(input[1]);

                arr[x] = 0;
            } else if (input[0].equals("check")){
                x = Integer.parseInt(input[1]);

                sb.append(arr[x]).append("\n");
            } else if (input[0].equals("toggle")){
                x = Integer.parseInt(input[1]);

                arr[x] = arr[x] == 1 ? 0 : 1;
            } else if (input[0].equals("all")){
                for(int i=1; i<=20; i++){
                    arr[i] = 1;
                }
            } else {
                for(int i=1; i<=20; i++){
                    arr[i] = 0;
                }
            }
        }

        System.out.println(sb.toString());
    }
}
