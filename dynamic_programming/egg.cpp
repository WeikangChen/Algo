// http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/
// A Dynamic Programming based C++ Program for the Egg Dropping Puzzle
# include <stdio.h>
# include <limits.h>
# include <iostream>
# include <vector>
using namespace std;

// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b)? a: b; }



/* Function to get minimum number of trails needed in worst
  case with n eggs and k floors */
int eggDrop(int n, int k)
{
    /* A 2D table where entery eggFloor[i][j] will represent minimum
       number of trials needed for i eggs and j floors. */
    // int eggFloor[n+1][k+1];
    vector<vector<int>> eggFloor(n + 1, vector<int>(k + 1));
    // We need one trial for one floor and0 trials for 0 floors
    /*
    for (i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }
    */

    // We always need j trials for one egg and j floors.
    for (int j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    // Fill rest of the entries in table using optimal substructure
    // property
    vector<int> parent(k+1, 0);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            eggFloor[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                int res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                if (res < eggFloor[i][j]) {
                    eggFloor[i][j] = res;
                    parent[j] = j - x;
                }
            }
            // cout << eggFloor[i][j] << " ";
        }
        // cout << endl;
    }

    int p = k;
    while(p) {
        cout << p << "->";
        p = parent[p];
    }
    cout << 0 << endl;

    // eggFloor[n][k] holds the result
    return eggFloor[n][k];
}

/* Driver program to test to pront printDups*/
int main()
{
    // int n = 3, k = 100;
    int n = 2, k = 36;
    //for (int k = 10; k <=100; k+=10)
    printf ("Minimum number of trials in worst case with %d eggs and "
            "%d floors is %d \n", n, k, eggDrop(n, k));
    return 0;
}
