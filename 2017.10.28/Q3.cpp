#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int N;
	std::vector<int> taro, hanako;

	std::cin >> N;

	for(int i = 0; i < N; ++i){
		int input;
		std::cin >> input;
		taro.push_back(input);
	}

	for(int i = 1; i <= N * 2; ++i){
		if(std::find(taro.begin(), taro.end(), i) == taro.end()){
			hanako.push_back(i);
		}
	}

	std::sort(taro.begin(), taro.end());
	std::sort(hanako.begin(), hanako.end());

	bool is_taros_turn = true;
	while(!taro.empty() && !hanako.empty()){
		int card = 0;

		while(true){
			if(is_taros_turn){
				is_taros_turn = false;
				auto itr = taro.begin();
				bool flag = true;
				for(; itr != taro.end(); ++itr){
					if(*itr > card){
						flag = false;
						break;
					}
				}
				
				if(flag){
					break;
				}
				
				card = *itr;
				taro.erase(itr);
				if(taro.empty()){
					break;
				}
			}
			else{
				is_taros_turn = true;
				auto itr = hanako.begin();
				bool flag = true;
				for(; itr != hanako.end(); ++itr){
					if(*itr > card){
						flag = false;
						break;
					}
				}
				
				if(flag){
					break;
				}

				card = *itr;
				hanako.erase(itr);
				if(hanako.empty()){
					break;
				}
			}
		}
	}

	std::cout << hanako.size() << std::endl << taro.size() << std::endl;

	return 0;
}
