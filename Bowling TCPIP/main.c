#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// hit and spare
	int fir_hit;
	int sed_hit;
	int fir_spare[12] = {0, };
	int sed_spare;
	
	// etc
	int pin = 10;
	int total_sum;
	int i;
	
	// stage
	int frame;
	int frame_score[12] = {0, };
	int strike[12] = {0, };
	int spare_check[12] = {0, };
	
	// 1~10 frame
	for(frame = 0; frame < 10; ++frame){
		printf("=================%d==================\n", frame+1);
		printf("1st ");
		
		scanf("%d", &fir_hit);
		if(fir_hit > 10 || fir_hit < 0){
			printf("try input nember\n");
			--frame;
			continue;
		}	
	
		if(fir_hit == 10){
			printf("ST\n");
			frame_score[frame] = 10;
			strike[frame] = 1;
			continue;

		}else if(fir_hit < 10){
			fir_spare[frame] = pin - fir_hit;
			frame_score[frame] = fir_hit;
		
			printf("2st ");
			scanf("%d", &sed_hit);
		
			if(sed_hit > fir_spare[frame]){
				printf("try input nember\n");
				--frame;
				continue;
			}
			sed_spare = abs(fir_spare[frame] - sed_hit);
		
			if(sed_spare == 0){
				printf("SP\n");
				frame_score[frame] += sed_hit;
				spare_check[frame] = 1;
				continue;
			
			}else if(sed_spare > 0){
				frame_score[frame] += sed_hit;
				printf("%d\n", frame_score[frame]);
				
			}
		}
	}	
	

	// bouns
	if(strike[9] == 1){
		while(1){
			printf("================bouns stage==============\n");
			printf("1st ");
			scanf("%d", &fir_hit);
	
			if(fir_hit > 10 || fir_hit < 0){
				printf("try input nember\n");
				continue;
			}	

			if(fir_hit == 10){
				printf("ST\n");
				frame_score[10] = 10;
				strike[10] = 1;
			
				if(strike[10] == 1){
					printf("================bouns stage==============\n");
					printf("1st ");
					scanf("%d", &fir_hit);
	
					if(fir_hit > 10 || fir_hit < 0){
						printf("try input nember\n");
						continue;
					}	

					if(fir_hit == 10){
						printf("ST\n");
						frame_score[11] = 10;
						strike[11] = 1;
						break;	
					
					}else if(fir_hit < 10){
						printf("================bouns stage==============\n");
						printf("2st ");
						frame_score[11] = fir_hit;
						fir_spare[11] = pin - fir_hit;
						break;
					}
				}
			
			}else if(fir_hit < 10){
				printf("2st ");
				scanf("%d", &sed_hit);
				frame_score[10] = fir_hit + sed_hit;
				break;
			}
		}
	}
	
	// bouns
	if(spare_check[9] == 1){
		printf("================bouns stage==============\n");
		printf("1st ");
		scanf("%d", &fir_hit);
		frame_score[10] = fir_hit;
	}

	// strike_sum
	for(i=0; i<10; ++i){
		if(strike[i] == 1 && strike[i+1] != 1 && strike[i+2] != 1){
			if(i==9){
				frame_score[i] += (pin - fir_spare[i+1]);
			
			}else{
				frame_score[i] += frame_score[i+1];
			}
			 
		}else if(strike[i] == 1 && strike[i+1] == 1 && strike[i+2] != 1){
			if(i==9){
				frame_score[i] = frame_score[i+1] + (pin - fir_spare[i+2]);
			}else{
				frame_score[i] = frame_score[i+1] + frame_score[i+2];
			}
			
		}else if(strike[i] == 1 && strike[i+1] == 1 && strike[i+2] == 1){
			frame_score[i] += 20;
		}
	}
	
	
	// spare_sum
	for(i=0; i<10; ++i){
		if(spare_check[i] == 1){
			frame_score[i] = frame_score[i] + (pin - fir_spare[i+1]);
		}
	}
	
	// total_sum
	for(i=0; i<10; ++i){
		total_sum += frame_score[i];
	}
	printf("%d\n", total_sum);	
	

	return 0;
}
