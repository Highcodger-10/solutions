#include<iostream>
#include<cmath>
#define    f(x)    x*sin(x)*cos(x) + log(x)
using namespace std;
int main(){
	float x0, x1, x2, f0, f1, f2, e;
	int k = 1, N; 
	cout<<"Enter first guess: ";
	cin>>x0;
	cout<<"Enter second guess: ";
	cin>>x1;
	cout<<"Enter tolerable error: ";
	cin>>e;
	cout<<"Enter maximum iteration: ";
	cin>>N;
	do{
		f0 = f(x0);
		f1 = f(x1);
		if(f0 == f1){
			cout<<"Mathematical Error.";
			exit(0);
		  }
		x2 = x1 - (x1 - x0) * f1/(f1-f0);
		f2 = f(x2);
		x0 = x1;
		f0 = f1;
		x1 = x2;
		f1 = f2;
		k++;
		if(k > N){
			cout<<"Not Convergent.";
			exit(0);
		}
	}while(fabs(f2)>e);
	cout<< endl<<"Root is: "<< x2;
	return 0;
}
