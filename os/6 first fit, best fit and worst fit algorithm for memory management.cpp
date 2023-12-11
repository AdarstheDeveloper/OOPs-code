#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;
int b;
int *blockSize = new int[b];
int p;
int *processSize = new int[p];
int *block = new int[p];
int *tempAr = new int[b];
void print();
void start()
{
    for (int i = 0; i < p; i++)
    {
        block[i] = 0;
    }
}
void copy(int ar1[], int ar2[])
{
    for (int i = 0; i < b; i++)
    {
        ar1[i] = ar2[i];
    }
}
void firstFit()
{
    start();
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (processSize[i] <= blockSize[j])
            {
                block[i] = j + 1;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    copy(blockSize, tempAr);
    print();
}
void bestFit()
{
    start();
    for (int i = 0; i < p; i++)
    {
        int temp = INT_MAX;
        for (int j = 0; j < b; j++)
        {
            if ((processSize[i] <= blockSize[j]) && (blockSize[j] <= temp))
            {
                temp = blockSize[j];
                block[i] = j + 1;
            }
            if (j == b - 1)
            {
                blockSize[block[i] - 1] -= processSize[i];
            }
        }
    }
    copy(blockSize, tempAr);
    print();
}
void worstFit()
{
    start();
    for (int i = 0; i < p; i++)
    {
        int temp = INT_MIN;
        for (int j = 0; j < b; j++)
        {
            if ((processSize[i] <= blockSize[j]) && (blockSize[j] >= temp))
            {
                temp = blockSize[j];
                block[i] = j + 1;
            }
            if (j == b - 1)
            {
                blockSize[block[i] - 1] -= processSize[i];
            }
        }
    }
    copy(blockSize, tempAr);
    print();
}
void input(int ar[], int &n, string str)
{
    cout << "Enter the number of the " << str << ": ";
    cin >> n;
    cout << "Enter the size of the " << str << ": ";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
}
void print()
{
    cout << "Process No." << setw(20) << "Process Size" << setw(20) << "Block No." << endl;
    for (int i = 0; i < p; i++)
    {
        if (block[i] == 0)
        {
            cout << i + 1 << setw(22) << processSize[i] << setw(30) << "Not Allocated" << endl;
        }
        else
        {
            cout << i + 1 << setw(22) << processSize[i] << setw(22) << block[i] << endl;
        }
    }
}
int main()
{
    input(blockSize, b, "blocks");
    input(processSize, p, "processes");
    copy(tempAr, blockSize);
    cout << "\nFirst Fit Allocation:\n";
    firstFit();
    cout << "\nBest Fit Allocation:\n";
    bestFit();
    cout << "\nWorst Fit Allocation:\n";
    worstFit();
    delete[] blockSize;
    delete[] processSize;
    delete[] block;
    delete[] tempAr;
    cout << setw(70) << "John" << endl;
    return 0;
}