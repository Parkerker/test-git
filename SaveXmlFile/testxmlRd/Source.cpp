#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "tinyxml2.cpp"
#include <iomanip>
#include <typeinfo>

//#include <array>
//#include <direct.h>
using namespace std;
using namespace tinyxml2;

int main() {

	XMLDocument doc;
	doc.LoadFile("./xmlrd.xml");

	vector<const char*> accou = { "AccountNo", "type", "customer", "balance", "openDate" };
	vector<const char*> Account = {};
	XMLElement* p_root_element = doc.RootElement();
		XMLElement* p_Accounts = p_root_element->FirstChildElement("Accounts");
			XMLElement* p_Account = p_Accounts->FirstChildElement("Account");

	while (p_Account) {

		//const char* e_attribute = p_Employee->Attribute("student_type");
		//cout << e_attribute << endl;
		for (int i = 0; i < accou.size(); i++) {
			XMLElement* e_Accou = p_Account->FirstChildElement(accou[i]);
			cout <<"\t\t\t"<<accou[i]<<"：" << e_Accou->GetText() << endl;
			Account.push_back(e_Accou->GetText());
			if (i == accou.size()-1)cout << endl;
		}
		//XMLElement* e_Name = p_Account->FirstChildElement("Name");
		//cout << e_Name->GetText() << endl;
		
		
		p_Account = p_Account->NextSiblingElement("Account");



	}
	string s = "";
	/*char name[10];
	cout << "enter your name :";
	cin.getline(name, 10);*/
	
	for (int i = 0; i < Account.size(); i++) { cout << "Account：" << Account[i]<<i<<endl; }
	while (getline(cin, s)) {
		cout << "s：" << s << endl;
		if (s == Account[2]) { cout << "customer：" << Account[2] << endl; }
		if (s == Account[3])cout << "3"<<endl;
		if (s == Account[4])cout << "4" << endl;
	}

	XMLDocument docsave;

	string filename;
	cin >> filename;
	//【】構建我們的xml數據結構
	XMLDeclaration* declaration = docsave.NewDeclaration();
	docsave.InsertFirstChild(declaration);
	//建立與此文件關聯的新元素。元素的記憶體由文件管理。
	XMLElement* root = docsave.NewElement("Account");
	docsave.InsertEndChild(root);
	XMLElement* accountNo = root->InsertNewChildElement("AccountNo");
	accountNo->SetAttribute("Type", "A");
	accountNo->SetText("1");
	XMLElement* type = root->InsertNewChildElement("type");
	type->SetText("Saving");
	XMLElement* customer = root->InsertNewChildElement("customer");
	customer->SetText("John Doe");
	XMLElement* balance = root->InsertNewChildElement("balance");
	balance->SetText("399.88");
	XMLElement* openDate = root->InsertNewChildElement("openDate");
	openDate->SetText("01/01/2023");
	string aa = "./" + filename + ".xml";
	//docsave.SaveFile("./1234.xml");// aa.c_str()
	const char* abc = aa.c_str();
	docsave.SaveFile(abc);// aa.c_str()
	system("pause");
	return 0;
}





/*
//xml.xml
int main() {

	XMLDocument doc;
	doc.LoadFile("./xml.xml");

	//vector<const char*> elems = { "title", "description", "date", "time", "tag" };
	vector<const char*> Name = {};
	XMLElement* p_root_element = doc.RootElement();
	XMLElement* p_Employee = p_root_element->FirstChildElement("Student");

	//test read attribute
	while (p_Employee) {
		
		const char* e_attribute = p_Employee->Attribute("student_type");
		cout << e_attribute << endl;
		XMLElement* e_Name = p_Employee->FirstChildElement("Name");
		cout << e_Name->GetText() << endl;
		Name.push_back(e_Name->GetText());

		p_Employee = p_Employee->NextSiblingElement("Student");



	}
	cout << "----check Name----" << endl;
	for (int i = 0; i < Name.size(); i++) {
		cout << "Name" << i << "：" << Name[i] << endl;

	}
	

	//輸入尋找
	/*string s = "Drake";
	while (cin >> s) {
		if (Name[1] == s) { cout << "Take " << Name[1] << " YA!!" << endl; }
		//cout << "Take " << (Name[1] == s ?  Name[1] : "not get")<<endl;


		cout << " s：" << s << endl;
	}*/


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





	//return 0;
//}

