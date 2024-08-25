#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/stat.h>
#include <cstdio>
#include <dirent.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

bool fileExists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

void listFilesAndDirectories() {
    system("ls");
}

void createNewFile(const string& filename, const string& extension) {
    string fullFilename = filename + extension;
    ofstream file(fullFilename);
    if (file.is_open()) {
        cout << "File Created Successfully" << endl;
    }
    file.close();
}

void deleteFile(const string& filename) {
    if (fileExists(filename)) {
        remove(filename.c_str());
        cout << "Successfully Deleted." << endl;
    } else {
        cout << "File Does not Exist..Try again" << endl;
    }
}

void renameFile(const string& oldName, const string& newName) {
    if (fileExists(oldName)) {
        rename(oldName.c_str(), newName.c_str());
        cout << "Successfully Renamed. Now Your File Exists with " << newName << " Name" << endl;
    } else {
        cout << oldName << " does not exist..Try again with correct filename." << endl;
    }
}

void editFileContent(const string& filename) {
    if (fileExists(filename)) {
        string command = "nano " + filename;
        system(command.c_str());
    } else {
        cout << filename << " File does not exist..Try again." << endl;
    }
}

void searchFile(const string& filename) {
    if (fileExists(filename)) {
        string command = "find /home -name " + filename;
        system(command.c_str());
    } else {
        cout << "File Does not Exist..Try again." << endl;
    }
}

void showFileDetails(const string& filename) {
    if (fileExists(filename)) {
        string command = "stat " + filename;
        system(command.c_str());
    } else {
        cout << filename << " File does not exist..Try again." << endl;
    }
}

void viewFileContent(const string& filename) {
    if (fileExists(filename)) {
        string command = "cat " + filename;
        system(command.c_str());
    } else {
        cout << filename << " does not exist" << endl;
    }
}

void sortFileContent(const string& filename) {
    if (fileExists(filename)) {
        string command = "sort " + filename;
        system(command.c_str());
    } else {
        cout << filename << " File does not exist..Try again." << endl;
    }
}

void listDirectories() {
    system("ls -d */");
}

void listFilesWithExtension(const string& extension) {
    string command = "ls *." + extension;
    system(command.c_str());
}

void totalDirectories() {
    system("echo */ | wc -w");
}

void totalFiles() {
    system("ls -l | grep -v 'total' | grep -v '^d' | wc -l");
}

void sortFiles() {
    system("ls | sort");
}

