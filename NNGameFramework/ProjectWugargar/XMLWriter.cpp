#include "XMLWriter.h"



CXMLWriter* CXMLWriter::Create( std::string filename )
{
	CXMLWriter* pInstance = nullptr;
	pInstance = new CXMLWriter(filename);
	return pInstance;
}

CXMLWriter::CXMLWriter(void)
{
	CXMLWriter("default_name.xml");
}

CXMLWriter::CXMLWriter( std::string filename )
{
	initXML();
	m_Filename = filename;
}


void CXMLWriter::initXML()
{
	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "euc-kr", "" ); 
	m_Document.LinkEndChild( decl );
}

CXMLWriter::~CXMLWriter(void)
{
}

void CXMLWriter::AddRoot( std::string rootname )
{
	TiXmlElement* root = new TiXmlElement(rootname.c_str());
	m_XMLhierarchy.emplace(rootname, root);
	m_Document.LinkEndChild(root);
}

void CXMLWriter::AddNode( std::string elementName, std::string parentName )
{
	TiXmlElement* element = new TiXmlElement(elementName.c_str());
	m_XMLhierarchy.emplace(elementName, element);
	(m_XMLhierarchy.at(parentName))->LinkEndChild(element);

}

void CXMLWriter::AddText( std::string content, std::string element )
{
	TiXmlText* text = new TiXmlText(content.c_str());
	m_XMLhierarchy.emplace(content, text);
	(m_XMLhierarchy.at(element))->LinkEndChild(text);
}

void CXMLWriter::ExportXMLFile( void )
{
	m_Document.SaveFile(m_Filename.c_str());
}

