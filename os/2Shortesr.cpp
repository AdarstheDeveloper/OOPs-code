// NOn-Preemptive SJF
#include <iostream>
#include <iomanip>
#include <limits>
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
void index(int fcfs[], int bt[], int bt2[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bt2[i] == bt[j])
            {
                fcfs[i] = j;
                bt[j] = -1;
                break;
            }
        }
    }
}
void copy(int ar1[], int ar2[])
{
    for (int i = 0; i < n; i++)
    {
        ar1[i] = ar2[i];
    }
}
int main()
{
    cout << "Enter the number of Processes: ";
    cin >> n;
    int at[n], bt[n], fcfs[n], at2[n], bt2[n], temp[n], wt[n], wt2[n], sjf[n], at3[n];
    cout << "Enter the Arrival Time of the Processes: ";
    entry(at);
    cout << "Enter the Burst Time of the Processes: ";
    entry(bt);
    copy(at3, at);
    copy(at2, at);
    copy(temp, bt);
    copy(bt2, bt);
    insertionSort(at2);
    insertionSort(bt2);
    index(fcfs, temp, bt2);
    int total = at2[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (at3[fcfs[j]] <= total)
            {
                sjf[i] = fcfs[j];
                at3[fcfs[j]] = numeric_limits<int>::max();
                total += bt[fcfs[j]];
                break;
            }
        }
    }
    int sum = 0, x = 0;
    wt2[0] = 0;
    while (x < n - 1)
    {
        x++;
        wt2[x] = (at[sjf[x - 1]] + bt[sjf[x - 1]] + wt2[x - 1]) - at[sjf[x]];
        while (wt2[x] < 0)
        {
            wt2[x]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        wt[sjf[i]] = wt2[i];
    }
    cout << "\nOrder: ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << "P" << sjf[i] + 1 << "->";
    }
    cout << "P" << sjf[n - 1] + 1;
    cout << "\nProcesses" << setw(20) << "Arrival Time" << setw(20) << "Burst Time" << setw(20)
         << "Waiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << setw(20) << at[i] << setw(20) << bt[i] << setw(20) << wt[i] << endl;
        sum += wt[i];
    }
    cout << "Average Waiting Time is: " << (float)sum / n << setw(40) << "John\n";
    return 0;
}
// Source Code (Preemptive):
#include <iostream>
#include <iomanip>
using namespace std;
int n;
int same[10], name[10];
void input(int ar[], string str)
{
    cout << "Enter the " << str << " of the Processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
}
void sort(int ar[], int at[])
{
    fill_n(name, 10, 0);
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
            else if ((ar[j] == ar[j - 1]) && (at[j] < at[j - 1]))
            {
                same[i] = j - 1;
                name[i]++;
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
void copy(int ar1[], int ar2[])
{
    for (int i = 0; i < n; i++)
    {
        ar1[i] = ar2[i];
    }
}
void index(int fcfs[], int bt[], int bt2[])
{
    int temp[n];
    copy(temp, bt);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == same[j]) && (name[i] > 0))
            {
                name[i]--;
                continue;
            }
            else if (bt2[i] == temp[j])
            {
                fcfs[i] = j;
                temp[j] = -1;
                break;
            }
        }
    }
}
int main()
{
    cout << "Enter the number of Processes: ";
    cin >> n;
    int at[n], bt[n], at2[n], bt2[n], bt3[n], fcfs[n], sjf[50], wt[n], value = 0, sum = 0;
    input(at, "Arrival Time");
    input(bt, "Burst Time");
    copy(at2, at);
    copy(bt2, bt);
    copy(bt3, bt);
    sort(at2, at);
    sort(bt2, at);
    index(fcfs, bt, bt2);
    int total = at2[0];
    for (int i = 0; i <= total; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((at[fcfs[j]] <= total) && (bt3[fcfs[j]] > 0))
            {
                sjf[i] = fcfs[j];
                bt3[fcfs[j]]--;
                total++;
                copy(bt2, bt3);
                sort(bt2, at);
                index(fcfs, bt3, bt2);
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        value = 0;
        for (int j = 0; j < total; j++)
        {
            if (i == sjf[j])
            {
                value++;
                wt[i] = j + 1 - value - at[sjf[j]];
            }
        }
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
    }
    value = 1;
    cout << "\nOrder: ";
    for (int i = 0; i < total - 1; i++)
    {
        if (sjf[i + 1] == sjf[i])
        {
            value++;
        }
        else
        {
            cout << "P" << sjf[i] + 1 << "(" << value << ")->";
            value = 1;
        }
    }
    cout << "P" << sjf[total - 1] + 1 << "(" << value << ")";
    cout << "\nProcesses" << setw(20) << "Arrival Time" << setw(20) << "Burst Time" << setw(20)
         << "Waiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << setw(20) << at[i] << setw(20) << bt[i] << setw(20) << wt[i] << endl;
        sum += wt[i];
    }
    cout << "Average Waiting Time is: " << (float)sum / n << setw(40) << "John\n";
    return 0;
}