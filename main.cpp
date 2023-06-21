#include <windows.h> // SetConsoleCP
#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;

// Присутствует ли в пути расширение png
bool hasFileExtensionPNG(const std::string &pathName) {
    size_t position = pathName.find_last_of('.');

    if (position != std::string::npos)
        if (pathName.substr(position + 1) == "png")
            return true;

    return false;
}

// Существует ли в принципе, искомый файл
bool hasFileExist(const char* fileName) {
    bool isExist = false;
    std::ifstream fileReader;
    fileReader.open(fileName);
    if (fileReader.is_open() && !fileReader.bad()) isExist = true;
    fileReader.close();

    return isExist;
}

bool checkHeaderPNG(const char* fileName) {
    long long headerSize = 8 / 2;
    char buffer[headerSize];

    std::ifstream fileReader;
    fileReader.open(fileName, std::ios::binary);
    fileReader.read(buffer, headerSize);
    fileReader.close();

    return (((buffer[0] - 0) == -119) && ((buffer[1]) == 'P') && ((buffer[2]) == 'N') && ((buffer[3]) == 'G'));
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // const char* pathName = R"(..\136.png)";
    const char* pathName = R"(..\test.co.png)";
    // const char* pathName = R"(..\test.co.txt)";
    bool isExist = hasFileExist(pathName);

    if (!isExist) {
        cout << "Такого файла не существует. Попробуйте снова" << endl;
    }

    bool isFileExtensionPNG = hasFileExtensionPNG(pathName);

    if (!isFileExtensionPNG) {
        cout << "У файла должно быть расширение .png" << endl;
    }

    if (isExist && isFileExtensionPNG) {
        cout << checkHeaderPNG(pathName) << endl;
    }
}
