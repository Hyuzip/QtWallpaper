#pragma once
#include <fstream>
#include <string>
#include <vector>

//#include <iostream>

#define WALLPAPERPATH_ITEM ("WallpaperPath")

class ClassLog
{
public:
	ClassLog(std::string);


	std::string getItem(std::string);
	void		setItem(std::string,std::string);

private:
	std::fstream m_File;
	std::string m_FileBuffer;


	std::vector<std::pair<std::string/*ItemName*/, std::string/*ItemValue*/>> m_ItemVector;
};

