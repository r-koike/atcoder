#include<iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);ios::sync_with_stdio(false);
	/* ====================================== */
	int N, K;
	cin >> N >> K;
	string n = "NO";
	string y = "YES";

	if((N+1)/2 >= K){
	cout << y;

	}else{
	cout << n;

	}

	/* ====================================== */
	return 0;
}