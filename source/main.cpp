#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    cout << "Hello from counseling app!\n";
    
    fstream fin;
    fin.open("/Users/kavehz98/Documents/GitHub/CS Club/spring2024-final/data/reportcard.csv", ios::in);

    int rollnum = 0;
    int roll2 = 0;
    int count = 0;

    cout << "Enter the roll number of the student to display details: ";
    cin >> rollnum;

    vector<string> row;

    string line;
    string word;

    while (getline(fin, line)) // Corrected to read the entire line
    {
        row.clear();
        stringstream s(line); // Use stringstream to parse the line

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        roll2 = stoi(row[0]);

        if (roll2 == rollnum)
        {
            count = 1;
            cout << "Details of Roll " << row[0] << " : \n"; 
            cout << "Name: " << row[1] << "\n"; 
            cout << "Score 1: " << row[2] << "\n"; 
            cout << "Score 2: " << row[3] << "\n"; 
            cout << "Score 3: " << row[4] << "\n"; 
            cout << "Score 4: " << row[5] << "\n"; 
            break;
        }
    }

    if (count == 0)
    {
        cout << "Record not found!" << endl;
    }

    return 0;
}
