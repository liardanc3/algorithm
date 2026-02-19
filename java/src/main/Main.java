package main;

import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static String input;
    public static int n, m, k;
    public static int[] tree = new int[1001];
    public static List<int[]> edges = new ArrayList<>();
    public static List<Integer> result = new ArrayList<>();

    public static int getRoot(int i) {
        return (tree[i] == i) ? i : (tree[i] = getRoot(tree[i]));
    }

    public static void main(String[] args) throws IOException {

        input = br.readLine();
        n = Integer.parseInt(input.split(" ")[0]);
        m = Integer.parseInt(input.split(" ")[1]);
        k = Integer.parseInt(input.split(" ")[2]);

        for (int i = 0; i < m; i++) {
            input = br.readLine();
            String[] arr = input.split(" ");
            int color = arr[0].equals("B") ? 0 : 1;
            int a = Integer.parseInt(arr[1]);
            int b = Integer.parseInt(arr[2]);
            edges.add(new int[]{color, a, b});
        }

        for (int i = 1; i <= n; i++) tree[i] = i;
        for (int[] e : edges) {
            if (e[0] == 1) {
                int ra = getRoot(e[1]);
                int rb = getRoot(e[2]);
                if (ra != rb) tree[ra] = rb;
            }
        }

        boolean[] isEssential = new boolean[m];
        int currentBlue = 0;

        for (int i = 0; i < m; i++) {
            int[] e = edges.get(i);
            if (e[0] == 0) {
                int ra = getRoot(e[1]);
                int rb = getRoot(e[2]);
                if (ra != rb) {
                    tree[ra] = rb;
                    isEssential[i] = true;
                    result.add(i);
                    currentBlue++;
                }
            }
        }

        for (int i = 1; i <= n; i++) tree[i] = i;

        for (int e : result) {
            tree[getRoot(edges.get(e)[1])] = getRoot(edges.get(e)[2]);
        }

        for (int i = 0; i < m; i++) {
            int[] e = edges.get(i);
            if (e[0] == 0 && !isEssential[i] && currentBlue < k) {
                int ra = getRoot(e[1]);
                int rb = getRoot(e[2]);
                if (ra != rb) {
                    tree[ra] = rb;
                    result.add(i);
                    currentBlue++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int[] e = edges.get(i);
            if (e[0] == 1) {
                int ra = getRoot(e[1]);
                int rb = getRoot(e[2]);
                if (ra != rb) {
                    tree[ra] = rb;
                    result.add(i);
                }
            }
        }

        if (result.size() == n - 1 && currentBlue == k) {
            for (int e : result) {
                bw.write(edges.get(e)[1] + " " + edges.get(e)[2] + "\n");
            }
            bw.flush();
        } else {
            System.out.println(0);
        }
    }
}