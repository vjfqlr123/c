#include <stdio.h>

typedef struct{
	char name[21];
	int kor;
	int eng;
	int mat;
	int sum;
	double avg;
	int rank;
} student;

int main(void)
{
	FILE *fin = fopen("score.dat", "r");
	
	student students[5];
	for(int i = 0; i<5; ++i){
		fscanf(fin, "%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].mat);
		students[i].sum = students[i].kor + students[i].eng + students[i].mat;
		students[i].avg = (double)students[i].sum/3;
		students[i].rank = 1;
	}
	
	for(int i = 0; i<5; ++i){
		for(int j = 0; j<5; ++j){
			if(students[i].sum < students[j].sum){
				++students[i].rank;
			}
		}
	}
	
	for(int i =0; i<5; ++i){
		printf("%s %d %d %d %d %.2f %d\n", students[i].name, students[i].kor, students[i].eng, students[i].mat, students[i].sum, students[i].avg, students[i].rank);
	}
	
	fclose(fin);
	return 0;
}
