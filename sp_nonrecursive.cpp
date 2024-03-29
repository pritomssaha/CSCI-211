#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int rows = 5, cols = 6;
string path[rows][cols];

int calculateCost(int i, int j) { 
   static int weight[rows][cols] = {{3,4,1,2,8,6},
                                    {6,1,8,2,7,4},
                                    {5,9,3,9,9,5},
                                    {8,4,1,3,2,6},
                                    {3,7,2,8,6,4}};

   static int cost[rows][cols] = {};
   if (cost[i][j] != 0)    // If the cost has already been calculated, return it.
      return cost[i][j];    

   if (j == 0) {           // Base case (leftmost column)
      path[i][j] = to_string(i);
      return weight[i][j];
   }      

   int up = calculateCost((i+rows-1)%rows, j-1);   
   int left = calculateCost(i, j-1);
   int down = calculateCost((i+1)%rows, j-1);

   int minCost = min(min(up, left), down);   

   if (minCost == up)                   
      path[i][j] = path[(i+rows-1)%rows][j-1] + to_string(i);
   else if (minCost == left)
      path[i][j] = path[i][j-1] + to_string(i);
   else
      path[i][j] = path[(i+1)%rows][j-1] + to_string(i);
   cost[i][j] = minCost + weight[i][j];    
   return cost[i][j];                    
}



int main() {

   int minRow = 0;
   for (int i = 1; i < rows; ++i)
      if (calculateCost(i, cols-1) < calculateCost(minRow, cols-1))
         minRow = i;
   cout << "The length of the shortest path is " << calculateCost(minRow, cols-1);
   cout << ".\nThe rows of the path from left to right are " << path[minRow][cols-1] << ".";
   return 0;

}