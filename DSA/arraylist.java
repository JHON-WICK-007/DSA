import java.util.ArrayList;
import java.util.Collections;

public class arraylist {
    public static void main(String[] args) {
        // Declare and create an ArrayList of integers
        ArrayList<Integer> list = new ArrayList<>();
        ArrayList<Integer> list1 = new ArrayList<>();

        // Add elements
        list.add(10);
        list.add(20);
        list.add(30);

        // Print all elements
        System.out.println("All elements of list : " + list);
        System.out.println();

        // Modify element at index 1
        list.set(1, 25);
        System.out.println("All elements after replacing the 20 with 25 : " + list);
        System.out.println();

        // Access elements
        int a = list.get(0);
        System.out.println("Accessing the first element of list : " + a);
        System.out.println();

        list.add(0, 0);
        System.out.println("Adding a 0 at the beginning of the list : " + list);
        System.out.println();

        // Remove an element
        list.remove(2); // removes element at index 2
        System.out.println("After removing the element at index 2 : " + list);
        System.out.println();

        // Size of list
        int b = list.size();
        System.out.println("Size of the list : " + b);
        System.out.println();

        // Check if list contains an element
        if (list.contains(25)) {
            System.out.println("25 is in the list.");
        }

        // Clear the list
        list.clear();
        System.out.println("Is list empty? " + list.isEmpty());
        System.out.println();

        // sorting of an array
        list1.add(3);
        list1.add(2);
        list1.add(4);
        list1.add(1);
        System.out.println("New List1 before sorting: " + list1);
        Collections.sort(list1);
        System.out.println("New List1 after sorting : " + list1);
    }
}
