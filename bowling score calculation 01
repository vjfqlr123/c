#include <stdio.h>

int main(void)
{
	int frameScore[9+1][2+1] = {0, };
	int frameScore10[3+1] = {0, };
	
	int scores[10+1] = {0, };
	
	
	// 1~9 frame game
	for(int i=1; i<=9; ++i){
		
		printf("%d frame 1st bow : ", i);
		// first bow
		scanf("%d", &frameScore[i][1]);
		
		// (i-1) frame spare --> find i-1 frame score
		if(frameScore[i-1][1] != 10 && frameScore[i-1][1] + frameScore[i-1][2] ==10 && i >= 2){
			scores[i-1] = scores[i-2] + 10 + frameScore[i][1];
			printf("#frame : %d score : %d\n", i-1, scores[i-1]);
		
		// (i-2) frame strike, (i-1) frame strike --> find i-2 frame score	
		}else if(frameScore[i-2][1] == 10 && frameScore[i-1][1] == 10 && i >= 3){
			scores[i-2] = scores[i-3] + 10 + 10 + frameScore[i][1];
			printf("#frame : %d score : %d\n", i-2, scores[i-2]);
			
		}	
		
		
		// second bow <-- first bow != 10
		if(frameScore[i][1] != 10){
			printf("%d frame 2nd bow : ", i);
			scanf("%d", &frameScore[i][2]);
		
			// (i-1) frame strike --> find i-1 frame score
			if(frameScore[i-1][1] == 10 && i>=2){
				scores[i-1] = scores[i-2] + 10 + frameScore[i][1] + frameScore[i][2];
				printf("#frame : %d score : %d\n", i-1, scores[i-1]);
			
			}	
			
			// i frame is not strike or spare --> find i frame score
			if(frameScore[i][1] + frameScore[i][2] < 10){
				scores[i] = scores[i-1] + frameScore[i][1] + frameScore[i][2];
				printf("#frame : %d score : %d\n", i, scores[i]);
				
			}
		}
	}
	
	// 10 frame game
	printf("10 frame 1st bow : ");
	scanf("%d", &frameScore10[1]);
	if(frameScore[9][1] != 10 && frameScore[9][1] + frameScore[9][2] == 10){
		scores[9] = scores[8] + 10 + frameScore10[1];
		printf("#frame : %d score : %d\n", 9, scores[9]);
	
	}else if(frameScore[8][1] == 10 && frameScore[9][1] == 10){
		scores[8] = scores[7] + 10 + 10 + frameScore10[1];
		printf("#frame : %d score : %d\n", 8, scores[8]);
	
	}
	printf("10 frame 2nd bow : ");
	scanf("%d", &frameScore10[2]);
	
	if(frameScore[9][1] == 10){
		scores[9] = scores[8] + 10 + frameScore10[1] + frameScore10[2];
		printf("#frame : %d score : %d\n", 9, scores[9]);	
		
	}
	
	if(frameScore10[1] + frameScore10[2] < 10){
		scores[10] = scores[9] + frameScore10[1] + frameScore10[2];
		printf("#frame : %d score : %d\n", 10, scores[10]);
		
	}
	
	
	//if(frameScore10[1] == 10 || frameScore10[1] + frameScore10[2] == 10){
	if(frameScore10[1] + frameScore10[2] >= 10){
		printf("10 frame 3rd bow : ");
		scanf("%d", &frameScore10[3]);
		
		scores[10] = scores[9] + frameScore10[1] + frameScore10[2] + frameScore10[3];
		printf("#frame : %d score : %d\n", 10, scores[10]);
		
	}
	
	
	return 0;
}
