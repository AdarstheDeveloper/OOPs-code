import java.util.Scanner;

public class Program9a {
    static int MatrixChainOrder(int p[], int i, int j) {
        if (i == j)
            return 0;
        int min = Integer.MAX_VALUE;
        for (int k = i; k < j; k++) {
            int count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
            if (count < min)
                min = count;
        }
        return min;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of matrices: ");
        int N = s.nextInt();
        int arr[] = new int[N + 1];
        System.out.print("Enter the order of matrices: ");
        for (int i = 0; i <= N; i++) {
            arr[i] = s.nextInt();
        }
        System.out.print("The Order of the matrices are ");
        for (int i = 0; i < N - 1; i++) {
            System.out.print(arr[i] + "x" + arr[i + 1] + ", ");
        }
        System.out.println(arr[N - 1] + "x" + arr[N]);
        System.out.println("Minimum number of multiplications are: " + MatrixChainOrder(arr, 1, N));
    }
}
// Source Code (Longest Common Subsequence):

public class Program9b {
static void lcs(String S1, String S2, int m, int n) {
int[][] LCS_table = new int[m + 1][n + 1];
for (int i = 0; i <= m; i++) {
for (int j = 0; j <= n; j++) {
if (i == 0 || j == 0)
LCS_table[i][j] = 0;
else if (S1.charAt(i - 1) == S2.charAt(j - 1))
LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
else
LCS_table[i][j] = Math.max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
}
}
int index = LCS_table[m][n];
int temp = index;
char[] lcs = new char[index + 1];
lcs[index] = '\0';
int i = m, j = n;
while (i > 0 && j > 0) {
if (S1.charAt(i - 1) == S2.charAt(j - 1)) {
lcs[index - 1] = S1.charAt(i - 1);
i--;
j--;
index--;
}
else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
i--;
else
j--;
}
System.out.print("First String: " + S1 + "\nSecond String: " + S2 + "\nLongest Common
Subsequence: ");
for (int k = 0; k <= temp; k++)
System.out.print(lcs[k]);
System.out.println();
}

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter two Strings: ");
        String S1 = s.next();
        String S2 = s.next();
        int m = S1.length();
        int n = S2.length();
        lcs(S1, S2, m, n);
    }
}