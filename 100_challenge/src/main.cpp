#include<iostream>
#include<string>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;

int main()
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.!? ,0123456789"};
    
    string key {".90mnopqrstuvwxyz372DEFGHIJKLabcdefghijklMNOPQRSTUVWX=_ZY456ABC81!?"};

    cout << "================MESSAGE ENCRYPTOR==================" << endl;
    string message {};
    cout << "Enter the message that you want to encrypt: " << endl;
    getline(cin, message);

    string encrypted {};

    //Encryption
    cout << "========================================";
    cout << "\nEncrypting..........." << endl;
    for (size_t i {0}; i<message.length(); ++i)
    {
       size_t position = alphabet.find(message.at(i));
       if (position != string::npos)
       {
           encrypted += key.at(position);
       }
       else
       {
           encrypted += message.at(i);
       }
    }
    cout << "========================================";
    cout << "\nEncrypted message:\n" << encrypted << endl;

    //write to .txt file
    ofstream outfile;
    outfile.open("Encrypted.txt", ios::out);
    outfile << encrypted << endl;
    outfile.close();

    string decrypted {};

    //Decryption
    cout << "========================================";
    cout << "\nDecrypting..........." << endl;
    for (size_t i {0}; i<encrypted.length(); ++i)
    {
       size_t position = key.find(encrypted.at(i));
       if (position != string::npos)
       {
           decrypted += alphabet.at(position);
       }
       else
       {
           decrypted += encrypted.at(i);
       }
    }
    cout << "========================================";
    cout << "\nDecrypted message:\n" << decrypted << endl;

    return 0;
}
