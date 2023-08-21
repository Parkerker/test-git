#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;*/


template<typename T>
void printVector(vector<T>& vec) {
    for (auto& i : vec) {
        cout << i << "; ";
    }
    cout << endl;
}

template<typename T>
void bubbleSort(vector<T>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec.at(j) > vec.at(j + 1))
                swap(vec.at(j), vec.at(j + 1));
        }
    }
}


int main()
{
    string filename("./test.txt");
    vector<int> numbers;
    int number;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file >> number) {
        numbers.push_back(number);
    }
    bubbleSort(numbers);
    printVector(numbers);

    for (const auto& i : numbers) {
        cout << i << ", ";
    }
    cout << endl;
    input_file.close();

    return 0;
}



/* 直接印出來
int main()
{
    string filename("E:\\test.txt");
    int number;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file >> number) {
        cout << number << "; ";
    }
    cout << endl;
    input_file.close();

    return EXIT_SUCCESS;
}

*/



/*#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    ifstream read;
    string file = "E:\\test.txt";//文件路徑
    read.open(file.data());
    assert(read.is_open());//如果打開文件失敗，則輸出錯誤消息，並終止運行
    read >> noskipws;//設置可以讀取空白符
    string str1, str2;
    char c;
    int cou = 0;//計數
    double sum = 0, temp;
    while (!read.eof())
    {
        read >> c;
        if (c == ' ' || c == '\n' || read.eof())
        {
            //字符串轉換爲數字
            stringstream s;
            s.str(str1);
            s >> temp;
            //求和
            sum += temp;
            //設爲0，防止文件末尾出現空行
            temp = 0;
            str1 = "";
        }
        else
        {
            cou++;//統計數字個數
            //將字符轉換爲字符串
            stringstream ss;
            ss << c;
            str2 = ss.str();
            str1 += str2;
        }
    }
    cout << "實數個數為：";
    cout << cou << endl;
    cout << "平均值為：";
    cout << sum / cou << endl;

    read.close();
}*/