#include <iostream>
#include <cstring>

constexpr int MAX_N = 20;
constexpr int MAX_M = 20;
constexpr int MOD = 100000;
constexpr char JOI[] = "JOI";

int N, M;
char field[MAX_M][MAX_N];
int dp[2][1 << MAX_N][2];//dp[current or next][直前N文字（前の一列）に"JO"があるか][直前の文字が"J"なのかどうか]

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> M >> N;

	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			std::cin >> field[i][j];
		}
	}

	dp[0][0][0] = 1;

	int crt = 0, nxt = 1;

	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			memset(dp[nxt], 0, sizeof(dp[nxt]));

			for(int bit = 0; bit < (1 << N); ++bit){
				for(int f = 0; f < 2; ++f){//直前の文字が'J'なのかどうか
					if(dp[crt][bit][f] > 0){//そもそも、存在しない場合は処理しない
						for(int k = 0; k < 3; ++k){//文字を三通り当てはめる、但し'?'の時は三通り全て当てはめる
							if(field[i][j] != '?' && field[i][j] != JOI[k]){
								continue;
							}//文字が今回調べるべきでないとき
							if(bit >> j & 1 && JOI[k] == 'I'){
								continue;
							}//「良い旗」ができてしまったとき

							int nbit = bit & ~(1 << j);//現在の位置のJOのbitを消去する
							int nf = JOI[k] == 'J';//次のfを求める

							if(JOI[k] == 'O' && f == 1){
								nbit |= 1 << (j - 1);
							}//JOができた時は次のビットにそれを適応する

							dp[nxt][nbit][nf] += dp[crt][bit][f];
							if(dp[nxt][nbit][nf] > MOD){
								dp[nxt][nbit][nf] -= MOD;
							}
						}
					}
				}
			}

			std::swap(crt, nxt);
		}
		for(int bit = 0; bit < (1 << N); ++bit){
			dp[crt][bit][0] += dp[crt][bit][1];
			if(dp[crt][bit][0] >= MOD){
				dp[crt][bit][0] -= MOD;
			}
 
			dp[crt][bit][1] = 0;
		}//行が変わるとき、前のますが'J'であることはなくなるので、それを処理する。
	}
	int ans = 1;
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			if(field[i][j] == '?'){
				ans = (ans * 3) % MOD;
			}
		}
	}

	for(int bit = 0; bit < 1 << N; ++bit){
		ans = (ans + MOD - dp[crt][bit][0]) % MOD;
	}

	std::cout << ans << std::endl;

	return 0;
}
