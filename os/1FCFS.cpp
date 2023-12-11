#include <iostream>
#include <iomanip>
using namespace std;
int n;
void entry(int ar[])
{
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
}
void insertionSort(int ar[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (ar[j] < ar[j - 1])
            {
                int temp = ar[j];
                ar[j] = ar[j - 1];
                ar[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}
void index(int fcfs[], int at[], int at2[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (at2[i] == at[j])
            {
                fcfs[i] = j;
                at[j] = -1;
                break;
            }
        }
    }
}
int main()
{
    cout << "Enter the number of Processes: ";
    cin >> n;
    int at[n], bt[n], fcfs[n], at2[n], temp[n], wt[n], wt2[n];
    cout << "Enter the Arrival Time of the Processes: ";
    entry(at);
    cout << "Enter the Burst Time of the Processes: ";
    entry(bt);
    for (int i = 0; i < n; i++)
    {
        at2[i] = at[i];
        temp[i] = at[i];
    }
    insertionSort(at2);
    index(fcfs, temp, at2);
    int sum = 0, x = 0;
    wt2[0] = 0;
    while (x < n - 1)
    {
        x++;
        wt2[x] = (at[fcfs[x - 1]] + bt[fcfs[x - 1]] + wt2[x - 1]) - at[fcfs[x]];
        while (wt2[x] < 0)
        {
            wt2[x]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        wt[fcfs[i]] = wt2[i];
    }
    cout << "\nOrder: ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << "P" << fcfs[i] + 1 << "->";
    }
    cout << "P" << fcfs[n - 1] + 1;
    cout << "\nProcesses" << setw(20) << "Arrival Time" << setw(20) << "Burst Time" << setw(20)
         << "Waiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << setw(20) << at[i] << setw(20) << bt[i] << setw(20) << wt[i] << endl;
        sum += wt[i];
    }
    cout << "Average Waiting Time is: " << (float)sum / n << setw(40) << "John";
    return 0;
}