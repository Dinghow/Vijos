#include<iostream>
#include<string>
using namespace std;

string type1(string line,int n) {
	char temp;
	for (int i = 0; i<n/2; i++) {
		temp = line[i];
		line[i] = line[n - i-1];
		line[n - i - 1] = temp;
	}

	return line;
}

string type2(string line, int k,int n) {
	for (int i = 0; i<n; i++) {
		if ((int)line[i] + k>'z')
			line[i] = line[i] - 26 + k;
		else
			line[i] += k;
	}

	return line;
}

string type3(string line, int k,int n) {
	for (int i = 0; i<n; i++) {
		if ((int)line[i] - k<'a')
			line[i] = line[i] + 26 - k;
		else
			line[i] -= k;
	}

	return line;
}

int main() {
	int n = 0;
	string ch[3], output, o_type1, o_type2, o_type3;

	cin >> n;
	for (int i = 0; i<3; i++) {
		cin>>ch[i];

	}
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++) {
			if (j == i)
				continue;
			for (int k = 0; k<3; k++) {
				if (k == i || k == j)
					continue;
				else {
					o_type1 = type1(ch[i],n);
					for (int m = 0; m<=6; m++) {
						o_type2 = type2(ch[j], m,n);
						o_type3 = type3(ch[k], m,n);
						if ((o_type1 == o_type2) && (o_type1 == o_type3))
							output = o_type1;
					}
				}
			}
		}
	cout << output;

	return 0;
}
