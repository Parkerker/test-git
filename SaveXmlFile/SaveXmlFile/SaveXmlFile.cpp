#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "tinyxml2.cpp"
#include <iomanip>
//#include <array>
using namespace std;
using namespace tinyxml2;

int main() {
	
	string path = ".\\";
	string dirr;
	cin >> dirr;
	path = "mkdir" + path + dirr;
	system(path.c_str());

	//test catalog.xml
	XMLDocument doc;
	doc.LoadFile("./catalog.xml");

	vector<const char*> elems = { "COMMON", "BOTANICAL", "ZONE", "LIGHT", "PRICE","AVAILABILITY"};
	vector<const char*> common = {}, botanical = {}, zone = {}, light = {}, price = {}, availability = {};
	//Attributes
	vector<const char*> attr = {}; attr.push_back("Part_3");

	XMLElement* p_root_element = doc.RootElement();
	XMLElement* p_plant = p_root_element->FirstChildElement("PLANT"); //data(X
	
		
		while (p_plant) {
			for (int i=0; i < elems.size(); ++i) {
				XMLElement* ptr = p_plant->FirstChildElement(elems[i]);
				cout << elems[i] << ": " << ptr->GetText() << '\n';

				if (i == 0)common.push_back(ptr->GetText());
				if (i == 1)botanical.push_back(ptr->GetText());
				if (i == 2)zone.push_back(ptr->GetText());
				if (i == 3)light.push_back(ptr->GetText());
				if (i == 4)price.push_back(ptr->GetText());
				if (i == 5)availability.push_back(ptr->GetText());

				cout << (i == elems.size() - 1 ? "\n" : "");

			}
			p_plant = p_plant->NextSiblingElement("PLANT");
		}
		for (int i = 0; i < common.size(); ++i) {
			cout << elems[0] << "：" << common[i] << endl;
		
		}
		
		//test cout correct
		/*
		*string s = ""; 
		while (getline(cin, s)) {
			for (int i = 0; i < common.size(); ++i) {
				if (s == common[i]) {
					cout << elems[0] << "：" << common[i] << endl;
					cout << elems[1] << "：" << botanical[i] << endl;
					cout << elems[2] << "：" << zone[i] << endl;
					cout << elems[3] << "：" << light[i] << endl;
					cout << elems[4] << "：" << price[i] << endl;
					cout << elems[5] << "：" << availability[i] << endl;	
				}
			}

		}*/
		string filename;
		while (getline(cin, filename)) {
			for (int i = 0; i < common.size(); ++i) {
				if (filename == common[i]) {
					
					XMLDocument docsave;
	
					//【】構建我們的xml數據結構
					XMLDeclaration* declaration = docsave.NewDeclaration();
					docsave.InsertFirstChild(declaration);
					//建立與此文件關聯的新元素。元素的記憶體由文件管理。
					XMLElement* root = docsave.NewElement("Catalog");
					docsave.InsertEndChild(root);
					XMLElement* Plant = root->InsertNewChildElement("PLANT");
					Plant->SetAttribute("alias", attr[0]);
					//Plant->SetText("1");
					XMLElement* COMMON = Plant->InsertNewChildElement("COMMON");
					COMMON->SetText(common[i]);
					XMLElement* BOTANICAL = Plant->InsertNewChildElement("BOTANICAL");
					BOTANICAL->SetText(botanical[i]);
					XMLElement* ZONE = Plant->InsertNewChildElement("ZONE");
					ZONE->SetText(zone[i]);
					XMLElement* LIGHT = Plant->InsertNewChildElement("LIGHT");
					LIGHT->SetText(light[i]);
					XMLElement* PRICE = Plant->InsertNewChildElement("PRICE");
					PRICE->SetText(price[i]);
					XMLElement* AVAILABILITY = Plant->InsertNewChildElement("AVAILABILITY");
					AVAILABILITY->SetText(availability[i]);

					string aa = "./" + dirr + "/" + filename + ".xml";
					//docsave.SaveFile("./1234.xml");// aa.c_str()
					const char* abc = aa.c_str();
					docsave.SaveFile(abc);// aa.c_str()
					cout<<"Save Successful..." << endl;
				}
			}

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