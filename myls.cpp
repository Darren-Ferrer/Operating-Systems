/*
Pair Programming Equitable Participation & Honesty Affidavit
We the undersigned promise that we have in good faith attempted to follow the principles of pair programming. Although we were free to discuss ideas with others, the implementation is our own. We have shared a common workspace and taken turns at the keyboard for the majority of the work that we are submitting. Furthermore, any non programming portions of the assignment were done independently. We recognize that should this not be the case, we will be subject to penalties as outlined in the course syllabus.


Darren Ferrer
Pair Programmer 1

Ethan Ha
Pair Programmer 2
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<unistd.h>
#include<dirent.h>
#include<iostream>

#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

int hflag = 0;

void readDirs(char *dirString)
{
    DIR *dir;
    struct dirent *sd;
    struct stat s;

    //opens directory
    dir = opendir(dirString);

    // if -h, return back to main
    if (strcmp(dirString, "-h") == 0)
        return;
    // prints out current directory
    cout << "Directory: " <<dirString << endl;

    // if NULL then return to main
    if (dir == NULL)
    {
        cout << "Cannot access " << dirString << endl;
        return;
    }

    // if there is a "-h" in the arguments, print hidden files
    if (hflag == 1)
        {
            // while there is more to read, print the contents of directory
            while ( (sd = readdir(dir)) != NULL)
            {
                printf("%s\n", sd->d_name);
            }
        }

    // if there is not a "-h" in the arguments, print public files
    if (hflag != 1)
    {
        while ( (sd = readdir(dir)) != NULL)
        {
            // print non-hidden files
            if (sd->d_name[0] != '.')
            {
                printf("%s\n", sd->d_name);
            }
        }
    }
    // puts extra space between each directory call
    cout << "" << endl;
    // close the directory
    closedir(dir);
}

int main(int argc, char *argv[])
{
    // checks for a -h in the arguments
    for (int i = 0; i < argc; i++)
        {
            // sets a flag for -h
            if (strcmp(argv[i], "-h") == 0)
            {
                hflag = 1;
                //cout << "h flag is set" << endl;
            }
        }

        readDirs((char*)".");
        // ./myls
        for (int i = 1; i < argc; i++)
        {
            readDirs(argv[i]);
        }
        
    return(0);
}
