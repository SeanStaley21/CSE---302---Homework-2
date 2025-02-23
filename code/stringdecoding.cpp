#include <iostream>
#include <string>
#include "StackType.h" 
#include "QueType.h"  

std::string decode(std::string exp, std::string code) {
    std::string result = "";  // To store the final decoded string
    StackType<char> stack(exp.length());  // Create a stack for code characters

    // Iterate through each character in exp
    for (size_t i = 0; i < exp.length(); ++i) {
        char currentChar = exp.at(i);

        // Check if current character is in the 'code' string
        if (code.find(currentChar) != std::string::npos) {
            stack.Push(currentChar);  // Push to stack if it's in code
        } else {
            result += currentChar;  // Append directly to result if not in code
        }
    }

    // Pop from stack and append in reverse order
    while (!stack.IsEmpty()) {
        result += stack.Pop();
    }

    return result;  // Return the decoded string
}

int main() {
    std::string inputLine, exp, code;

    std::cout << "Enter the decode function call (e.g. decode(\"exp\", \"code\")):" << std::endl;
    std::getline(std::cin, inputLine);

    // Extract exp and code from the input string
    size_t startExp = inputLine.find("\"") + 1;
    size_t endExp = inputLine.find("\"", startExp);
    size_t startCode = inputLine.find("\"", endExp + 1) + 1;
    size_t endCode = inputLine.find("\"", startCode);

    exp = inputLine.substr(startExp, endExp - startExp);
    code = inputLine.substr(startCode, endCode - startCode);

    // Decode and print the result
    std::string decodedString = decode(exp, code);
    std::cout << "Decoded string: " << decodedString << std::endl;

    return 0;
}
