#include <iostream>
#include <filesystem>

using namespace std;

string getDirectories(string path) {
    string directories = "";
    int start = 0;
    for (int i = 0; i < path.length(); i++) {
        if (path[i] == '/') {
            directories += path.substr(start, (i + 1) - start);
            start = i + 1;
        }
    }
    return directories;
}

int main() {
    string path = "./dir/lol/./xd/../hi/state.txt";
    cout << getDirectories(path) << endl;
    if (filesystem::exists(getDirectories(path))) {
        cout << "Folder exists" << endl;
    } else {
        cout << "Folder does not exist" << endl;
    }
}