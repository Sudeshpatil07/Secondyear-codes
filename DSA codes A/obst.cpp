#include<iostream>
#define max 20
using namespace std;
int n, k, i, j;
float p[max],q[max],w[max][max],c[max][max],r[max][max];
void OBST();
void print_tab();
void OBST()
{
for(int i=0; i<n; i++){
r[i][i] = 0;
c[i][i] = 0;
w[i][i] = q[i];
w[i][i+1] = p[i+1]+q[i+1]+w[i][i];
c[i][i+1] = w[i][i+1];
r[i][i+1] = i+1;
}
c[n][n] = 0.0;
r[n][n] = 0.0;
w[n][n] = q[n];
for(int i=2; i<=n; i++)
{
for(int j=0; j<=n-i; j++)
{
w[j][j+i] = p[j+i] + q[j+i] + w[j][j+i-1];
c[j][j+i] = 999;
for(int k=j+1; k<=j+i; k++)
{
if(c[j][j+i] > c[j][k-1] + c[k][j+i])
{
c[j][j+i] = c[j][k-1] + c[k][j+i];
r[j][j+i] = k;
}
}
c[j][j+i] += w[j][j+i];
}
}
}
void print_tab()
{
for(int i=0; i<=n; i++)
cout<<"w("<<i<<","<<i<<")="<<w[i][i]<<"\t";
cout<<endl;
for(int i=0; i<=n; i++)
cout<<"c("<<i<<","<<i<<")="<<c[i][i]<<"\t";
cout<<endl;
for(int i=0; i<=n; i++)
cout<<"r("<<i<<","<<i<<")="<<r[i][i]<<"\t";
cout<<endl;
int k = 1;
while(k <= n)
{
cout<<endl;
for(int i=0, j=i+k; i<n && j<=n; i++, j++)
cout<<"w("<<i<<","<<j<<")="<<w[i][j]<<"\t";
cout<<endl;
for(int i=0, j=i+k; i<n && j<=n; i++, j++)
cout<<"c("<<i<<","<<j<<")="<<c[i][j]<<"\t";
cout<<endl;
for(int i=0, j=i+k; i<n && j<=n; i++, j++)
cout<<"r("<<i<<","<<j<<")="<<r[i][j]<<"\t";
cout<<endl;
k++;
}
}
int main(){
cout<<"Enter the number of nodes : ";
cin>>n;
cout<<"\nEnter the successfull probabilities: ";
for(int i = 1; i<=n; i++){
cin>>p[i];
}
cout<<"\nEnter the unsuccessfull probabilities: ";
for(int i = 0; i<=n; i++){
cin>>q[i];
}
OBST();
print_tab();
return 0;
}