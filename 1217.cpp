#include<iostream>
#include<cmath>
using namespace std;

char letter[100000];
void Output(int cap,int type) {
	int w = 0, l = 0;
	for (int i = 0; i < cap; i++) {
		if (letter[i] == 'W')
			w++;
		if (letter[i] == 'L')
			l++;
		if (((w == type||l==type)&&(abs(l-w)>=2))||((w>type||l>type)&&(abs(l-w)==2)) ){
			cout << w << ':' << l;
			w = 0, l = 0;
			cout << endl;
		}
	}
	cout << w << ':' << l;
}
int main() {
	int i = 0;
	while ((letter[i] = getchar()) != EOF) {
		if (letter[i] == 'E')
			break;
		i++;
	}
	Output(i, 11);
	cout << endl<<endl;
	Output(i, 21);

	return 0;
}