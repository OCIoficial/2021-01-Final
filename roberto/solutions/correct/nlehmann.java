import java.util.*;
import java.io.*;

class roberto {
  public static void main(String[] args) throws Exception {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(in.readLine());

    int H = Integer.parseInt(st.nextToken());
    int W = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int N = Integer.parseInt(st.nextToken());

    int terrain[][] = new int[H][W];
    for (int i = 0; i < H; ++i) {
      st = new StringTokenizer(in.readLine());
      for (int j = 0; j < W; ++j) {
        terrain[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    int mins_for_row[][] = new int[H][];
    int maxs_for_row[][] = new int[H][];
    for (int i = 0; i < H; ++i) {
      Pair<int[]> p = compute_min_max_arrs(terrain[i], N);
      mins_for_row[i] = p.x;
      maxs_for_row[i] = p.y;
    }

    int best = Integer.MAX_VALUE;
    for (int j = 0; j + N - 1 < W; ++j) {
      TreeMap<Integer, Integer> elements_min = new TreeMap<>();
      TreeMap<Integer, Integer> elements_max = new TreeMap<>();

      for (int i = 0; i < M; ++i) {
        insert(elements_min, mins_for_row[i][j]);
        insert(elements_max, maxs_for_row[i][j]);
      }
      best = Math.min(best, elements_max.lastKey() - elements_min.firstKey());
      for (int i = 1; i + M - 1 < H; ++i) {
        remove(elements_min, mins_for_row[i - 1][j]);
        insert(elements_min, mins_for_row[i + M - 1][j]);

        remove(elements_max, maxs_for_row[i - 1][j]);
        insert(elements_max, maxs_for_row[i + M - 1][j]);

        best = Math.min(best, elements_max.lastKey() - elements_min.firstKey());
      }
    }

    System.out.println(best);
  }

  static Pair<int[]> compute_min_max_arrs(int arr[], int w) {
    int mins[] = new int[arr.length - w + 1];
    int maxs[] = new int[arr.length - w + 1];
    TreeMap<Integer, Integer> elements = new TreeMap<>();
    for (int i = 0; i < w; ++i) {
      insert(elements, arr[i]);
    }
    mins[0] = elements.firstKey();
    maxs[0] = elements.lastKey();

    for (int i = 1; i + w - 1 < arr.length; ++i) {
      remove(elements, arr[i - 1]);
      insert(elements, arr[i + w - 1]);
      mins[i] = elements.firstKey();
      maxs[i] = elements.lastKey();
    }
    return new Pair(mins, maxs);
  }

  static void insert(TreeMap<Integer, Integer> set, int element) {
    int n = set.containsKey(element) ? set.get(element) : 0;
    set.put(element, n + 1);
  }

  static void remove(TreeMap<Integer, Integer> set, int element) {
    if (set.containsKey(element)) {
      int n = set.get(element);
      if (n == 1) {
        set.remove(element);
      } else {
        set.put(element, n - 1);
      }
    }
  }
}

class Pair<T> {
  T x, y;

  public Pair(T x, T y) {
    this.x = x;
    this.y = y;
  }
}
