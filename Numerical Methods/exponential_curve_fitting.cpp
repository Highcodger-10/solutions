//for ae^(bx)
#include<iostream>
#include<cstdio>
#include<cmath>
#define e 2.71828
using namespace std;
int main(){
  int n;
  cout << "Enter the total number of input data set: " ;
  cin >> n;
  float y[n] , Y[n],x[n];
  int xsum = 0;
  float Ysum = 0, xYsum = 0, x2sum = 0, A = 0, b = 0;

  cout << "For the data entry of x: "<< endl;
  for (int i = 0; i < n; i++){
    cout << "Enter the data for x: " ;
    cin >> x[i];
  }

  cout << "For the data entry of y: "<< endl;
  for (int j = 0; j < n; j++){
    cout << "Enter the data for y: ";
    cin >> y[j];
  }

  for (int k = 0; k < n; k++)
    Y[k] = log(y[k]);


  for (int i = 0; i < n ; i++){
    xsum += x[i];               //calculation of sigma(x)
    x2sum += x[i] * x[i];   //calculation of sigma(x^2)
    Ysum += Y[i];             //calculation of sigma(Y)
    xYsum += x[i] * Y[i]; //calculation of sigma(xY)
  }

  A = (Ysum*x2sum - xsum*xYsum)/(n*x2sum - pow(xsum,2));
  b = (n*xYsum - xsum*Ysum)/(n*x2sum - pow(xsum,2));
  float a = pow(e,A);
  cout << "The resulting expression would be " << fabs(a) << "e^(" << fabs(b) << "x)" << endl;
  return 0;
}