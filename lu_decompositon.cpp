#include <iostream>
using namespace std; 
    
void decomposition(int A[3][3], int n) 
{ 
    int l[n][n], u[n][n]; 
    
    for (int i = 0; i < n; i++) { 
   
        for (int k = i; k < n; k++) { 
  
            int sum = 0; 
            for (int j = 0; j < i; j++) 
                sum += (l[i][j] * u[j][k]); 
  
            u[i][k] = A[i][k] - sum; 
        } 
   
        for (int k = i; k < n; k++) { 
            if (i == k) 
                l[i][i] = 1;  
            else { 
  
                int sum = 0; 
                for (int j = 0; j < i; j++) 
                    sum += (l[k][j] * u[j][i]); 
                l[k][i] = (A[k][i] - sum) / u[i][i]; 
            } 
        } 
    } 
  
    cout <<  "Lower Triangle" << endl; 
   
    for (int i = 0; i < n; i++) { 
        
        for (int j = 0; j < n; j++) 
        {if(j>i)
            cout<<"0 ";
            else
            cout << l[i][j] << " "; } 
        cout << "\n"; 
        }
        
        cout <<  "Upper Triangle" << endl;
   for (int i = 0; i < n; i++) { 
          
        for (int j = 0; j < n; j++) 
        {if(j<i)
            cout<<"0 ";
            else
            cout << u[i][j] << " ";} 
        cout << endl; 
    } 
} 
 
int main() 
{ 
   int i, j, f, n;
int A[10][10], factor, C[10], x = 0;
int B[3][3] = { {1,2,4},{3,8,14},{2,6,13} };
cout << "Enter number of linear equation " << endl;
cin >> n;
cout << "Enter the elements of matrix:" << endl;
for (i = 1; i <= n; i++)
{
for (j = 1; j <= (n + 1); j++)
{

cin >> A[i][j];

}
}
  for (j = 1; j <= n; j++)  
{
for (i = 1; i <= n; i++)
{
if (i > j)
{
factor = A[i][j] / A[j][j];
for (f = 1; f <= n + 1; f++)
{
A[i][f] = A[i][f] - factor * A[j][f];
}
}
}
}
C[n] = A[n][n + 1] / A[n][n];

for (i = n - 1; i >= 1; i--)
{
x = 0;
for (j = i + 1; j <= n; j++)
{
x = x + A[i][j] * C[j];
}
C[i] = (A[i][n + 1] - x) / A[i][i];
}
cout << endl;
cout << "The solution is : " << endl;
for (i = 1; i <= n; i++)
{

cout << "X" << i << "=" << C[i] << endl;
}
    decomposition(B, 3); 
    return 0; 
}
