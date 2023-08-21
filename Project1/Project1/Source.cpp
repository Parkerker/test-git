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
	/*--------------------------------- Camera.XML -�ϥΨ禡*/
	XMLDocument docc;
	docc.LoadFile("camera.xml");

	XMLElement* pFirst = docc.FirstChildElement("CameraI");
	ReadOneCameraAttribute(pFirst); std::cout << "------------------\n";

	bool camera1 = docc.FirstChildElement("CameraI")->FirstChildElement("ExposureAuto")->BoolText();
	cout << "camera1�G" << ((camera1==true) ? "true" : "false" )<< endl;
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
	cout << "\tDevID�G" << DevID << endl;
	cout << "\t\tDP�G" << Second << endl;
	cout << "\tIpAddress�G" << IpAddress << endl;
	cout << "\tSubnetMask�G" << SubnetMask << endl;
	cout << "\tExposureAuto�G" << ExposureAuto << endl;
	cout << "\tExposureTime�G" << ExposureTime << endl;
	cout << "\tTriggerMode�G" << TriggerMode << endl;

	//const char* IpAddress2 = DP.FirstChildElement("CameraIIII")->FirstChildElement("pass")->GetText();
	const char* attributeValue = DP.FirstChildElement("CameraIIII")->FirstChildElement("IpAddress")->Attribute("pass");
	//cout << "\tIpAddress2�G" << IpAddress2 << endl;
	cout << "\tattributeValue�G" << attributeValue << endl;
	/*�p�G����Ӥ@�˪��W�� �pCameraII �H�U�d��*/
	const char* NextSiblingCameraII = DP.FirstChildElement("CameraII")->NextSiblingElement("CameraII")->FirstChildElement("DevID")->GetText();
	cout << "\tNextSiblingCameraII�G" << NextSiblingCameraII << endl;


	return 0;
}


/*

(1) FirstChildElement(const char* value=0):����Ĥ@�ӭȬ�value���l�`�I�Avalue�q�{�Ȭ��šA�h��^�Ĥ@�Ӥl�`�I�C
�@�@(2) NextSiblingElement( const char* _value=0 ) �G��o�U�@��(�S��)�`�I�C
�@�@(3) LinkEndChild(XMLHandle *handle):�K�[�@�Ӥl�`�I�C�����Ϊ̤奻
�@�@(4) GetText() :��^�@�Ӥ������Ҫ����e
�@�@(5) LoadFile()�G������ơA�[���@��xml���
�@�@(6) SaveFile()�G������ơA�O�s�@��xml���
�@�@(7) Parse ()�G�ѪR�ǤJ�r�Ŧ�xml�ƾ�
�@�@(8) RootElement():����ڸ`�I
�@�@��h��ƨϥλ����A�����Ѧ�TinyXML����
*/

/*#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

	int a;
	cin >> a;
	cout << "a�G" << a << endl;


	return 0;
	system("pause");

}*/

