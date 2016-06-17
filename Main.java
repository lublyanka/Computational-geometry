import java.io.*;
import java.util.*;

public class Main {

    private static class Side implements Comparable<Side> {
        private final int length;

        private Side(int length) {
            this.length = length;
        }

        @Override
        public int compareTo(Side that) {
            return Integer.compare(this.length, that.length);
        }

        public String toString() {
            return String.valueOf(this.length);
        }
    }

    private static class Triangle {
        private final Side a, b, c;

        private Triangle(Side a, Side b, Side c) {
            Side[] sides = new Side[]{a, b, c};
            Arrays.sort(sides);

            this.a = sides[0];
            this.b = sides[1];
            this.c = sides[2];
        }

        static boolean isTriangle(Side a, Side b, Side c) {
            Side[] sides = new Side[]{a, b, c};
            Arrays.sort(sides);
            if (sides[2].length >= sides[0].length + sides[1].length) {
                return false;
            }
            return true;
        }

        public boolean isSimilarWith(Triangle that) {
            Set<Side> thisSides = new HashSet<Side>();
            Collections.addAll(thisSides, this.a, this.b, this.c);

            Set<Side> thatSides = new HashSet<Side>();
            Collections.addAll(thatSides, that.a, that.b, that.c);

            if (thisSides.removeAll(thatSides))
                return false;

            if (((double) this.a.length / this.b.length) == ((double) that.a.length / (double) that.b.length) &&
                    ((double) this.b.length / (double) this.c.length) == ((double) that.b.length / (double) that.c.length))
                return true;
            return false;
        }

        public boolean isEarlierThan(Triangle that) {
            return this.a.length < that.a.length;
        }

        public String toString() {
            return this.a + " " + b + " " + c;
        }
    }

    public static void main(String[] args) throws IOException {
        String userDir = System.getProperty("user.dir") + File.separator;
        BufferedReader reader = new BufferedReader(new FileReader(new File(userDir + "pifagor.in")));
        //файлик потёрся
        File out = new File(userDir + "pifagor.out");
        if (!out.exists()) {
            out.createNewFile();
        }
        BufferedWriter writer = new BufferedWriter(new FileWriter(out));
        String sidesLine = reader.readLine();
        String[] sidesStrings = sidesLine.split(" ");
        //number of sides
        int N = sidesStrings.length;
        Side[] sides = new Side[N];
        reader.close();

        for (int i = 0; i < N; i++) {
            sides[i] = new Side(Integer.valueOf(sidesStrings[i]));
        }

        List<Triangle> triangles = new ArrayList<Triangle>();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    Side a = sides[i];
                    Side b = sides[j];
                    Side c = sides[k];
                    if (Triangle.isTriangle(a, b, c)) {
                        triangles.add(new Triangle(a, b, c));
                    }
                }
            }
        }

        int numberOfTriangles = triangles.size();

        for (int i = 0; i < numberOfTriangles; i++) {
            for (int j = i + 1; j < numberOfTriangles; j++) {
                Triangle triangle = triangles.get(i);
                Triangle anotherTriangle = triangles.get(j);
                if (triangle.isSimilarWith(anotherTriangle)) {
                    if (triangle.isEarlierThan(anotherTriangle)) {
                        writer.write(triangle.toString());
                        writer.newLine();
                        writer.write(anotherTriangle.toString());
                        writer.close();
                        return;
                    } else {
                        writer.write(anotherTriangle.toString());
                        writer.newLine();
                        writer.write(triangle.toString());
                        writer.close();
                        return;
                    }
                }
            }
        }
    }
}
