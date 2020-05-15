#include <fstream>

#include "File.h"

File::File(const char* filename)
	: mFilename(filename)
{
	std::ifstream file(filename, std::ifstream::binary);

	file.seekg(0, std::ifstream::end);
	mSize = static_cast<int>(file.tellg());
	file.seekg(0, std::ifstream::beg);

	mBuffer = new char[mSize];
	file.read(mBuffer, mSize);
}

File::~File()
{
	delete[] mBuffer;
}
