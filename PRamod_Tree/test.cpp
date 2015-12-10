//===========================================================
// Name        : Multimedia
// Author      : Pramod Bhosale
// Description : Assignmet #4 :: Uniform Quantization
//===========================================================

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <cmath>
#include <fstream>
#include <math.h>
#include <sstream>

using namespace std;

int imgOutput[512][512];
int imgDecoded[512][512];
int imgError[512][512];
int newGrayLevel;
long total = 0;

int main() {
	ifstream myfileInput;
	ofstream myfileOutput, myfileOutDecoded, myfileOutError;
	string line1, line2;
	int width = 0;
	int height = 0;
	int max = 0;

//open input file
	myfileInput.open("baboon.pgma");
	if (!myfileInput)
	{
		cout << "NO FILE FOUND: PLEASE ENTER CORRECT PATH : ";
		return 0;
	}

// Skip the first two lines
	getline(myfileInput, line1);
	getline(myfileInput, line2);

// Get the values of height,width and maximum pixels
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			myfileInput >> width;
		}
		else if (i == 1)
		{
			myfileInput >> height;
		}
		else
		{
			myfileInput >> max;
		}
	}

// Get the values into two dimensional matrix
	int image_store[512][512];
	for (int j = 0; j < height; j++) {

		for (int k = 0; k < width; k++)
		{
			myfileInput >> image_store[j][k];
		}
	}

// Closing the file
	myfileInput.close();
	cout << "Enter the new gray levels";
	cin >> newGrayLevel;
	myfileOutput.open("resultedImage.pgma");
	if (!myfileOutput.is_open())
	{
		cout << "Could not open output image file\n";
		return 2;
	}

// Encoding the Image using newGrayLevel specified
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			imgOutput[i][j] = ((image_store[i][j]) / 256.0) * newGrayLevel;
		}
	}
	max = newGrayLevel - 1;

// Push the values into a new image output file
	myfileOutput << line1;
	myfileOutput << line2 << "\n";
	myfileOutput << width << " " << height << "\n";
	myfileOutput << max;
	int i = 0;
	for (int j = 0; j < height; j++)
	{
		for (int k = 0; k < width; k++)
		{
			if (i % 12 == 0)
			{
				myfileOutput << "\n" << imgOutput[j][k] << "  ";
			}
			else {
				myfileOutput << imgOutput[j][k] << "  ";
			}
			i++;
		}
	}

// Decoding the encoded image
	myfileOutDecoded.open("resultedImageDecoded.pgma");
	int noOfElementsInRegion = 256 / newGrayLevel;
	int addTerm = noOfElementsInRegion / 2;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			imgDecoded[i][j] = ((imgOutput[i][j] / (float) newGrayLevel) * 256)
					+ addTerm;
		}
	}
	max = 255;

// Push the values of the decoded image into a new ResultedImageDecoded file
	myfileOutDecoded << line1;
	myfileOutDecoded << line2 << "\n";
	myfileOutDecoded << width << " " << height << "\n";
	myfileOutDecoded << max;

	int l = 0;

	for (int j = 0; j < height; j++)
	{
		for (int k = 0; k < width; k++)
		{
			if (l % 12 == 0)
			{
				myfileOutDecoded << "\n" << imgDecoded[j][k] << "  ";}
			else {
				myfileOutDecoded << imgDecoded[j][k] << "  ";}
			l++;  }
	}

//calculate the error image
	myfileOutError.open("errorImage.pgma");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			imgError[i][j] = abs(image_store[i][j] - imgDecoded[i][j]);
		}
	}

	max = 255;
	myfileOutError << line1;
	myfileOutError << line2 << "\n";
	myfileOutError << width << " " << height << "\n";
	myfileOutError << max;
	int m = 0;
	for (int j = 0; j < height; j++)
	{
		for (int k = 0; k < width; k++)
		{
			if (m % 12 == 0)
		 {
				myfileOutError << "\n" << imgError[j][k] << "  ";}
			else {
				myfileOutError << imgError[j][k] << "  ";			}
			m++;
		}
}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			total = total + ((imgError[i][j]) * (imgError[i][j]));
	}
}
double distortion = total / (double) (512 * 512);
cout << "Distortion=" << distortion;
return 0;
}
