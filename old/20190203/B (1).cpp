#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdint.h>

using namespace std;

int main()
{
	cin.tie(0);ios::sync_with_stdio(false);
	/* ====================================== */
	int N, K;
	cin >> N >> K;
	vector<uint64_t> A(N);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}

	vector<uint64_t> BIT(100);
	for(int i = 0; i < 100; i++){
		BIT[i] = ((uint64_t)1 << i);
	}
	
	uint64_t res = 0;
	for(int i = 0; i < 100; i++){
		uint64_t bit = BIT[i];
		int count = 0;
		for(int j = 0; j < N; j++){
			if((A[j] & bit) == bit){
				count++;
			}
		}
		if(count < (double)N/2){
			res = res + bit;
			if(bit > K){
				res -= bit;
				break;
			}
		}
	}
	uint64_t ans = 0;
	for(int j = 0; j < N; j++){
		ans += (A[j] ^ res);
	}

	cout << ans;
	/* ====================================== */
	return 0;
}