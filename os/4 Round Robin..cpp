#include <iostream>
#include <iomanip>
using namespace std;
int n, tq;
void input(int ar[], string str)
{
    cout << "Enter the " << str << " of the Processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
}
void sort(int ar[], int value2)
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
void copy(int ar1[], int ar2[])
{
    for (int i = 0; i < n; i++)
    {
        ar1[i] = ar2[i];
    }
}
void index(int fcfs[], int at[], int at2[], int value, int index)
{
    int temp[n];
    copy(temp, at);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((at2[i] == temp[j]) && (value == 1) && (j == index))
            {
                continue;
            }
            else if (at2[i] == temp[j])
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
    int at[n], bt[n], at2[n], bt2[n], at3[n], at4[n], fcfs[n], rr[1000], wt[n], sum = 0, value = 0;
    input(at, "Arrival Time");
    input(bt, "Burst Time");
    cout << "Enter the Time quantum: ";
    cin >> tq;
    copy(at2, at);
    copy(at3, at);
    copy(at4, at);
    copy(bt2, bt);
    sort(at2, 0);
    sort(at4, 0);
    index(fcfs, at, at2, 0, 0);
    int total = at2[0];
    int temp = tq;
    for (int i = at2[0]; i <= total; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((at3[fcfs[j]] <= total) && (bt2[fcfs[j]] > 0) && (temp > 0) && (temp <= tq))
            {
                rr[i] = fcfs[j];
                bt2[fcfs[j]]--;
                temp--;
                total++;
                if (bt2[fcfs[j]] == 0)
                {
                    temp = 0;
                }
                if (temp == 0)
                {
                    temp = tq;
                    at3[fcfs[j]] = total + 1;
                    copy(at4, at3);
                    sort(at4, 1);
                    index(fcfs, at3, at4, 1, fcfs[j]);
                }
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        value = 0;
        for (int j = at2[0]; j < total; j++)
        {
            if (i == rr[j])
            {
                value++;
                wt[i] = j + 1 - value - at[rr[j]];
            }
        }
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
    }
    value = 1;
    cout << "\nOrder: ";
    for (int i = at2[0]; i < total - 1; i++)
    {
        if (rr[i + 1] == rr[i])
        {
            value++;
        }
        else
        {
            cout << "P" << rr[i] + 1 << "(" << value << ")->";
            value = 1;
        }
    }
    cout << "P" << rr[total - 1] + 1 << "(" << value << ")";
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