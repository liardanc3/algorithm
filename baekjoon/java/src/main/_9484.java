package main;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

import static java.util.Collections.sort;

public class _9484 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();

    public static int n, x, y;

    public static double mn = Double.MAX_VALUE;
    public static double mx = Double.MIN_VALUE;

    public static List<Point> pointList = new ArrayList<>();
    public static List<Line> lineList = new ArrayList<>();

    public static short[] sortRankToPointIdArr = new short[2001];
    public static short[] pointIdToSortRankArr = new short[2001];

    static class Point implements Comparable<Point> {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        static Point of(int x, int y) {
            return new Point(x, y);
        }

        @Override
        public int compareTo(Point p) {
            if (this.x != p.x) {
                return Integer.compare(this.x, p.x);
            }
            return Integer.compare(this.y, p.y);
        }
    }

    static class Line implements Comparable<Line> {
        short aIdx;
        short bIdx;

        Point a;
        Point b;

        public Line(Point a, short aIdx, Point b, short bIdx) {
            this.a = a;
            this.b = b;
            this.aIdx = aIdx;
            this.bIdx = bIdx;
        }

        static Line of(Point a, short aIdx, Point b, short bIdx) {
            return new Line(a, aIdx, b, bIdx);
        }

        private void swap() {
            short aRank = pointIdToSortRankArr[aIdx];
            short bRank = pointIdToSortRankArr[bIdx];

            pointIdToSortRankArr[aIdx] = bRank;
            pointIdToSortRankArr[bIdx] = aRank;

            sortRankToPointIdArr[bRank] = aIdx;
            sortRankToPointIdArr[aRank] = bIdx;
        }

        private double getTriangleAreaByPoint(Point c) {
            return Math.abs(0.5 * ((a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y)));
        }

        @Override
        public int compareTo(Line l) {
            if ((b.y - a.y) * (l.b.x - l.a.x) != (l.b.y - l.a.y) * (b.x - a.x)) {
                return (b.y - a.y) * (l.b.x - l.a.x) > (l.b.y - l.a.y) * (b.x - a.x) ? 1 : -1;
            }
            return 0;
        }
    }

    public static void main(String[] args) throws IOException {
        while (true) {
            System.gc();
            n = Integer.parseInt(br.readLine());
            if (n == 0) {
                break;
            }

            mn = Double.MAX_VALUE;
            mx = Double.MIN_VALUE;

            for (short i = 0; i < n; i++) {
                sortRankToPointIdArr[i] = i;
                pointIdToSortRankArr[i] = i;
            }

            for (short i = 0; i < n; i++) {
                sortRankToPointIdArr[i] = i;
                pointIdToSortRankArr[i] = i;
            }

            pointList.clear();
            for (int i = 1; i <= n; i++) {
                String line = br.readLine();

                x = Integer.parseInt(line.split(" ")[0]);
                y = Integer.parseInt(line.split(" ")[1]);

                pointList.add(Point.of(x, y));
            }
            sort(pointList);

            lineList.clear();
            for (short i = 0; i < pointList.size() - 1; i++) {
                for (short j = (short) (i + 1); j < pointList.size(); j++) {
                    lineList.add(Line.of(pointList.get(i), i, pointList.get(j), j));
                }
            }
            sort(lineList);

            for (Line now : lineList) {
                int leftSortRank = pointIdToSortRankArr[now.aIdx];
                int rightSortRank = pointIdToSortRankArr[now.bIdx];

                // A 왼쪽
                int minCandidateA = leftSortRank - 1;
                if (0 <= minCandidateA) {
                    int pointId = sortRankToPointIdArr[minCandidateA];

                    if (pointId != now.aIdx && pointId != now.bIdx) {
                        mn = Math.min(mn, now.getTriangleAreaByPoint(pointList.get(pointId)));
                    }
                }

                // B 오른쪽
                int minCandidateB = rightSortRank + 1;
                if (minCandidateB <= n - 1) {
                    int pointId = sortRankToPointIdArr[minCandidateB];

                    if (pointId != now.aIdx && pointId != now.bIdx) {
                        mn = Math.min(mn, now.getTriangleAreaByPoint(pointList.get(pointId)));
                    }
                }

                // 처음
                int maxCandidateA = 0;
                if (sortRankToPointIdArr[maxCandidateA] != now.aIdx && sortRankToPointIdArr[maxCandidateA] != now.bIdx) {
                    int pointId = sortRankToPointIdArr[maxCandidateA];

                    mx = Math.max(mx, now.getTriangleAreaByPoint(pointList.get(pointId)));
                }

                // 마지막
                int maxCandidateB = n - 1;
                if (sortRankToPointIdArr[maxCandidateB] != now.aIdx && sortRankToPointIdArr[maxCandidateB] != now.bIdx) {
                    int pointId = sortRankToPointIdArr[maxCandidateA];

                    mx = Math.max(mx, now.getTriangleAreaByPoint(pointList.get(pointId)));
                }

                now.swap();
            }

            System.out.printf("%.1f %.1f%n", mn, mx);
        }
    }
}
