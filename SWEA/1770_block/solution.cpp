#define MAX 30000

void flip(int map[4][4]){
	int temp;
	for(int i=0 ; i<4 ; i++){
		int temp = map[i][0];
		map[i][0] = map[i][3];
		map[i][3] = temp;
		temp = map[i][1];
		map[i][1] = map[i][2];
		map[i][2] = temp;
	}
}
int makeBlock(int module[][4][4])
{
}
