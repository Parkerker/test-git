#include <iostream>
#include <fstream>
#include <vector>
#include "tinyxml2.cpp"

using namespace std;
using namespace tinyxml2;

static void ReadOneCameraAttribute(const tinyxml2::XMLElement* p)
{
	int devIdContent = p->FirstChildElement("DevID")->IntText();
	const char* ipAddrContent = p->FirstChildElement("IpAddress")->GetText();
	const char* subnetMaskContent = p->FirstChildElement("SubnetMask")->GetText();
	const char* exposureAutoContent = p->FirstChildElement("ExposureAuto")->GetText();
	int64_t exposureTimeContent = p->FirstChildElement("ExposureTime")->Int64Text();
	bool triggerModeContent = p->FirstChildElement("TriggerMode")->BoolText();

	std::cout << "devIdContent(int):\t" << devIdContent << std::endl;
	std::cout << "ipAddrContent:\t" << ipAddrContent << std::endl;
	std::cout << "subnetMaskContent:\t" << subnetMaskContent << std::endl;
	std::cout << "exposureAutoContent:\t" << exposureAutoContent << std::endl;
	std::cout << "exposureTimeContent(int64_t):\t" << exposureTimeContent << std::endl;
	std::cout << "triggerModeContent(bool):\t" << ((triggerModeContent == true) ? "true" : "false") << std::endl;
}

int main(void)
{
	cout << "\nParsing my students data (sample.xml)....." << endl;
	// Read the sample.xml file
	XMLDocument doc;
	doc.LoadFile("sample.xml");
	

	const char* title = doc.FirstChildElement("MyStudentsData")->FirstChildElement("Student")->GetText();
	printf("Student Name: %s\n", title);

	XMLText* textNode = doc.LastChildElement("MyStudentsData")->LastChildElement("Student")->FirstChild()->ToText();
	title = textNode->Value();
	printf("Student Name: %s\n", title);
	/*--------------------------------- Camera.XML -使用函式*/
	XMLDocument docc;
	docc.LoadFile("camera.xml");

	XMLElement* pFirst = docc.FirstChildElement("CameraI");
	ReadOneCameraAttribute(pFirst); std::cout << "------------------\n";

	bool camera1 = docc.FirstChildElement("CameraI")->FirstChildElement("ExposureAuto")->BoolText();
	cout << "camera1：" << ((camera1==true) ? "true" : "false" )<< endl;
	cout << "\t\t ->" << endl;
	/*--------------------------------- Camera.XML-CameraIIII Test*/
	XMLDocument DP;
	DP.LoadFile("camera.xml");

	int DevID = DP.FirstChildElement("CameraIIII")->FirstChildElement("DevID")->IntText();
	int Second = DP.FirstChildElement("CameraIIII")->FirstChildElement("DevID")->FirstChildElement("DP")->IntText();
	const char* IpAddress= DP.FirstChildElement("CameraIIII")->FirstChildElement("IpAddress")->GetText();
	const char* SubnetMask = DP.FirstChildElement("CameraIIII")->FirstChildElement("SubnetMask")->GetText();
	const char* ExposureAuto = DP.FirstChildElement("CameraIIII")->FirstChildElement("ExposureAuto")->GetText();
	int ExposureTime = DP.FirstChildElement("CameraIIII")->FirstChildElement("ExposureTime")->IntText();
	const char* TriggerMode = DP.FirstChildElement("CameraIIII")->FirstChildElement("TriggerMode")->GetText();
	cout << "\tDevID：" << DevID << endl;
	cout << "\t\tDP：" << Second << endl;
	cout << "\tIpAddress：" << IpAddress << endl;
	cout << "\tSubnetMask：" << SubnetMask << endl;
	cout << "\tExposureAuto：" << ExposureAuto << endl;
	cout << "\tExposureTime：" << ExposureTime << endl;
	cout << "\tTriggerMode：" << TriggerMode << endl;

	//const char* IpAddress2 = DP.FirstChildElement("CameraIIII")->FirstChildElement("pass")->GetText();
	const char* attributeValue = DP.FirstChildElement("CameraIIII")->FirstChildElement("IpAddress")->Attribute("pass");
	//cout << "\tIpAddress2：" << IpAddress2 << endl;
	cout << "\tattributeValue：" << attributeValue << endl;
	/*如果有兩個一樣的名稱 如CameraII 以下範例*/
	const char* NextSiblingCameraII = DP.FirstChildElement("CameraII")->NextSiblingElement("CameraII")->FirstChildElement("DevID")->GetText();
	cout << "\tNextSiblingCameraII：" << NextSiblingCameraII << endl;


	return 0;
}


/*

(1) FirstChildElement(const char* value=0):獲取第一個值為value的子節點，value默認值為空，則返回第一個子節點。
　　(2) NextSiblingElement( const char* _value=0 ) ：獲得下一個(兄弟)節點。
　　(3) LinkEndChild(XMLHandle *handle):添加一個子節點。元素或者文本
　　(4) GetText() :返回一個元素標籤的內容
　　(5) LoadFile()：重載函數，加載一個xml文件
　　(6) SaveFile()：重載函數，保存一個xml文件
　　(7) Parse ()：解析傳入字符串xml數據
　　(8) RootElement():獲取根節點
　　更多函數使用說明，直接參考TinyXML文檔
*/

/*#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

	int a;
	cin >> a;
	cout << "a：" << a << endl;


	return 0;
	system("pause");

}*/

