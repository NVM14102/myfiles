package SortingAlgorithms;

public class Bubblesorting {
  static void printArray(int arr[]) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
  }

  public static void main(String[] args) {
    int arr[] = { 7, 8, 3, 1, 2 };
    // swapiping
    for (int i = 0; i < arr.length - 1; i++) {

      for (int j = i+1; j < arr.length - i - 1; j++) {
        // swap
       
        if (arr[j] >= arr[j + 1]) {
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }

    printArray(arr);

  }

}
