#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cin >> size;
    int roll[size];
    int time[size];
    for (int i = 0; i < size; i++)
    {
        cin >> roll[i];
        cin >> time[i];
    }
    int start = 0;
    int last = size - 1;
    int target;
    cin >> target;
    int count = 0;
    bool found=false;
    int mid;
    while (start <= last)
    {
        count++;
        mid = start + (last - start) / 2;
        if (target == roll[mid])
        {
            found=true;
            break;
        }
        else if (target > roll[mid])
        {
            start = mid + 1;
        }
        else if (target < roll[mid])
        {
            last = mid - 1;
        }
        
        else if(!found)
        {
            cout << "Not submitted";
        }
        
    }
    if(found)
    {
        cout << time[mid] << endl << count;
    }
    else
    {
        cout << "Not submitted";
    }
    return 0;
}