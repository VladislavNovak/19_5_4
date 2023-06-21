#include <windows.h> // SetConsoleCP
#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

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

// Считывает первую половину заголовка. Если она соответствует правилам, то это файл PNG
bool checkHeaderPNG(const char* fileName) {
    long long headerSize = 8 / 2;
    char buffer[headerSize];

    std::ifstream fileReader;
    fileReader.open(fileName, std::ios::binary);
    fileReader.read(buffer, headerSize);
    fileReader.seekg(0, std::ios::beg);
    fileReader.close();

    return (((buffer[0] - 0) == -119) && ((buffer[1]) == 'P') && ((buffer[2]) == 'N') && ((buffer[3]) == 'G'));
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    vector<string> paths = { R"(..\136.pngX)", R"(..\test.co.png)", R"(..\test.co.txt)", R"(..\test)" };

    for (const string &pathName : paths) {
        bool isExist = hasFileExist(pathName.c_str());
        bool isFileExtensionPNG = hasFileExtensionPNG(pathName);

        if (isExist && isFileExtensionPNG) {
            bool isHeaderPNG = checkHeaderPNG(pathName.c_str());
            if (isHeaderPNG) {
                printf("Файл %s обнаружен в текущей директории и его можно открывать\n", pathName.c_str());
            } else {
                printf("Файл %s обнаружен, но с ним какие-то проблемы (неверный заголовок)\n", pathName.c_str());
            }
        }

        if (!isExist) {
            printf("Файл %s не обнаружен в текущей директории\n", pathName.c_str());
        }

        if (!isFileExtensionPNG) {
            printf("У файла %s должно быть расширение .png\n", pathName.c_str());
        }
    }

}
