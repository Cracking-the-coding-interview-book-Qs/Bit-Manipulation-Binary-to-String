/*
Q))
Given a real number between O and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. 
If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR:'

Approach:
Refer cracking the coding interview book for approach


This code gives actual number of bits added without converting the number into 32 bits like IEEE standard.
some successfull test cases are 0.5,0.75,0.625.

*/

#include<iostream>
#include<vector>

using namespace std;

void BinaryToString(double n)
{
	double r=0;
	//Declaration of Vectors as our output, I will print it in the last
	vector<char>output;
	
	//number lies between 0 and 1, so print fractional part in binary
	output.push_back('.');
	
	int count=0;
	while(n!=0)
	{
		//ek tarah se saari bits ko left me shift karre hai by one.
		r=2*n;
		
		//means bit just after the decimal was 1
		if(r>=1)
		{
			//vector me 1 daalo
			output.push_back('1');
			
			count++;
			
			//ab vo bit jo decimal ke left me hai usko hata do.(1 here)
			n=r-1;
		}
		else
		{
			//matlab jo bit just decimal ke baad me thi vo 0 thi.Add 0 in our vector
			output.push_back('0');
			
			count++;
			
			//ab vo bit jo decimal ke left me hai usko hata do.(0 here)
			n=r;	
		}	
	}
	cout<<"\nBits added => "<<count;
	//If size of the vector exceeds 32, print ERROR
	 if(output.size()>=33) //one input is '.' 
	 {
	 	cout<<"\nERROR";
	 }
	 else
	 {
	 	//print the output 
	 	cout<<"\n\nBinary form of the input => \n";
    	for(int i=0; i < output.size(); i++)
   			cout << output.at(i) << ' ';
	 }
	
	
}

int main()
{
	double n;
	
	cout<<"\nEnter the number n"<<" ";
	cin>>n;
	
	//checking for corner cases
	if(n>0)
	{
		//number should be between 0 and 1
		if(n<1)  //zero se bada already hai
		{
			//calling our function
			BinaryToString(n);
		}
		else
		{
			cout<<"\Number should be between 0 and 1 ";;
		}
	}
	else
	{
		cout<<"\nEnter positive number ONLY!!";
	}
return 0;	
}
