#include<iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);ios::sync_with_stdio(false);
	/* ====================================== */
	int N;
	cin >> N;
	vector<int> L(N);
	for(int i = 0; i < N; i++){
		cin >> L[i];
	}
	string s = "No";
	int max = 0;
	int sum = 0;
	for(int i = 0; i < N; i++){
		sum += L[i];
		if(L[i] > max) max = L[i];
	}
	if(sum - max > max) s = "Yes";


	cout << 0;
	/* ====================================== */
	return 0;
}