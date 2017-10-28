#include <cstdio>
#include <cstring>

constexpr int MAX_N = 20;
constexpr int MAX_M = 20;

int main(){
	int N, M;
	char field[MAX_N][MAX_M];

	int dp[2][1 << 20][2];

	scanf("%d %d\n", &M, &N);

	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			scanf("%c", field[j][i]);
		}
		scanf("\n");
	}

	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			memset(dp[nxt], 0, sizeof(dp[nxt]))
		}
	}

	return 0;
}
