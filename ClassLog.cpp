#include "ClassLog.h"

ClassLog::ClassLog(std::string FilePath)
{
	m_File.open(FilePath);

	std::string Buffer;
	int Pos;

	while (m_File)
	{
		Buffer.push_back(m_File.get());
	}

	m_FileBuffer = Buffer;

	//std::cout << Buffer << std::endl;

	while (Pos = Buffer.find('\n'), Pos != std::string::npos)
	{
		std::string BufferLine(Buffer.substr(0, Pos));

		int Pos2;
		if (Pos2 = BufferLine.find('='), Pos2 != std::string::npos)
		{
			std::string TempItemName = BufferLine.substr(0,Pos2);
			std::string TempItemValue = BufferLine.substr(Pos2 + 1);

			//std::cout << "Success: name:" << TempItemName << " value:" << TempItemValue << std::endl;
			m_ItemVector.push_back(std::make_pair(TempItemName, TempItemValue));
		}

		Buffer = Buffer.substr(Pos + 1);
	}
}


std::string ClassLog::getItem(std::string ItemName)
{
	for (const auto& Item : m_ItemVector)
	{
		//std::cout << Item.first << std::endl;
		if (Item.first == ItemName)
			return Item.second;
	}

	return std::string();
}

void ClassLog::setItem(std::string ItemName,std::string ItemValue)
{

	for (auto& Item : m_ItemVector)
	{
		if (Item.first == ItemName)
			Item.second = ItemValue;
	}
	m_File.clear();
	m_File.seekp(0);
	m_File << "[start]" << std::endl;
	for (auto& Item : m_ItemVector)
	{
		std::string TempString(Item.first);
		TempString += '=';
		TempString += Item.second;

		m_File << TempString << std::endl;
	}
	m_File << "[end]" << std::endl;

	
	m_File.flush();
}
