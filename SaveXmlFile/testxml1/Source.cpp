#include <iostream>
#include <fstream>
#include <vector>
#include "tinyxml2.cpp"
#include <iomanip>
using namespace std;
using namespace tinyxml2;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4996 )

int main(void)
{
    XMLDocument doc;
    const char* path = "./xml.xml";
    char amountText[100];
    // Load the XML file into the Doc instance
    doc.LoadFile(path);
    // Get root Element
    XMLElement* pRootElement = doc.RootElement();
    // Print out the Table Header
    cout << '|' << setw(7) << "Acc No." << '|' << setw(12) << "Account Type" << '|' << setw(15) << "Customer Name" << '|' << setw(10) << "Balance" << '|' << setw(12) << "Open Date" <<endl << endl;
    if (NULL != pRootElement) {
        //Get 'Accounts' Child
        XMLElement* pAccounts = pRootElement -> FirstChildElement("Accounts");
        if (NULL != pAccounts) {
            //Get 'Account' Child
            XMLElement* pAccount = pAccounts -> FirstChildElement("Account");
            while (pAccount) {
                // Get 'AccountNo' Child
                XMLElement* pAccountNo = pAccount -> FirstChildElement("AccountNo");
                if (NULL != pAccountNo) {
                    //Print out AccountNo
                    cout << '|' << setw(7) << pAccountNo -> GetText();
                }
                //Get 'type' Child
                XMLElement* pType = pAccount -> FirstChildElement("type");
                if (NULL != pType) {
                    // Print out 'Tyoe'
                    cout << '|' << setw(12) << pType -> GetText();
                }
                // Get 'customer' Child
                XMLElement* name = pAccount -> FirstChildElement("customer");
                if (NULL != name) {
                    //Print out name
                    cout << '|' << setw(15) << name -> GetText();
                }
                // Get 'balance' Child
                XMLElement* balance = pAccount -> FirstChildElement("balance");
                if (NULL != balance) {
                    // Convert to *char
                    strcpy(amountText, "$");
                    strcat(amountText, balance -> GetText());
                    //Print out amount
                    cout << '|' << setw(10) << amountText << '|';
                }
                // Get 'openDate' Child
                XMLElement* openDate = pAccount->FirstChildElement("openDate");//XMLElement * openDate = helper.GetFirstChildElement(pAccount, "openDate");
                if (NULL != openDate) {
                    //Print out openDate
                    cout << setw(12) << openDate -> GetText() << '|';
                }
                cout << endl;
                cout << "------------------------------------------------------------";
                std::cout << std::endl;
                // Next Account
                pAccount = pAccount -> NextSiblingElement("Account");
            }
            cout << "\n";
        }
    }


	return 0;
}

//https://dotblogs.com.tw/thkaw/2013/12/11/133462
//https://www.codingpanel.com/a-complete-guide-to-tinyxml-using-cpp/