#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "tinyxml2.hpp"
#include "tinyxml2.cpp"
#include <iomanip>
//#include <array>
//#include <direct.h>
using namespace std;
using namespace tinyxml2;

int main() {
	/* test ³Ð¸ê®Æ§¨
	string s = ".\\";
	string dir;
	cin >> dir;
	//int a;
	//cin >> a;
	//string as = "";
	//as = to_string(a);
	//s = s + as;
		s = "mkdir"+ s + dir;
		system(s.c_str());
		
	//test 2dir
		string s1 = ".\\123456\\";
		string dirr;
		cin >> dirr;
		s1 = "mkdir" + s1 + dirr;
		system(s1.c_str());
	*/

	//test fourth.xml
	XMLDocument doc;
	doc.LoadFile("./fourth.xml");

	vector<const char*> elems = { "title", "description", "date", "time", "tag" };

	XMLElement* p_root_element = doc.RootElement();
	XMLElement* p_date = p_root_element->FirstChildElement("date");//data(X

	//cout << p_root_element->FirstChildElement("date")->FirstChildElement("article")->FirstChildElement("title")->GetText() << endl;
	//cout <<"xx" << p_root_element->FirstChildElement("data")->FirstChildElement("article")->FirstChildElement("title")->GetText() << endl;
	while (p_date) {
		XMLElement* p_article = p_date->FirstChildElement("article");
		while (p_article) {
			for (size_t i{}; i < elems.size(); ++i) {
				XMLElement* ptr = p_article->FirstChildElement(elems[i]);
				cout << elems[i] << ": " << ptr->GetText() << '\n';
				cout << (i == elems.size() - 1 ? "\n" : "");

			}
			p_article = p_article->NextSiblingElement("article");
		}
		p_date = p_date->NextSiblingElement("date");
	}
	//return EXIT_SUCCESS;

	


	return 0;
}

/*
#include <iostream>
#include <vector>
#include "tinyxml2/tinyxml2.hpp"

int main(){
  tinyxml2::XMLDocument doc;
  doc.LoadFile("fourth.xml");

  std::vector<const char*> elems = {"title", "description", "date", "time", "tag"};

  tinyxml2::XMLElement * p_root_element = doc.RootElement();
  tinyxml2::XMLElement * p_date = p_root_element->FirstChildElement("date");

  while(p_date){
	tinyxml2::XMLElement * p_article = p_date->FirstChildElement("article");
	while(p_article){
	  for (std::size_t i{}; i < elems.size(); ++i){
		tinyxml2::XMLElement * ptr = p_article->FirstChildElement(elems[i]);
		std::cout << elems[i] << ": " << ptr->GetText() << '\n';
		std::cout << ( i == elems.size() - 1 ? "\n" : "");
	  }
	  p_article = p_article->NextSiblingElement("article");
	}
	p_date = p_date->NextSiblingElement("data");
  }
  return EXIT_SUCCESS;
}
*/