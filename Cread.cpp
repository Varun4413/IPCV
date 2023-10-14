/**
* @file image_copy.c
* @brief This programs opens a BMP image, reads the header, colortable, and image data.
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	FILE *file;
	//FILE* outfile;
	//const char* outname = "C:/Users/LENOVO/source/repos/OpencvCourse1/Resources/sample_gray.bmp";

	const char* filename = "C:/Users/LENOVO/source/repos/OpencvCourse1/Resources/sample.bmp";
	
	//unsigned char header[54]; // to store the image header
	//unsigned char colorTable[1024]; // to store the colorTable, if it exists.

	//for (int i = 0; i < 54; i++)
	//	header[i] = getc(streamIn);  // strip out BMP header, byte-wise

	//int width = *(int*)&header[18]; // read the width from the image header
	//int height = *(int*)&header[22]; // read the height from the image header
	//int bitDepth = *(int*)&header[28]; // read the bitDepth from the image header
	//printf("width is %d", width);
	if (fopen_s(&file, filename, "rb") == 0) {
		// File opened successfully in binary read mode ("rb")
		// You can now read from the file or perform other operations.

		// For example, you can read binary data from the file using fread:
		// fread(buffer, sizeof(char), size, file);
		  // Seek to the beginning of the file
		fseek(file, 0, SEEK_SET);

		// Read the BMP header (at least the relevant parts)
		unsigned char header[54];
		fread(header, sizeof(unsigned char), 54, file);

		// Extract image width and height from the header
		int size = *(int*)&header[2];//size
		int width = *(int*)&header[18]; // Offset 18 contains the width
		int height = *(int*)&header[22]; // Offset 22 contains the height
		int colorPlanes = *(short*)&header[26];
		int bitDepth = *(int*)&header[28];
		printf("width is %d  ", width);
		printf("Num of colorPlanes is %d  ", colorPlanes);
		printf("size is %d  ", size);
		printf("Bit depth is %d  ", bitDepth);
		// Close the file when you're done.
		fclose(file);
	}
	else {
		// File opening failed
		printf("Failed to open the file.\n");
	}
	return 0;
}