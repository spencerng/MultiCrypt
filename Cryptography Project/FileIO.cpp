#include "Headers/FileIO.h"
#include<Windows.h>
#include<ShlObj.h>

string selectFile() {

	// Buffer string where the filename user selection is stored
	string filename(MAX_PATH, '\0');

	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);

	// Filter for text files and all files
	ofn.lpstrFilter = "Text Files\0*.txt\0All Files\0*.*\0\0";

	// Where to put the filename the user selects
	ofn.lpstrFile = LPSTR(filename.c_str());
	ofn.nMaxFile = filename.size();

	// Folder to start in
	

	// Title of the dialog
	ofn.lpstrTitle = "Select file to open";


	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

	// Shows the dialog
	GetOpenFileName(&ofn);

	// Removes null characters from filename
	string newFile = "";
	for (int i = 0; i < filename.size(); i++) {
		if (filename[i] != '\0')
			newFile += filename[i];
	}

	return newFile;
}

string selectFolder() {
	BROWSEINFO bi = { 0 };
	TCHAR path[MAX_PATH];
	
	bi.lpszTitle = "Select folder to save to\0";
	bi.ulFlags = BIF_EDITBOX | BIF_VALIDATE | BIF_USENEWUI;
	
	LPITEMIDLIST p = SHBrowseForFolder(&bi);
	SHGetPathFromIDList(p, path);
	string pa = path;
	
	return path;
}

bool isValidFile(string filePath) {
	// file to read from and verify
	ifstream file(filePath);

	// temp file to copy to, without hash data
	ofstream temp("temp.txt");

	string line;
	string tempStr;
	string hash;

	while (getline(file, line)) {
		stringstream buffer(line);
		buffer >> tempStr;
		
		if(tempStr!="Hash:")
			temp << line << endl;
		else {
			buffer >> hash;
			break;
		}
	}
	string newHash = shaFile("temp.txt");
	temp.close();
	if(remove("./temp.txt")!=0)
		perror("Not deleted");
	if (hash.length() != 0)
		if (newHash == hash)
			return 1;

	return 0;

}

void addHash(string filePath) {
	
	ofstream file(filePath, ios_base::app | ios_base::out);
	file << endl;
	string hash = shaFile(filePath);
	file  << "Hash: " << hash;

}

