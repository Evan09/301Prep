#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* Rules:
    >> : Ignores preceding spaces or ln, reads values until encounters space, leaves newline char

    getline(fh, myString): reads entire line and removes newline character
                           only for strings


*/

struct Person {
    String name;
    int age;
}

void readDataFromFile(string, vector<>);

int main() {
    string str, myString, misc;
    ifstream fh;
    int num;
    vector<int> myVector[];

    // includes whitespace and new lines
    while(fh >> str) {
        std::cout << str << std::cout << endl;
    }

    // doesn't include whitespace/new lines
    while (getline(fh, myString)) {
        std:: cout << myString << std::cout << endl;
    }

    /*
        example: in file - John Doe 
                           23 
                           Jane Marie Doe
                           30
    
    Need to use getline
    */

    while(getline(fh, myString)) {
        fh >> num; // reads in int, stops
        getline(fh, misc); // reads the new line and 
        fh >> num; // reads in int, stopsthrows it away into misc var, points to jane marie doe
    }
    fh.close();

    // vector search 
    for (unsigned i = 0; i < myList->size(); ++i) {
        if (myList->at[i].getID() == num) ; //get.ID() would belong to the object
    }

    // writing to a file is very similar to std::cout

    
    return 0;
}

void readDataFromFile(string myFile, vector<Part> *myList) {
    ifstream file (myFile.c_str());
    if (file >> numEntries) {
        for (unsigned i = 0; i < numEntries; ++i) {
            file >> id;          // receives object id
            getline(file, desc); // receives object description
            getline(file, desc); // gets newline
            myList(push_back(Part(id, desc)); // push back vector and add in the new object
        }
    }
    file.close();

}
