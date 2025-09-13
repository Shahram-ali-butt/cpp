#include <iostream>
#include <sstream>

int main(){
    std::cout << "********** Input sting stream ***********" << std::endl;
    std::string data = "47 128.42 Hello";
    std::istringstream iss(data);

    int x;
    double d;
    std::string word;

    iss >> x >> d >> word;

    std::cout << x << " " << d << " " << word << std::endl;

    // Step by step:

    // → We have a string that looks like "42 3.14 hello".
    // It has different types of data (int, double, string) separated by spaces.
    // istringstream iss → Create an input string stream from the string.
    // Now iss acts like cin, but instead of reading from the keyboard, it reads from the string "42 3.14 hello".

    // Extracts an int from the stream → stores 42 in i.
    // Extracts a double → stores 3.14 in d.
    // Extracts a string (until whitespace) → stores "hello" in word.

    std::cout << "********** Output sting stream ***********" << std::endl;
    
    std::ostringstream oss;
    oss << "Pi is about: " << 3.1415962;
    
    std::string result = oss.str();
    std::cout << result << std::endl;
    
    // Step by step:
    
    // ostringstream oss → Create an output string stream.
    // This works like cout, but instead of printing on the console, it collects the output inside a string.
    // Send text "Pi is about " into the stream. Then sends number 3.14159.
    // So the stream now holds "Pi is about 3.14159".
    
    // → oss.str() extracts the built-up contents as a normal string.
    
    std::cout << "********** Both I/O sting streams in one ***********" << std::endl;
    std::stringstream ss;  // can read and write

    // Write into the stream (like cout)
    ss << "100 " << 3.5 << " apple";

    // Now read back from the same stream (like cin)
    int num;
    double val;
    std::string word2;

    ss >> num >> val >> word;

    std::cout << "Number: " << num << std::endl;
    std::cout << "Value: " << val << std::endl;
    std::cout << "Word: " << word << std::endl;
    return 0;
}

