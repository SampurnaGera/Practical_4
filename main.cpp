#include <iostream>
#include <cmath>
using namespace std;

double * read_poly(int &n){
  cout << "Enter degree of Polynomial: ";
  cin >> n;
  double * c=new double[n+1];

  for(int i=0;i<=n;i++){
    cout << "coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}


void print_poly(double *c, int n){
  int i;
  cout << c[0];
  if(n>0)
    cout << " + ";
  for(i=1;i<n;i++)
    cout << c[i] << "*x^" << i << " + ";
  if(i==n) //(n>0)
    cout << c[n] << "*x^" << i;
  cout << endl;
}


void cal_poly(double *c, int n)
{
  int x,i;
  double sum=0;

  cout <<"Enter value of x: ";
  cin >>x;
  
  for(i=0;i<=n+1;i++)
  { 
    sum=sum+c[i]*pow(x,i);
  }
cout<<"The value of the polynomial is: "<< sum<<endl;
}


void poli_sum (double * p1, int d1, double * p2, int d2)
{
  int i,j;
  if (d1<d2)
  {
    for(j=0;j<=d2+1;j++)
    {
      for(i=0;i<=d1+1;i++)
      {
        if (i==j)
        {
          p2[j]=p1[i]+p2[j];
        }

      }
    }

    cout<<"The sum of polynomial is: ";
    print_poly(p2,d2);
    cout<<endl;
  }
  else
  {
    for(i=0;i<=d1+1;i++)
    {
      for(j=0;j<=d2+1;j++)
      {
        if (i==j)
        {
          p1[j]=p1[i]+p2[j];
        }
      }
    }
     cout<<"The sum of polynomial is: ";
    print_poly(p1,d1);
    cout<<endl;
  }
}


void poli_product(double *p1, int d1, double *p2, int d2)
{
  int i,j;

  double * p3 = new double[d1+d2];
//Initialising p3 array to a 0 value
  for (i=0;i<=d1+d2;i++)
  {
    p3[i]=0;
  }

  for(j=0;j<=d2;j++)
  {
    for(i=0;i<=d1;i++)
    { 
      p3[i+j] = p3[i+j]+(p1[i]*p2[j]); 
    }
  }
  cout<<"The product of polynomial is: ";
    print_poly(p3,d1+d2);
    cout<<endl;
  
}



int main()
{
  //declaration
  double *p1,*p2;
  int g1,g2;

 // calling function
  p1=read_poly(g1);
  print_poly(p1,g1);


  
  //Solution 1
  cal_poly(p1,g1);

  //calling function to input 2nd polynomial
  p2=read_poly(g2);
  print_poly(p2,g2);

  //Solution 3
  poli_product(p1,g1,p2,g2);

  //Solution 2
 poli_sum(p1,g1,p2,g2);

  

 
 //deleting dynamic memory
  delete[] p1;
  delete[] p2;

  return 0;
}