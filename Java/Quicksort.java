import java.util.Scanner;

public class Quicksort {
   public static int partition(int[] arr, int left, int right) {
        int pivot = arr[right];
        int i=left-1;
        for (int j=left; j<right; j++) {
            if(arr[j]<pivot) {
                i++;
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        i++;
        int temp=arr[i];
        arr[i]=pivot;
        arr[right]=temp;
        return i;
    }
    public static void quickSort(int[] arr, int left, int right) {
        if (left < right) {
            int p= partition(arr,left,right);
            quickSort(arr,left,p-1);
            quickSort(arr,p+1,right);

        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int size=sc.nextInt();
        int[] arr=new int[size];
        System.out.println("Enter the elements:");
        for(int i=0;i<size;i++) {
            arr[i]=sc.nextInt();
        }
        quickSort(arr,0,size-1);
        System.out.println("Sorted array:");
        for(int i=0;i<size;i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
        sc.close();
    }

}
