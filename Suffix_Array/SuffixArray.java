import java.util.Arrays;
import java.util.Comparator;

public class SuffixArray {
    static Integer[] buildSuffixArray(String s) {
        int n = s.length();

        // tombok feltoltese
        Integer[] suffixArray = new Integer[n];
        int[] rank = new int[n];
        int[] newRank = new int[n];

        // kezdetleges ertekek adasa, amikor csak 1 hosszuakat nezunk
        for (int i = 0; i < n; i++) {
            suffixArray[i] = i;

            // karakter kodja a kezdetleges rang
            rank[i] = s.charAt(i);
        }

        // 1 << step == 2^step
        for (int step = 0; (1 << step) < n; step++) {
            // a csodalatos Java nyelv oromei :)
            final int st = step;
            final int[] r = rank;
            Comparator<Integer> cmp = (a, b) -> {
                if (r[a] != r[b]) return r[a] - r[b];
                else return r[a + (1 << st)] - r[b + (1 << st)];
            };

            // lerendezzuk a tombot
            Arrays.sort(suffixArray, cmp);

            // melyik rangu osztalynal jarunk jelenleg
            int rankAt = 0;
            newRank[suffixArray[0]] = 0;

            // ha egy uj fajta szuffixet talalunk akkor eggyel magasabb rangot adunk neki
            for (int i = 1; i < n; i++) {
                if (cmp.compare(suffixArray[i-1], suffixArray[i]) < 0) rankAt++;
                newRank[suffixArray[i]] = rankAt;
            }

            rank = Arrays.copyOf(newRank, newRank.length);
        }

        return suffixArray;
    }

    public static void main(String... args) {
        String s = "abbacd";
        Integer[] sa = buildSuffixArray(s);
        for (Integer aSa : sa) {
            System.out.println(aSa + " = " + s.substring(aSa));
        }
    }
}
