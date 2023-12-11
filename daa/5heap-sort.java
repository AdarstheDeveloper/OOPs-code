import java.util.Scanner;

public class Program5 {
    static int n;

    public void sort(int arr[]) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    void heapify(int arr[], int N, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < N && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < N && arr[r] > arr[largest]) {
            largest = r;
        }
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            heapify(arr, N, largest);
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        n = s.nextInt();
        int arr[] = new int[n];
        System.out.print("Enter the array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }
        Program5 ob = new Program5();
        ob.sort(arr);
        System.out.print("Sorted array is: ");
        for (int e : arr) {
            System.out.print(e + " ");
        }
        System.out.println();
    }
}