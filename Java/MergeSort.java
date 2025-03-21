import java.util.Arrays;
import java.util.Scanner;

public class MergeSort {
    public static void merge(int []arr,int left,int mid,int right){
        int merged[]=new int[right-left+1];
        int n1=left;
        int n2=mid+1;
        int x=0;
        while(n1<=mid && n2<=right){
            if(arr[n1]<arr[n2]){
                merged[x++]=arr[n1++];
            }else{
                merged[x++]=arr[n2++];
            }
        }
        while(n1<=mid){
            merged[x++]=arr[n1++];
        }
        while(n2<=right){
            merged[x++]=arr[n2++];
        }
        for(int i=0,j=left;i<merged.length;i++,j++){
            arr[j]=merged[i];
        }
    }
    public static void mergeSort(int[] arr,int left,int right) {
        if(left < right) {
            int mid=left+(right-left)/2;
            mergeSort(arr,left,mid);
            mergeSort(arr,mid+1,right);
            merge(arr,left,mid,right);
        }
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the size of array:");
        int size=s.nextInt();
        int arr[]=new int[size];
        System.out.println("Enter the elements:");
        for(int i=0;i<size;i++){
            arr[i]=s.nextInt();
         
        }

        mergeSort(arr,0,size-1);
        System.out.println("Sorted array:");
        for(int i=0;i<size;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
        s.close();



    }
}
