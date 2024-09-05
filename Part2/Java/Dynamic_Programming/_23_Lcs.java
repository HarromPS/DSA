package Java.Dynamic_Programming;

// a string is given find the palindrome in the string
// find lcs by reversing the given string as s2 & we will get the longest palindromic subsequence
public class _23_Lcs {
    public static void findLen_String(String s1, String s2) {
        int dp[][] = new int[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i < s1.length() + 1; i++) {
            for (int j = 0; j < s2.length() + 1; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i < s1.length() + 1; i++) {
            for (int j = 1; j < s2.length() + 1; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Backtrace to find the string
        String ans = "";
        int i = s1.length(), j = s2.length();
        while (i > 0 && j > 0) {
            if (dp[i][j] != dp[i - 1][j] && dp[i][j] != dp[i][j - 1] && dp[i - 1][j] == dp[i][j - 1]) {
                ans += s1.charAt(i - 1);
                i--;
                j--;
            } else if (dp[i - 1][j] != dp[i][j - 1] && (dp[i][j] == dp[i - 1][j] || dp[i][j] == dp[i][j - 1])) {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            } else {
                j--;
            }
        }
        System.out.println(
                "Longest palindromic Subsequence String:'" + ans + "' with length: " + dp[s1.length()][s2.length()]);
    }

    public static void main(String[] args) {
        String s1 = "abaaa";
        String s2 = "baabaca";
        // for (int i = s1.length() - 1; i >= 0; i--) {
        //     s2 += s1.charAt(i);
        // }

        findLen_String(s2, s1);
    }
}
