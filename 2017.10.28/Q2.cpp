#include <iostream>

constexpr int MAX_N = 300;
constexpr int MAX_M = 100;

int main(){
	int N, M;

	int friends[MAX_N], tgts[MAX_M];

	std::cin >> N >> M;

	for(int i = 0; i < N; ++i){
		friends[i] = 0;
	}

	for(int i = 0; i < M; ++i){
		int input;
		std::cin >> input;
		--input;

		tgts[i] = input;
	}

	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			int input;
			std::cin >> input;
			--input;

			if(input == tgts[i]){
				++friends[j];
			}
			else{
				++friends[tgts[i]];
			}
		}
	}

	for(int i = 0; i < N; ++i){
		std::cout << friends[i] << std::endl;		
	}

	return 0;
}
