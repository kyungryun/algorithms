#define N 4
typedef struct {
	int strike;
    int ball;
}Result;
// API

extern Result query(int guess[]);

int arr[6000];
int s[10000];
bool flag = false;
int cnt = 0;
void perm(){
	if(!flag){
		flag = true;
		for(int i=0 ; i<10 ; i++){
			for(int j=0 ; j<10 ; j++){
				if(i == j) continue;
				for(int k=0 ; k<10 ; k++){
					if(k == i || k == j) continue;
					for(int l=0 ; l<10 ; l++){
						if(l == i || l == j || l == k) continue;
						arr[cnt++] = i*1000 + j*100 + k*10 + l;
					}
				}
			}
		}
	}
	for(int i=0 ; i<cnt ; i++) s[arr[i]] = 0;
}
Result cmp(int number, int now){
	int num[10] = {0};
	Result res = {0, 0};
	for(int i=0 ; i<4 ; i++){
		num[now %10]++;
		num[number %10]++;
		if(now % 10 == number % 10) res.strike++;
		now /= 10;
		number /= 10;
	}
	for(int i=0 ; i<10 ; i++){
		if(num[i] == 2) res.ball++;
	}
	res.ball -= res.strike;
	return res;
}
void doUserImplementation(int guess[]) {
	perm();
	Result candi,result;

	while(1){
		int now;
		for(int i=0 ; i<cnt ; i++){
			if(s[arr[i]] == 0){
				now = arr[i];
				guess[0] = now / 1000;
				guess[1] = now % 1000/100;
				guess[2] = now % 100 / 10;
				guess[3] = now % 10;
				break;
			}
		}
		candi = query(guess);
		if(candi.strike == 4) break;
		else s[arr[now]] = 1;

		for(int i=0 ; i<cnt ; i++){
			if(s[arr[i]] == 0){
				result = cmp(arr[i], now);
				if(result.strike != candi.strike || result.ball != candi.ball){
					s[arr[i]] = 1;
				}
			}
		}
	}
}