int process() {
    int i = 0;
    while (i < 100) {
        // Compile and run the C++ source file
        system("g++ trial2.cpp -o proj && ./proj");

        cout << "Enter your choice: ";
        int opt1;
        cin >> opt1;

        switch (opt1) {
            case 1:
                cout << "List all files and Directories here.." << endl;
                cout << "Showing all files and directories...." << endl;
                sleep(3);
                cout << "Loading.." << endl;
                sleep(3);
                cout << "-------------------------------OutPut-------------------------------" << endl;
                listFilesAndDirectories();
                cout << " " << endl;
                break;
            case 2: {
                cout << "Create New Files here.." << endl;
                cout << "Which type of file you want to create!" << endl;
                cout << "1- .c\n2- .sh\n3- .txt\nEnter your choice from 1-3" << endl;
                int filechoice;
                cin >> filechoice;
                string filename;
                switch (filechoice) {
                    case 1:
                        cout << "Enter File Name without .c Extension" << endl;
                        cin >> filename;
                        createNewFile(filename, ".c");
                        break;
                    case 2:
                        cout << "Enter File Name without .sh Extension" << endl;
                        cin >> filename;
                        createNewFile(filename, ".sh");
                        break;
                    case 3:
                        cout << "Enter File Name without .txt Extension" << endl;
                        cin >> filename;
                        createNewFile(filename, ".txt");
                        break;
                    default:
                        cout << "Invalid Input..Try Again." << endl;
                        break;
                }
                cout << "-------------------------------OutPut-------------------------------" << endl;
                cout << "File Created Successfully" << endl;
                cout << " " << endl;
                break;
            }
            case 3: {
                cout << "Delete existing files here.." << endl;
                cout << "Enter name of File you want to Delete!" << endl;
                cout << "Note: Please Enter full Name with Extension." << endl;
                string delfile;
                cin >> delfile;
                cout << "-------------------------------OutPut-------------------------------" << endl;
                deleteFile(delfile);
                cout << " " << endl;
                break;
            }
            case 4: {
                cout << "Rename files here.." << endl;
                cout << "Enter Old Name of File with Extension.." << endl;
                string oldName, newName;
                cin >> oldName;
                cout << "Checking for file..." << endl;
                sleep(3);
                renameFile(oldName, newName);
                cout << " " << endl;
                break;
            }
            case 5: {
                cout << "Edit file content here.." << endl;
                cout << "Enter File Name with Extension: " << endl;
                string edit;
                cin >> edit;
                cout << "-------------------------------OutPut-------------------------------" << endl;
                cout << "Checking for file.." << endl;
                sleep(3);
                editFileContent(edit);
                cout << " " << endl;
                break;
            }
            case 6: {
                cout << "Search files here.." << endl;
                cout << "Enter File Name with Extension to search" << endl;
                string f;
                cin >> f;
                cout << "-------------------------------OutPut-------------------------------" << endl;
                searchFile(f);
                cout << " " << endl;
                break;
            }
            case 7: {
                cout << "Detail of file here.." << endl;
                cout << "Enter File Name with Extension to see Detail: " << endl;
                string detail;
                cin >> detail;
                cout << "-------------------------------OutPut-------------------------------" << endl;
                cout << "Checking for file.." << endl;
                sleep(4);
                showFileDetails(detail);
                cout << " " << endl;
                break;
            }
            case 8: {
                cout << "View content of file here.." << endl;
                cout << "Enter File Name: " << endl;
                string readfile;
                cin >> readfile;
                cout << "-------------------------------OutPut-------------------------------" << endl;
                viewFileContent(readfile);
                cout << " " << endl;
                break;
            }
            case 9: {
                cout << "Sort file content here.." << endl;
                cout << "Enter File Name with Extension to sort: " << endl;
                string sortfile;
                cin >> sortfile;
                cout << "-------------------------------OutPut-------------------------------" << endl;
                sortFileContent(sortfile);
                cout << " " << endl;
                break;
            }
            case 10:
                cout << "List of all Directories here.." << endl;
                cout << "Showing all Directories..." << endl;
                cout << "Loading.." << endl;
                sleep(3);
                listDirectories();
                cout << " " << endl;
                break;
            case 11: {
                cout << "List of Files with Particular extensions here.." << endl;
                cout << "Which type of file list you want to see?" << endl;
                cout << "1- .c\n2- .sh\n3- .txt\nEnter your choice from 1-3" << endl;
                int extopt;
                cin >> extopt;
                cout << "-------------------------------OutPut-------------------------------" << endl;
                switch (extopt) {
                    case 1:
                        listFilesWithExtension("c");
                        break;
                    case 2:
                        listFilesWithExtension("sh");
                        break;
                    case 3:
                        listFilesWithExtension("txt");
                        break;
                    default:
                        cout << "Invalid Input..Try again.." << endl;
                        break;
                }
                cout << " " << endl;
                break;
            }
            case 12:
                cout << "Total number of Directories here.." << endl;
                cout << "Loading all directories.." << endl;
                sleep(3);
                totalDirectories();
                cout << " " << endl;
                break;
            case 13:
                cout << "Total Numbers of Files in Current Directory here.." << endl;
                cout << "Loading all files.." << endl;
                sleep(3);
                totalFiles();
                cout << " " << endl;
                break;
            case 14:
                cout << "Sort all files in Ascending Order here.." << endl;
                cout << "Sorting Files..." << endl;
                sleep(3);
                sortFiles();
                cout << " " << endl;
                break;
            case 15:
                cout << "Press 15 to Quit" << endl;
                exit(0);
            default:
                cout << "Invalid Input..Please Try Again" << endl;
                break;
        }
    }
    return 0;
}
