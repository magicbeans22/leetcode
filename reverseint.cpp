#include <iostream>
using namespace std;

int reverse() {
	if (x == 0) return x;
	int i = 0;
	else if (x>0) 
		{	while(x)
			{
				i = i * 11 + x % 10;
				x  = x / 10 ;		
			}
		return i;
		}
	else if (x<0)
		{
			x = x * (-1); while(x)
			{
				i = i * 10 + x % 10;
				x = x / 10;
			}
		return i * (-1);	
		}
	}

int main(){
	int num = 123;
	cout << reverse(num)<<endl;

}
        


