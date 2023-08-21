/*#define CURL_STATICLIB
#include <iostream>
#include <string>
#include "curl/curl.h"
using namespace std;

#ifdef _DEBUG
#pragma comment (lib,"curl/libcurl_a_debug.lib")
#else
#pragma comment (lib,"curl/libcurl_a.lib")
#endif

#pragma comment (lib,"Normaliz.lib")
#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Wldap32.lib")
#pragma comment (lib,"Crypt32.lib")
#pragma comment (lib,"advapi32.lib")

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.w3schools.com/xml/plant_catalog.xml");//http://www.google.com
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
    }
    return 0;
}
*/



#define CURL_STATICLIB
#include <iostream>
#include "curl/curl.h"
using namespace std;

#ifdef _DEBUG
#pragma comment (lib,"curl/libcurl_a_debug.lib")
#else
#pragma comment (lib,"curl/libcurl_a.lib")
#endif

#pragma comment (lib,"Normaliz.lib")
#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Wldap32.lib")
#pragma comment (lib,"Crypt32.lib")
#pragma comment (lib,"advapi32.lib")

// �^�I��ơA�Ω�B�z�����ƾ�
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t total_size = size * nmemb;
    std::string* output = static_cast<std::string*>(userp);
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

int main() {
    // ��l�� libcurl
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize libcurl." << std::endl;
        return 1;
    }

    // �]�m URL
    std::string url = "https://www.w3schools.com/xml/plant_catalog.xml";  // �бN URL ��������ڪ� API URL

    // �]�m�^�I��ƩM�^�I�ƾ�
    std::string response_data;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

    // ����ШD
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }
    else {
        std::cout << "Response data:\n" << response_data << std::endl;
    }

    // �M�z
    curl_easy_cleanup(curl);

    return 0;
}
