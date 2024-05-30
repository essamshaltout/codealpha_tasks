#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cout<<"Hello Essam\n";
    int key = -1, encrypt = -1;

    do
    {
        cout<<"Type 1 if you want to encrypt, and 0 if you want to decrypt : ";
        cin>> encrypt;
    }   while(encrypt != 0 && encrypt != 1);

    do
    {
        cout<<"Enter key : ";
        cin>> key;
    }   while(key <= 0 || key > 25);

    // key = key % 


    if(encrypt  == 1)
    {
        ifstream plain_file; 
        plain_file.open("PLAIN_TEXT.txt"); 
        
        if (!plain_file.is_open()) 
        {
            cout<< "Unable to open file\n";
            return 1;
        }

        ostringstream ss;
        ss << plain_file.rdbuf();
        string plain_text = ss.str();
        plain_file.close();

        int size = plain_text.size();
        string encrypted_text = plain_text;
        for(int i = 0; i < size; i++)
        {
            if(plain_text[i] == ' ' || plain_text[i] == '\n')   continue;
            if(encrypted_text[i] > 'Z')
            {
                encrypted_text[i] = (plain_text[i] - 'a' + key) % 26 + 'a';
            }
            else
            {
                encrypted_text[i] = (plain_text[i] - 'A' + key) % 26 + 'A';
            }
        }

        ofstream encrypted_file;
        encrypted_file.open("ENCRYPTED_TEXT.txt");
        encrypted_file << encrypted_text << endl;
        encrypted_file.close();
        cout<<"Encrypted Successfully\n";
    }

    if(encrypt == 0)
    {
        ifstream encrypted_file; 
        encrypted_file.open("ENCRYPTED_TEXT.txt"); 
        
        if (!encrypted_file.is_open()) 
        {
            cout<< "Unable to open file\n";
            return 1;
        }

        ostringstream ss;
        ss << encrypted_file.rdbuf();
        string encrypted_text = ss.str();
        encrypted_file.close();

        int size = encrypted_text.size();
        string plain_text = encrypted_text;
        for(int i = 0; i < size; i++)
        {
            if(encrypted_text[i] == ' ' || encrypted_text[i] == '\n')   continue;
            if(encrypted_text[i] > 'Z')
            {

                plain_text[i] = encrypted_text[i] - 'a'  - key;   // 0 --- 25    , // - key, 25 - key
                if(plain_text[i] < 0)
                {
                    plain_text[i] = 26 + plain_text[i];
                }
                plain_text[i] += 'a';
            }
            else
            {
                plain_text[i] = encrypted_text[i] - 'A'  - key;   // 0 --- 25    , // - key, 25 - key
                if(plain_text[i] < 0)
                {
                    plain_text[i] = 26 + plain_text[i];
                }
                plain_text[i] += 'A';
            }


        }

        ofstream plain_file;
        plain_file.open("PLAIN_TEXT.txt");
        plain_file << plain_text << endl;
        plain_file.close();   
        cout<<"Decrypted Successfully\n";
    }

    return 0; 
}