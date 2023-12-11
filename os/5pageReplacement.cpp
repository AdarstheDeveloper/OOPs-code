// Source Code (LRU):
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    int m, n, position, k, l, f, p;
    int a = 0, b = 0, pageFaults = 0;
    cout << "Enter the number of page references: ";
    cin >> p;
    int pages[p];
    cout << "Enter the page references: ";
    for (int i = 0; i < p; i++)
    {
        cin >> pages[i];
    }
    cout << "Enter the number of frames: ";
    cin >> f;
    int frames[f], temp[f];
    string lru[f][p];
    for (m = 0; m < f; m++)
    {
        frames[m] = -1;
    }
    for (n = 0; n < p; n++)
    {
        a = 0, b = 0;
        for (m = 0; m < f; m++)
        {
            if (frames[m] == pages[n])
            {
                a = 1, b = 1;
                break;
            }
        }
        if (a == 0)
        {
            for (m = 0; m < f; m++)
            {
                if (frames[m] == -1)
                {
                    frames[m] = pages[n];
                    b = 1;
                    pageFaults++;
                    break;
                }
            }
        }
        if (b == 0)
        {
            for (m = 0; m < f; m++)
            {
                temp[m] = 0;
            }
            for (k = n - 1, l = 1; l <= f - 1; l++, k--)
            {
                for (m = 0; m < f; m++)
                {
                    if (frames[m] == pages[k])
                    {
                        temp[m] = 1;
                    }
                }
            }
            for (m = 0; m < f; m++)
            {
                if (temp[m] == 0)
                {
                    position = m;
                }
            }
            frames[position] = pages[n];
            pageFaults++;
        }
        for (m = 0; m < f; m++)
        {
            if ((a == 1 && b == 1) || (frames[m] == -1))
            {
                lru[m][n] = "_";
            }
            else
            {
                lru[m][n] = to_string(frames[m]);
            }
        }
    }
    for (m = 0; m < p; m++)
    {
        cout << pages[m] << setw(3);
    }
    cout << endl;
    for (m = 0; m < p; m++)
    {
        cout << "↓"
             << " ";
    }
    cout << "\n\n";
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << lru[i][j] << setw(3);
        }
        cout << setw(0) << endl;
    }
    cout << "\nTotal number of page faults are: " << pageFaults << setw(30) << "John" << endl;
    return 0;
}
// Source Code (FIFO):
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    int f, p, m, n, s, pageFaults = 0;
    cout << "Enter the number of page references: ";
    cin >> p;
    int pages[p];
    cout << "Enter the page references: ";
    for (int i = 0; i < p; i++)
    {
        cin >> pages[i];
    }
    cout << "Enter the number of frames: ";
    cin >> f;
    int frames[f];
    string fifo[f][p];
    for (m = 0; m < f; m++)
    {
        frames[m] = -1;
    }
    for (m = 0; m < p; m++)
    {
        s = 0;
        for (n = 0; n < f; n++)
        {
            if (pages[m] == frames[n])
            {
                s = 1;
                pageFaults--;
            }
        }
        pageFaults++;
        if ((pageFaults <= f) && (s == 0))
        {
            int i = 0;
            while (frames[i] != -1)
            {
                i++;
            }
            frames[i] = pages[m];
        }
        else if (s == 0)
        {
            frames[(pageFaults - 1) % f] = pages[m];
        }
        for (n = 0; n < f; n++)
        {
            if ((frames[n] == -1) || (s == 1))
            {
                fifo[n][m] = "_";
            }
            else
            {
                fifo[n][m] = to_string(frames[n]);
            }
        }
    }
    for (m = 0; m < p; m++)
    {
        cout << pages[m] << setw(3);
    }
    cout << endl;
    for (m = 0; m < p; m++)
    {
        cout << "↓"
             << " ";
    }
    cout << "\n\n";
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << fifo[i][j] << setw(3);
        }
        cout << setw(0) << endl;
    }
    cout << "\nTotal number of page faults are: " << pageFaults << setw(30) << "John" << endl;
    return 0;
}
// Source Code (Optimal):
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    int flag1, flag2, flag3, i, j, k, p, f, position, max, pageFaults = 0;
    cout << "Enter the number of page references: ";
    cin >> p;
    int pages[p];
    cout << "Enter the page references: ";
    for (int i = 0; i < p; i++)
    {
        cin >> pages[i];
    }
    cout << "Enter the number of frames: ";
    cin >> f;
    int frames[f], temp[f];
    string opt[f][p];
    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
    }
    for (i = 0; i < p; i++)
    {
        flag1 = flag2 = 0;
        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                flag1 = 1, flag2 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pageFaults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            flag3 = 0;
            for (j = 0; j < f; j++)
            {
                temp[j] = -1;
                for (k = i + 1; k < p; k++)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }
            for (j = 0; j < f; j++)
            {
                if (temp[j] == -1)
                {
                    position = j;
                    flag3 = 1;
                    break;
                }
            }
            if (flag3 == 0)
            {
                max = temp[0];
                position = 0;
                for (j = 1; j < f; j++)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        position = j;
                    }
                }
            }
            frames[position] = pages[i];
            pageFaults++;
        }
        for (j = 0; j < f; j++)
        {
            if ((flag2 == 1 && flag1 == 1) || (frames[j] == -1))
            {
                opt[j][i] = "_";
            }
            else
            {
                opt[j][i] = to_string(frames[j]);
            }
        }
    }
    for (i = 0; i < p; i++)
    {
        cout << pages[i] << setw(3);
    }
    cout << endl;
    for (i = 0; i < p; i++)
    {
        cout << "↓"
             << " ";
    }
    cout << "\n\n";
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << opt[i][j] << setw(3);
        }
        cout << setw(0) << endl;
    }
    cout << "\nTotal number of page faults are: " << pageFaults << setw(30) << "John" << endl;
    return 0;
}