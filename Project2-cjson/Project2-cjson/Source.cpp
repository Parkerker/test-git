#include <string>
#include "cJSON.h"
#include <json.h>
#include <iostream>
#include <fstream>
using namespace std;
void readstrjson() {
		const char* str=
			"{\"name\":\"shuiyixin\",\"age\":\"21\",\"sex\":\"man\"}";
		
		Json::Reader reader;
		Json::Value root;

		if (reader.parse(str, root))
		{
			string name = root["name"].asString();
			int age = root["nomen"].asInt();
			string sex = root["sex"].asString();
			cout << name + "," << age << "," << sex << endl;

		}
}
//I从字符串中读取SON
//void readstrprojson();//从字得串中读取]SON（内容复杂些）
void readFilejson() {

	Json::Reader reader;
	Json::Value root;
		ifstream in("demo.json", ios::binary);
	if (!in.is_open())
	{
		cout << "Error opening file\n";
		return;
	}
		if (reader.parse(in, root)){
			string name = root["name"].asString();
			int age = root["age"].asInt();
			string sex = root["sex"].asString();

			cout << "My name is " << name << endl;
			cout << "I'm " << age << " years old" << endl;
			cout << "I'm a " << sex << endl;

			string friend_name = root["friends"]["friend_name"].asString();
			int friend_age = root["friends"]["friend_age"].asInt();
			string friend_sex = root["friends"]["friend_sex"].asString();

			cout << "My friend's name is " << friend_name << endl;
			cout << "My friend's sex is " << friend_sex << endl;
			cout << "My friend is " << friend_age << " years old" << endl;

			cout << "Here's my hobby:" << endl;
			for (unsigned int i = 0; i < root["hobby"].size(); i++){
				
				string ach = root["hobby"][i].asString();
				cout << ach << '\t';
			}
				cout << endl;
				cout << "Reading Complete!" << endl;
				
			
		}
		else
			cout << "parse error\n" << endl;
	in.close();


}//从文件中读SON


int main(){
	
	readFilejson();//从文件中读取]SON
	cout << "\n\n";


	readstrjson();//从字符串中读json
	cout << "\n\n";
	//readstrprojson();//从字中读取SON（内容复杂些。
	system("pause");
	return 0;
}