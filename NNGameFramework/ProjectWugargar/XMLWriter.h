#pragma once

#include <map>
#include <string>
#include "Library/TinyXML/tinyxml.h"
#include "Library/TinyXML/xpath_static.h"

class CXMLWriter
{
public:
	CXMLWriter(std::string filename);
	CXMLWriter(void);
	~CXMLWriter(void);

	NNCREATE_FUNC(CXMLWriter);	

	void AddNode(std::string elementName, std::string parent);
	void AddRoot(std::string rootname);
	void ExportXMLFile(void);

private:
	void initXML();


	std::string		m_Filename;	// 출력될 파일 이름
	TiXmlDocument	m_Document; 
	std::map<std::string, TiXmlElement> m_XMLhierarchy;

};

