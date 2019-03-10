// C++ program for weighted job scheduling using Dynamic Programming. 
#include <iostream> 
#include <algorithm> 
#include <fstream>
#include <sstream>
using namespace std; 
  
// A job has start time, finish time and profit. 
struct Job
{ 
    int id, start, finish, profit; 
}; 
  
// A utility function that is used for sorting events 
// according to finish time 
bool jobComparataor(Job s1, Job s2) 
{ 
    return (s1.finish < s2.finish); 
} 
  
// Find the latest job (in sorted array) that doesn't 
// conflict with the job[i] 
int latestNonConflict(Job arr1[], int i) 
{ 
    for (int j=i-1; j>=0; j--) 
    { 
        if (arr1[j].finish <= arr1[i].start) 
            return j; 
    } 
    return -1; 
} 
  
// The main function that returns the maximum possible 
// profit from given array of jobs 
int findMaxProfit(Job arr1[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr1, arr1+n, jobComparataor); 
  
    // Create an array to store solutions of subproblems.  table[i] 
    // stores the profit for jobs till arr[i] (including arr[i]) 
    int *table = new int[n]; 
    table[0] = arr1[0].profit; 
  
    // Fill entries in M[] using recursive property 
    for (int i=1; i<n; i++) 
    { 
        // Find profit including the current job 
        int inclProf = arr1[i].profit; 
        int l = latestNonConflict(arr1, i); 
        if (l != -1) 
            inclProf += table[l]; 
  
        // Store maximum of including and excluding 
        table[i] = max(inclProf, table[i-1]); 
    } 
  
    // Store result and free dynamic memory allocated for table[] 
    int result = table[n-1]; 
    delete[] table; 
  
    return result; 
} 
  
// Driver program 
int main() 
{ 

    int arr1[8][8];
  
    string line;
    ifstream myfile ("input2.txt");

    string ai;
    if(myfile.is_open())
    {
        getline(myfile, ai);
        bool separator = false;
        string activity; string interval;
        int act,inter;
        for (int x = 0; x <  ai.size(); x++)
        {
            if (ai[x] == ' ')
            {
              separator = true;
              x++;
            }
            if (separator == true)
            {
                activity += ai[x];
            }
            else
            {
                interval += ai[x];
            }
            stringstream convert1(activity);
            stringstream convert2(interval);
             convert1 >> inter;
             convert2 >> act;
          }
           cout << "ACTIVITY: " << act << endl;
           cout <<  "INTERVAL: " << inter << endl;

                for(int i = 0; i <= 6; i++)
                    {
                        myfile >> arr1[0][i];
                        myfile >> arr1[1][i];
                        myfile >> arr1[2][i];
                        myfile >> arr1[3][i];
                    }

               for(int i = 0; i <=5; i++)
               {
                for(int j = 0; j <=5; j++)
                {
                    cout << arr1[i][j]<< ' ';
                }
                cout << endl;
               }         

        Job arr1[8];
        
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout << "The optimal profit is " << findMaxProfit(arr1, n)<< endl;
        myfile.close();
    }

    else
    {
      cout << "Error opening file." << endl;
    }
   
    return 0; 
} 
