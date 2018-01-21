#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
	string isbn;
	int i,j=1,temp = 0;
	cin>>isbn;
	for(i = 0;i<11;i++){
		if(isbn[i]!= '-'){
			temp += (isbn[i] - '0')*j++;
		}
	} 
	temp %= 11;
	if(temp == 10)
		temp = 'X';
	if(temp == (isbn[12] - '0')||(temp == isbn[12]))
		cout<<"Right";
	else{
		if(temp != 'X')
			isbn[12] = (char)(temp+'0');
		else
			isbn[12] = temp;
		cout<<isbn;
	}
	
	return 0;
}
