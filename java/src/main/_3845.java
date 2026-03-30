package main;

import java.io.*;
import java.util.*;

public class _3845 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;
    public static int nx, ny, w;
    public static boolean xSeq, xRange, ySeq, yRange;
    public static List<Integer> xList = new ArrayList<>();
    public static List<Integer> yList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        while (true) {
            st = new StringTokenizer(br.readLine());

            nx = Integer.parseInt(st.nextToken());
            ny = Integer.parseInt(st.nextToken());
            w = (int) (Double.parseDouble(st.nextToken()) * 10_000_000);

            if (nx == 0 && ny == 0 && w == 0.0) {
                break;
            }

            xList.clear();
            yList.clear();
            xSeq = true;
            xRange = true;
            ySeq = true;
            yRange = true;

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < nx; i++) {
                xList.add((int) (Double.parseDouble(st.nextToken()) * 10_000_000));
            }
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < ny; j++) {
                yList.add((int) (Double.parseDouble(st.nextToken()) * 10_000_000));
            }

            xList.sort(Comparator.naturalOrder());
            yList.sort(Comparator.naturalOrder());

            for (int i = 0; i < nx - 1; i++) {
                if (xList.get(i + 1) - xList.get(i) > w) {
                    xSeq = false;
                    break;
                }
            }
            xRange = xList.get(0) <= w / 2 && xList.get(nx - 1) >= 750_000_000 - w / 2
                    && xList.get(nx - 1) - xList.get(0) + w >= 750_000_000;

            for (int i = 0; i < ny - 1; i++) {
                if (yList.get(i + 1) - yList.get(i) > w) {
                    ySeq = false;
                    break;
                }
            }
            yRange = yList.get(0) <= w / 2 && yList.get(ny - 1) >= 1_000_000_000 - w / 2
                    && yList.get(ny - 1) - yList.get(0) + w >= 1_000_000_000;

            bw.write(xSeq && xRange && ySeq && yRange ? "YES\n" : "NO\n");
        }

        bw.flush();
    }
}