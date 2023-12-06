#include <bits/stdc++.h>
using namespace std;
string key = "HACK";
int keynumlist[4];

void setkeynumlist()
{
    string a = "ABCDEFGHJKLMNOPQRSTUVWXYZ";
    int id = 0;
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < key.length(); j++)
        {
            if (a[i] == key[j])
            {
                keynumlist[j] = id;
                id++;
            }
        }
    }

    // for(int i=0;i<key.length();i++)
    // {
    //         cout<<  keynumlist[i]<<" ";
    // }
    // cout<<endl;
}
void encrypt(string text)
{
    int col = key.length();
    int row = text.length() / key.length();
    if (text.length() % key.length())
        row += 1;

    // cout<<row<<" "<<col<<endl;
    char matrix[row][col];
    int ind = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (ind < text.length())
            {
                matrix[i][j] = text[ind++];
            }
            else
            {
                matrix[i][j] = '_';
            }
        }
    }

    // for(int i=0;i<row;i++)
    // {
    //     for(int j=0;j<col;j++)
    //     {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    string res = "";
    for (int i = 0; i < key.length(); i++)
    {
        int ii = keynumlist[i];
        for (int j = 0; j < row; j++)
        {
            if (matrix[j][ii] != '_')
                res += matrix[j][ii];
        }
    }

    cout << "Encrypted text: " << res << endl;
}
void decrypt(string text)
{
    int row = text.length() / key.length();
    if (text.length() % key.length())
    {
        row++;
    }
    int col = key.length();
    int rem = key.length() - (text.length() % key.length());

    int ind = 0;
    char matrix[row][col];
    for (int c = col - 1; c > 0, rem != 0; c--)
    {
        matrix[row - 1][c] = '_';
        rem--;
    }

    for (int i = 0; i < col; i++)
    {
        int ii = keynumlist[i];
        for (int j = 0; j < row; j++)
        {
            if (ind < text.length() && matrix[j][ii] != '_')
            {
                matrix[j][ii] = text[ind++];
            }
        }
    }

    string res = "";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != '_')
                res += matrix[i][j];
        }
    }

    cout << "Decrypt text: " << res << endl;
}
int main()
{
    int key, opt, p = 1;
    string text;
    setkeynumlist();

    while (p)
    {
        cout << "Enter 1.Encrypt 2.Decrypt 3.Exit" << endl;
        cin >> opt;
        if (opt == 3)
            break;
        cin.ignore();
        cout << "Enter text" << endl;
        getline(cin, text);
        cin.ignore();
        

        switch (opt)
        {
        case 1:
            encrypt(text);
            break;
        case 2:
            decrypt(text);
            break;
        default:
            p = 0;
            break;
        }
    }
}