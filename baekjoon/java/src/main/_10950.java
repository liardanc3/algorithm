import java.io.*;
import java.util.*;

public class _10950 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        while(t-- > 0){
            String[] input = br.readLine().split(" ");

            System.out.println(Integer.parseInt(input[0])
            +
                    Integer.parseInt(input[1]));
        }

    }
}