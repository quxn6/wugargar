#include "XMLWriter.h"


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

void CXMLWriter::AddNode( std::string elementName, std::string parent )
{
	TiXmlElement* element = new TiXmlElement(elementName.c_str());
	// 계속 구현할 것 ㅎㅎ

}

void CXMLWriter::AddRoot( std::string rootname )
{
	TiXmlElement* root = new TiXmlElement(rootname.c_str());
	m_XMLhierarchy.emplace(rootname, root);
	m_Document.LinkEndChild(root);
}

void CXMLWriter::ExportXMLFile( void )
{

}

