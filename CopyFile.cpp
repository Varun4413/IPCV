#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>



int main(int argc, char* argv[]) {
	const char* filename = "C:/Users/LENOVO/source/repos/OpencvCourse1/Resources/test.txt";
	const char* filename2 = "C:/Users/LENOVO/source/repos/OpencvCourse1/Resources/test_copy.txt";
	//printf("%c", *filename);

	FILE* source;
	FILE* desti;
	source = fopen(filename, "r");
	desti = fopen(filename2, "w");
	//unsigned char contents[100];
	char c = fgetc(source);
	printf("%c\n", c);
	int i = 0;
	while (c != EOF) {
		fputc(c, desti);
		c = fgetc(source);
		//
		i++;
		printf("%c", c);
	} 
	printf("Total characters = %d", i);
	if (i > -1) {
		fclose(source);
		fclose(desti);
	}
	return 0;
}