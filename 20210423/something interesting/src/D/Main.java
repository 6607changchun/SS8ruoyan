package D;

import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int cases = Integer.parseInt(input.nextLine());
        for (int j = 0; j < cases; j++) {
            input.nextLine();
            String[] cnt = input.nextLine().split(" ");
            int n = Integer.parseInt(cnt[0]);
            String text = input.nextLine();
            HashSet<String> set = new HashSet<>();
            int t = text.length() - n;
            for (int i = 0; i <= t; i++)
                set.add(text.substring(i, i + n));
            System.out.println(set.size());
            System.out.println();
        }
    }
}
