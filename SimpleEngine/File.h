#pragma once

class File final
{
public:
	File(const char* filename);
	File(const File&) = delete;
	File& operator=(const File&) = delete;
	~File();
	
	inline const char* GetBuffer() const { return mBuffer; }
	inline int GetSize() const { return mSize; }
	
private:
	const char* mFilename = nullptr;
	char* mBuffer = nullptr;
	int mSize = 0;
};
