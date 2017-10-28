#include <iostream>

constexpr int MAX_NQ = 200000;

int N, Q, S, T;
long long diff[MAX_NQ + 1];
long long ans = 0;

long long get(long long t);

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> Q >> S >> T;

	long long prev = 0;
	for(int i = 0; i <= N; ++i){
		long long input;
		std::cin >> input;
		diff[i] = input - prev;
		ans += get(diff[i]);
		prev = input;
	}

	for(int i = 0; i < Q; ++i){
		long long l, r, x;
		std::cin >> l >> r >> x;
		++r;
		ans -= get(diff[l]);
		diff[l] += x;
		ans += get(diff[l]);
		if(r <= N){
			ans -= get(diff[r]);
			diff[r] -= x;
			ans += get(diff[r]);
		}
		std::cout << ans << std::endl;
	}

	return 0;
}

long long get(long long t){
	if(t > 0){
		return -t * S;
	}
	else{
		return -t * T;
	}
}
