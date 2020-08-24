//reading file TriangleData.txt

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    ifstream myfile("TriangleData.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}
