package src.main;

import java.io.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class _5622 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static Map<String, Integer> alphabetAndCostMap = new HashMap<>();
    public static int sum;

    static {
        List.of("A", "B", "C")      .forEach(alphabet -> alphabetAndCostMap.put(alphabet, 3));
        List.of("D", "E", "F")      .forEach(alphabet -> alphabetAndCostMap.put(alphabet, 4));
        List.of("G", "H", "I")      .forEach(alphabet -> alphabetAndCostMap.put(alphabet, 5));
        List.of("J", "K", "L")      .forEach(alphabet -> alphabetAndCostMap.put(alphabet, 6));
        List.of("M", "N", "O")      .forEach(alphabet -> alphabetAndCostMap.put(alphabet, 7));
        List.of("P", "Q", "R", "S") .forEach(alphabet -> alphabetAndCostMap.put(alphabet, 8));
        List.of("T", "U", "V")      .forEach(alphabet -> alphabetAndCostMap.put(alphabet, 9));
        List.of("W", "X", "Y", "Z") .forEach(alphabet -> alphabetAndCostMap.put(alphabet, 10));
    }

    public static void main(String[] args) throws IOException {
        String input = br.readLine();
        for (int i = 0; i < input.length(); i++) {
            sum += alphabetAndCostMap.get("" + input.charAt(i));
        }
        System.out.println(sum);
    }
}
