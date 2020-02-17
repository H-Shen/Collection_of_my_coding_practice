#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
class Calculator {
    public:
        Calculator() {}
        long long power(int n, int p) {
            long long n_long(n);
            long long ret = 1;
            if (n_long < 0 || p < 0) {
                throw std::invalid_argument( "n and p should be non-negative" );
            } else {
                for (int i = 0; i < p; ++i) {
                    ret *= n_long;
                }
            }
            return ret;
        }
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}