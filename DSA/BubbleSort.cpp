#include <iostream>
using namespace std;

int main()
{
    cout << "bubble sort" << endl;
    int arr1[] = {7, 8, 3, 1, 2};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                swap(arr1[j], arr1[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << endl;
    return 0;
}

#include <iostream>
using namespace std;

struct Student
{
    int roll_no;
    int submission_time;
};

int bubbleSort(Student arr[], int n)
{
    int swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].submission_time > arr[j + 1].submission_time)
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    return swaps;
}

int selectionSort(Student arr[], int n)
{
    int swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].submission_time < arr[minIdx].submission_time)
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }
    return swaps;
}

int main()
{
    int n;
    cin >> n;

    Student students[50];
    for (int i = 0; i < n; i++)
    {
        cin >> students[i].roll_no >> students[i].submission_time;
    }

    int choice;
    cin >> choice;

    int swaps = 0;

    if (choice == 1)
    {

        swaps = bubbleSort(students, n);
    }
    else if (choice == 2)
    {

        swaps = selectionSort(students, n);
    }
    else
    {
        cout << "Invalid choice" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << students[i].roll_no << " " << students[i].submission_time << endl;
    }

    cout << swaps << endl;

    cout << students[0].roll_no << "," << students[1].roll_no << endl;

    return 0;
}
