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
    const string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.!? ,0123456789"};
    
    const string key {".90mnopqrstuvwxyz372DEFGHIJKLabcdefghijklMNOPQRSTUVWX=_ZY456ABC81!?"};

    cout << "================MESSAGE ENCRYPTOR==================" << endl;
    string message {};

    //load input.txt file
    //http://www.martinbroadhurst.com/read-a-file-into-a-string-in-c.html
    //1. Open the file
    //2. Seek to the end and use tell to find out how big it is
    //3. Seek back to the beginning
    //4. Construct a string with the length + 1 and fill it with nul characters so it’s nul-terminated
    //5. Read the contents into the string’s buffer
    ifstream in_file ("input.txt");
    if (in_file.is_open()) 
    {
        in_file.seekg(0, ios::end);
        size_t len = in_file.tellg();
        in_file.seekg(0);
        string contents(len, '\0');
        in_file.read(&contents[0], len);
        message = contents;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

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
    cout << "\nEncrypted message:\n\n" << encrypted << endl;

    //write encrpyted.txt file
    ofstream out_file ("encrypted.txt");
    if (out_file.is_open())
    {
        out_file << encrypted << endl;
        out_file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

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
    cout << "\nDecrypted message:\n\n" << decrypted << endl;

    return 0;
}
