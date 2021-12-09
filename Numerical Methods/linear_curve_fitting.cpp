#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int i,j,k,n;
    cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays
    cin>>n;
    double x[n],y[n],a,b;

    cout<<"\nEnter the x-axis values:\n";                //Input x-values
    for (i=0;i<n;i++){
        cout << "Enter the data for x: " ;
        cin>>x[i];
    }

    cout<<"\nEnter the y-axis values:\n";                //Input y-values
    for (i=0;i<n;i++){
        cout << "Enter the corresponding y values";
        cin>>y[i];
    }

    double xsum=0,x2sum=0,ysum=0,xysum=0;                //variables for sums/sigma of xi,yi,xi^2,xiyi etc
    for (i=0;i<n;i++){
        xsum=xsum+x[i];                        //calculate sigma(x)
        ysum=ysum+y[i];                        //calculate sigma(y)
        x2sum=x2sum+pow(x[i],2);                //calculate sigma(x^2)
        xysum=xysum+x[i]*y[i];                    //calculate sigma(xy)
    }

    a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);   //calculate slope
    b=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);  //calculate intercept
    
    double y_fit[n];                        //an array to store the new fitted values of y    
    for (i=0;i<n;i++)
        y_fit[i]=a*x[i]+b;                    //to calculate y(fitted) at given x points 
    cout<<"\nThe linear fit line is of the form:\n\n"<<a<<"x + "<<b<<endl;        //print the best fit line
    return 0;
} 