#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

int main()
{
    printf("조상훈의 행복한 vc++\n");

    while (1) {
        printf("command>");
        std::string input;
        char command;

        while (1) {
            command = _getch();
            if (command == '\r') {
                break;
            }
            else if (command == 27) {
                printf("\ncommand>프로그램 종료\n");
                return 0;
            }
            input += command;
            printf("%c", command);
        }

        if (input == "q") {
            printf("\nqwer 화이팅\n");
        }
        else if (input == "w") {
            printf("\n과제 너무 좋다\n");
        }
        else if (input == "e") {
            printf("\n담주부턴 과제량 3배다\n");
        }
        else if (input == "r") {
            printf("\n행복합니다.\n");
        }
        else {
            printf("\n잘못된 입력입니다. 다시 시도해주세요.\n");
        }
    }
    return 0;
}