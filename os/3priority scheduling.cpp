// Source Code (Non-Preemptive):
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;
int n;
int same[10], value[10] = {};
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
                value[i]++;
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
void index(int fcfs[], int p[], int p2[])
{
    int temp[n];
    copy(temp, p);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == same[j]) && (value[i] > 0))
            {
                value[i]--;
                continue;
            }
            else if (p2[i] == temp[j])
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
    int at[n], bt[n], p[n], at2[n], p2[n], fcfs[n], ps[n], wt[n], sum = 0;
    input(at, "Arrival Time");
    input(bt, "Burst Time");
    input(p, "Priority");
    copy(at2, at);
    copy(p2, p);
    sort(at2, at);
    sort(p2, at);
    index(fcfs, p, p2);
    int total = at2[0];
    copy(at2, at);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (at2[fcfs[j]] <= total)
            {
                ps[i] = fcfs[j];
                at2[fcfs[j]] = numeric_limits<int>::max();
                wt[fcfs[j]] = total - at[fcfs[j]];
                total += bt[fcfs[j]];
                break;
            }
        }
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
    }
    cout << "\nOrder: ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << "P" << ps[i] + 1 << "->";
    }
    cout << "P" << ps[n - 1] + 1;
    cout << "\nProcesses" << setw(20) << "Arrival Time" << setw(20) << "Burst Time" << setw(18)
         << "Priority" << setw(22) << "Waiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << setw(20) << at[i] << setw(20) << bt[i] << setw(20) << p[i] << setw(20)
             << wt[i] << endl;
        sum += wt[i];
    }
    cout << "Average Waiting Time is: " << (float)sum / n << setw(60) << "John\n";
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
void index(int fcfs[], int p[], int p2[])
{
    int temp[n];
    copy(temp, p);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == same[j]) && (name[i] > 0))
            {
                name[i]--;
                continue;
            }
            else if (p2[i] == temp[j])
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
    int at[n], bt[n], p[n], at2[n], p2[n], bt2[n], wt[n], fcfs[n], ps[50], value = 0, sum = 0;
    input(at, "Arrival Time");
    input(bt, "Burst Time");
    input(p, "Priority");
    copy(at2, at);
    copy(p2, p);
    copy(bt2, bt);
    sort(at2, at);
    sort(p2, wt);
    index(fcfs, p, p2);
    int total = at2[0];
    for (int i = 0; i <= total; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((at[fcfs[j]] <= total) && (bt2[fcfs[j]] > 0))
            {
                ps[i] = fcfs[j];
                bt2[fcfs[j]]--;
                total++;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        value = 0;
        for (int j = 0; j < total; j++)
        {
            if (i == ps[j])
            {
                value++;
                wt[i] = j + 1 - value - at[ps[j]];
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
        if (ps[i + 1] == ps[i])
        {
            value++;
        }
        else
        {
            cout << "P" << ps[i] + 1 << "(" << value << ")->";
            value = 1;
        }
    }
    cout << "P" << ps[total - 1] + 1 << "(" << value << ")";
    cout << "\nProcesses" << setw(15) << "Arrival Time" << setw(15) << "Burst Time" << setw(12)
         << "Priority" << setw(18) << "Waiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << setw(15) << at[i] << setw(15) << bt[i] << setw(15) << p[i] << setw(15)
             << wt[i] << endl;
        sum += wt[i];
    }
    cout << "Average Waiting Time is: " << (float)sum / n << setw(40) << "John\n";
    return 0;
}