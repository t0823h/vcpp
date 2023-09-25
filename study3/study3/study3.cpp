#include <cstdio>
#include <conio.h>
#include <chrono>
#include <thread>
#include <string>

int main() {
    const int intervalMs = 300; 
    std::string inputBuffer;  

    char key = 'a';
    while (key != 27) {
        if (_kbhit()) {
            key = _getch();
            inputBuffer += key;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));

        
        if (inputBuffer.find(80) != std::string::npos && inputBuffer.find(77) != std::string::npos && inputBuffer.find("a") != std::string::npos) {
            printf("아도겐! =o\n");
            inputBuffer.clear();  
        }
        else if (inputBuffer.find(75) != std::string::npos && inputBuffer.find(77) != std::string::npos && inputBuffer.find("s") != std::string::npos) {
            printf("왼쪽 오른쪽 S 패턴! =o\n");
            inputBuffer.clear();  
        }
        else if (inputBuffer.find(80) != std::string::npos && inputBuffer.find(72) != std::string::npos && inputBuffer.find("d") != std::string::npos) {
            printf("아래 위쪽 D 패턴! =o\n");
            inputBuffer.clear();  
        }
    }

    return 0;
}