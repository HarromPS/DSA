package Java.Test;

import java.util.*;

/*

Try This


1. Input:
0 0 0 1 3 3
0 0 1 2 3 3
3 2 4

Output: 
2 2 3 3 3 3 
1 1 2 3 3 3 

2. Input:
0 0 1 2 3 3 
0 0 0 1 2 3
2 0 1

Output: 
1 1 2 3 3 3
0 0 1 2 3 3 

 */
public class Sarvaha_2_8_2024 {
    public static void solve() {
        // gather all the category citizens
        Map<Integer, Integer> people_freq = new HashMap<>();
        people_freq.put(1, 0); // initially
        people_freq.put(2, 0);
        people_freq.put(3, 0);

        int n1 = 6, n2 = 6;

        Scanner sc = new Scanner(System.in);

        // from 1st queue
        for (int i = 0; i < n1; i++) {
            int ip = sc.nextInt();
            if (ip != 0) {
                people_freq.put(ip, people_freq.get(ip) + 1);
            }
        }

        // from 2nd queue
        for (int i = 0; i < n2; i++) {
            int ip = sc.nextInt();
            if (ip != 0) {
                people_freq.put(ip, people_freq.get(ip) + 1);
            }
        }

        // extra standing people
        for (int i = 0; i < 3; i++) {
            int ip = sc.nextInt();
            if (ip != 0) {
                people_freq.put(3 - i, people_freq.get(3 - i) + ip);
            }
        }

        // segregate people for h1 and h2
        int seniors = people_freq.get(3);
        int ladies = people_freq.get(2);
        int males = people_freq.get(1);

        // seniors for copter 1 & 2
        int h1_sen = seniors / 2;
        int h2_sen = seniors / 2;
        if (seniors % 2 == 1) {
            h1_sen = (seniors / 2) + 1;
            h2_sen = (seniors / 2);
        }

        // ladies for copter 1 & 2
        int h1_lad = ladies / 2;
        int h2_lad = ladies / 2;
        if (ladies % 2 == 1) {
            h1_lad = (ladies / 2) + 1;
            h2_lad = (ladies / 2);
        }

        // males for copter 1 & 2
        int h1_males = males / 2;
        int h2_males = males / 2;
        if (males % 2 == 1) {
            h1_males = (males / 2) + 1;
            h2_males = (males / 2);
        }

        // helicopter 1 and 2
        List<Integer> h1 = new ArrayList<>();
        List<Integer> h2 = new ArrayList<>();

        // fill seniors
        while (h1_sen > 0) {
            h1.add(3);
            h1_sen--;
        }
        while (h2_sen > 0) {
            h2.add(3);
            h2_sen--;
        }

        // fill ladies
        while (h1_lad > 0) {
            h1.add(2);
            h1_lad--;
        }
        while (h2_lad > 0) {
            h2.add(2);
            h2_lad--;
        }

        // fill males
        while (h1_males > 0) {
            h1.add(1);
            h1_males--;
        }
        while (h2_males > 0) {
            h2.add(1);
            h2_males--;
        }

        // fill empty spaces
        int x = h1.size();
        while (x < 6) {
            h1.add(0);
            x++;
        }

        x = h2.size();
        while (x < 6) {
            h2.add(0);
            x++;
        }

        List<Integer> a1 = new ArrayList<>();
        List<Integer> a2 = new ArrayList<>();
        for (int i = 0; i < h1.size() && i < 6; i++) {
            a1.add(h1.get(i));
        }

        for (int i = 0; i < h2.size() && i < 6; i++) {
            a2.add(h2.get(i));
        }

        Collections.sort(a1);
        Collections.sort(a2);

        System.out.println("\nOutput:");
        for (int i = 0; i < a1.size(); i++) {
            System.out.print(a1.get(i) + " ");
        }
        System.out.println();

        for (int i = 0; i < a2.size(); i++) {
            System.out.print(a2.get(i) + " ");
        }
        System.out.println();
        sc.close();
    }

    public static void main(String[] args) {
        // input of 3 lines
        System.out.println("Input:");
        solve();
    }
}
