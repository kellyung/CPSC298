/// @file <Project_Authenticator.cpp>
/// @brief <Authentication mechanism to prove the identity of the sender of a message>
/// @author <kelung@chapman.edu>

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const char authenCharacter1 = 'E';
    const char authenCharacter2 = 'C';
    const char authenCharacter3 = 'A';
    char messCharacter1;
    char messCharacter2;
    char messCharacter3;
    const int validChecksum = 5;
    int messChecksum;
    
    // Part I: Entering and Displaying the Codes
    cout << "Enter the first character of the message code:" << endl;
    cin >> messCharacter1;
    cout << "Enter the second character of the message code:" << endl;
    cin >> messCharacter2;
    cout << "Enter the third character of the message code:" << endl;
    cin >> messCharacter3;
    cout << endl;
    
    std::string authenticatorCode;
    authenticatorCode += authenCharacter1;
    authenticatorCode += authenCharacter2;
    authenticatorCode += authenCharacter3;
    
    std::string messageCode;
    messageCode += messCharacter1;
    messageCode += messCharacter2;
    messageCode += messCharacter3;
    
    cout << "Authenticator Code: " << authenticatorCode << endl;
    cout << "Message Code: " << messageCode << endl << endl;
    
    // Part II: Reporting the Authenticity of the Code Using Character by Character Comparison
    if ((authenCharacter1 == messCharacter1) && (authenCharacter2 == messCharacter2) && authenCharacter3 == messCharacter3) {
        cout << "Message is authentic." << endl;
    }
    else {
        cout << "Message is invalid." << endl;
    }
    
    // Part III: Reporting the Authenticity of the Code Using String Comparison
    if (authenticatorCode == messageCode) {
        cout << "Concurrence: message is authentic." << endl;
    }
    else {
        cout << "Concurrence: message is invalid." << endl << endl;
    }
    
    // Part IV: Characterizing the Received Message Code
    cout << "Characterization of Message Code" << endl;
    cout << "--------------------------------" << endl;
    
    messChecksum = (int(messCharacter1) + int(messCharacter2) + int(messCharacter3)) % 7;
    
    if (messChecksum == validChecksum) {
        cout << "Message Code Checksum is valid: " << messChecksum << endl;
    }
    else {
        cout << "Message Code Checksum is invalid: " << messChecksum << ";" << " expected: " << validChecksum << endl;
    }
    
    cout << "ASCII Values of Message Code Characters: " << int(messCharacter1) << ", " << int(messCharacter2) << ", " << int(messCharacter3) << endl;
    cout << "Sum of ASCII values for Message Code Characters: " << int(messCharacter1) + int(messCharacter2) + int(messCharacter3) << endl;
    
    if (authenCharacter1 != messCharacter1) {
        cout << "First characters do not match: Message: " << messCharacter1 << "; Authenticator: " << authenCharacter1 << endl;
    }
    if (authenCharacter2 != messCharacter2) {
        cout << "Second characters do not match: Message: " << messCharacter2 << "; Authenticator: " << authenCharacter2 << endl;
    }
    if (authenCharacter3 != messCharacter3) {
        cout << "Third characters do not match: Message: " << messCharacter3 << "; Authenticator: " << authenCharacter3 << endl;
    }
    
    if (messageCode < authenticatorCode) {
        cout << "Message Code (" << messageCode << ") is lexicographically less than Authenticator code (" << authenticatorCode << ")" << endl;
    }
    if (messageCode > authenticatorCode) {
        cout << "Message Code (" << messageCode << ") is lexicographically greater than Authenticator code (" << authenticatorCode << ")" << endl;
    }
    return 0;
}
