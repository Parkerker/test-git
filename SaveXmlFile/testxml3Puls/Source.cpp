#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "tinyxml2.hpp"
#include "tinyxml2.cpp"
#include <iomanip>

#include <typeinfo>
//#include <array>
//#include <direct.h>
using namespace std;
using namespace tinyxml2;

int main() {

	XMLDocument doc;
	doc.LoadFile("./xml.xml");

	//vector<const char*> elems = { "title", "description", "date", "time", "tag" };
	vector<const char*> Name = {};
	XMLElement* p_root_element = doc.RootElement();
	XMLElement* p_Employee = p_root_element->FirstChildElement("Employee");

	while (p_Employee) {

		XMLElement* e_Name = p_Employee->FirstChildElement("Name");
		cout << e_Name->GetText() << endl;
		Name.push_back(e_Name->GetText());

		p_Employee = p_Employee->NextSiblingElement("Employee");



	}
	for (int i = 0; i < Name.size(); i++) {
		cout << "Name" << i << "：" << Name[i] << endl;

	}
	string s="Drake";
	while(cin >> s){
	if (Name[1] == s) { cout << "Take "<<Name[1]<<" YA!!" << endl; }
	//cout << "Take " << (Name[1] == s ?  Name[1] : "not get")<<endl;
	//cout << "變數：" << typeid("Drake").name() << endl;
	//cout << "變數s：" << typeid(s).name() << endl;

	cout << " s：" << s << endl;
	}
	//cout << p_root_element->FirstChildElement("date")->FirstChildElement("article")->FirstChildElement("title")->GetText() << endl;
	//cout <<"xx" << p_root_element->FirstChildElement("data")->FirstChildElement("article")->FirstChildElement("title")->GetText() << endl;
	/*
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
	}*/





	return 0;
}
