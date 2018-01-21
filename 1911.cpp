#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> array(n);
	vector<int>	answer;
	for (int i = 0; i < n; i++)
		cin >> array[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (array[i] == array[j] + array[k] && array[j] != array[k])
					if (answer.size() == 0)
						answer.push_back(array[i]);
					else{
						for (int l = 0; l < answer.size();l++) {
							if (answer[l] == array[i])
								break;
							else if(l == answer.size()-1)
								answer.push_back(array[i]);
						}
					}
			}
		}
	}
	cout << answer.size();

	return 0;
}