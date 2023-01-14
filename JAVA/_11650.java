import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class _11650 {

    public static void main(String[] args) throws IOException{

        class Point {
            int x;
            int y;
            Point(int x, int y) {
                this.x = x;
                this.y = y;
            }
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        List<Point> pointList = new ArrayList<>();
        while(N-- > 0){
            String[] input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            pointList.add(new Point(x,y));
        }
        Collections.sort(pointList, new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                return o1.x<o2.x?-1:o1.x>o2.x?1:o1.y<o2.y?-1:1;
            }
        });
        for(Point p : pointList)
            bw.write(p.x + " " + p.y + "\n");

        bw.flush();
        bw.close();
        br.close();
    }
}
