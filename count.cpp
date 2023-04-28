#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    // 检查是否输入了足够的参数
    if (argc < 3) {
        cout << "Usage: wordCount.exe [-c/-w] [input_file]" << endl;
        return 1;
    }

    // 获取命令行参数
    string flag = argv[1];
    string filename = argv[2];

    // 打开输入文件
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cout << "Error: Failed to open file " << filename << endl;
        return 1;
    }

    string line;
    int count = 0;

    // 根据标志统计字符数或单词数
    if (flag == "-c") {
        // 统计字符数
        while (getline(input_file, line)) {
            count += line.length();
        }
        cout << "The file contains " << count << " characters." << endl;
    } else if (flag == "-w") {
        // 统计单词数
        while (getline(input_file, line)) {
            stringstream ss(line);
            string word;
            while (ss >> word) {
                count++;
            }
        }
        cout << "The file contains " << count << " words." << endl;
    } else {
        cout << "Usage: wordCount.exe [-c/-w] [input_file]" << endl;
        return 1;
    }

    // 关闭输入文件
    input_file.close();

    return 0;
}
