
#pragma once

#include "Library/TinyXML/tinyxml.h"
#include "Library/TinyXML/xpath_static.h"
#include <string>

class NNXML
{
public: 
	NNXML( std::string path );
	NNXML( char *buf );
	NNXML();
	~NNXML();

	static NNXML* Create( std::string path );
	static NNXML* Create();
	static NNXML* CreateStream( char* buf );

	std::string XPathToString( std::string xpath );
	TiXmlDocument* GetDoc(){ return &m_Document; }
	bool GetLoadSuccess(void) { return m_LoadSuccess; }
private:
	TiXmlDocument m_Document;

	bool m_LoadSuccess;
};