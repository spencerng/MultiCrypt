#include "Headers/FileIO.h"


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
	ofn.lpstrDefExt = "*.txt";
	

	// Title of the dialog
	ofn.lpstrTitle = "Select file to open";


	ofn.Flags = OFN_FILEMUSTEXIST |OFN_HIDEREADONLY| OFN_PATHMUSTEXIST | OFN_EXTENSIONDIFFERENT;
	string newFile;
	// Shows the dialog
	do {
		printf("\tPlease select a text file.\n\n");
		GetOpenFileName(&ofn);

		// Removes null characters from filename
		newFile = "";
		for (int i = 0; i < filename.size(); i++) {
			if (filename[i] != '\0')
				newFile += filename[i];
		}
		if (newFile == "")
			if (error("Window closed without selecting a file. Please try again."))
				return std::to_string(ABORT);
	} while (newFile == "");
	return newFile;
	
}

// Deprecated by saveFile
string selectFolder() {
	BROWSEINFO bi = { 0 };
	TCHAR path[MAX_PATH];
	WCHAR userPath[MAX_PATH];
	SHGetFolderPathW(NULL, CSIDL_PROFILE, NULL, 0, userPath);
	
	bi.lpszTitle = "Select folder to save to\0";
	bi.ulFlags = BIF_EDITBOX | BIF_NEWDIALOGSTYLE | BIF_RETURNONLYFSDIRS | BIF_VALIDATE ;
	
	LPITEMIDLIST p = SHBrowseForFolder(&bi);
	SHGetPathFromIDList(p, path);
	
	
	return path;
}

string saveFile() {
	
	// Buffer string where the filename user selection is stored
	string filename(MAX_PATH, '\0');

	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);

	// Filter for text files and all files
	ofn.lpstrFilter = "Text File\0*.txt\0All Files\0*.*\0\0";

	// Where to put the filename the user selects
	ofn.lpstrFile = LPSTR(filename.c_str());
	ofn.nMaxFile = filename.size();
	ofn.lpstrDefExt = "txt";


	// Title of the dialog
	ofn.lpstrTitle = "Save text file";


	ofn.Flags =  OFN_PATHMUSTEXIST | OFN_EXTENSIONDIFFERENT | OFN_NOREADONLYRETURN | OFN_OVERWRITEPROMPT;

	// Shows the dialog
	string newFile;
	do {
		printf("\tPlease save the output file: \n");
		GetSaveFileName(&ofn);
					
		// Removes null characters from filename
		newFile = "";
		for (int i = 0; i < filename.size(); i++) 
			if (filename[i] != '\0')
				newFile += filename[i];
		
		if (newFile == "") {
			if (error("Windows closed without saving a file. Please try again."))
				return std::to_string(ABORT);
		}
		else if (ofn.Flags &OFN_EXTENSIONDIFFERENT)
			if (error("Please save file as a text file, with a .txt extension."))
				return std::to_string(ABORT);
		
	} while (newFile == "" || ofn.Flags&OFN_EXTENSIONDIFFERENT);
	return newFile;
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

bool fileExists(string fileName)
{
	ifstream in_stream;
	in_stream.open(fileName);
	if (in_stream.fail())
		return false;
	else
		return true;
}

void createFile(string fileName)
{
	ofstream out_stream;
	out_stream.open(fileName);
	out_stream.close();
}

void addHash(string filePath) {
	
	string hash = shaFile(filePath);
	outputLine(filePath, "Hash: " + hash);

}

void outputLine(string filePath, string line) {
	ofstream file(filePath, std::ios_base::app | std::ios_base::out);
	
	file << line << endl;

}

void getFileProperties(string filename, bool& hasPassword, string & key, string& message) {
	ifstream file(filename);
	string tempString;
	getline(file, tempString);
	if (tempString == "Yes")
		hasPassword = true;
	else hasPassword = false;
	getline(file, key);
	getline(file, message);

}

