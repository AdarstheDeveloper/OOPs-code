import java.util.Scanner;

public class Program3 {
    static void swap(int ar[], int i, int j) {
        int temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }

    static int partition(int ar[], int low, int high) {
        int pivot = ar[low];
        int j = high;
        for (int k = high; k > low; k--) {
            if (ar[k] > pivot)
                swap(ar, k, j--);
        }
        swap(ar, low, j);
        return j;
    }

    static void merge(int ar[], int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = low;
        int ar2[] = new int[high + 1];
        while ((i <= mid) && (j <= high)) {
            if (ar[i] <= ar[j]) {
                ar2[k] = ar[i];
                i++;
                k++;
            } else {
                ar2[k] = ar[j];
                j++;
                k++;
            }
        }
        if (i > mid) {
            while (j <= high) {
                ar2[k] = ar[j];
                j++;
                k++;
            }
        } else {
            while (i <= mid) {
                ar2[k] = ar[i];
                i++;
                k++;
            }
        }
        for (k = low; k <= high; k++) {
            ar[k] = ar2[k];
        }
    }

    static void quickSort(int ar[], int low, int high) {
        if (low < high) {
            int loc = partition(ar, low, high);
            quickSort(ar, low, loc - 1);
            quickSort(ar, loc + 1, high);
        }
    }

    static void mergeSort(int ar[], int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(ar, low, mid);
            mergeSort(ar, mid + 1, high);
            merge(ar, low, mid, high);
        }
    }

    static void printArray(int ar[], int n, String str) {
        System.out.print("The Array " + str + " sorting is: ");
        for (int i = 0; i < n - 1; i++) {
            System.out.print(ar[i] + ",");
        }
        System.out.println(ar[n - 1]);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = s.nextInt();
        int ar[] = new int[n];
        System.out.print("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            ar[i] = s.nextInt();
        }
        System.out.println("Quick sort(1), Merge sort(2)");
        System.out.print("Enter your choice: ");
        int choice = s.nextInt();
        printArray(ar, n, "before");
        switch (choice) {
            case 1:
                quickSort(ar, 0, n - 1);
                break;
            case 2:
                mergeSort(ar, 0, n - 1);
                break;
        }
        printArray(ar, n, "after");
    }
}