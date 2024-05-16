import java.io.*;
import java.util.*;

public class _1008 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        String input[] = br.readLine().split(" ");

        System.out.println(Double.parseDouble(input[0])/Double.parseDouble(input[1]));

    }
}