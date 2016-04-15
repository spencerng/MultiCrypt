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

	// Flags for defensive programming in input
	ofn.Flags = OFN_FILEMUSTEXIST |OFN_HIDEREADONLY| OFN_PATHMUSTEXIST | OFN_EXTENSIONDIFFERENT;
	string newFile;
	
	do {
		printf("\tPlease select a text file.\n\n");

		// Shows the dialog
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

	// Automatically appended if not present
	ofn.lpstrDefExt = "txt";


	// Title of the dialog
	ofn.lpstrTitle = "Save text file";

	// Flag 
	ofn.Flags =  OFN_PATHMUSTEXIST | OFN_EXTENSIONDIFFERENT | OFN_NOREADONLYRETURN | OFN_OVERWRITEPROMPT;

	
	string newFile;
	do {
		printf("\tPlease save the output file: \n");

		// Shows the dialog
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

		// Flag detects if the extension is different from the default (*.txt)
		else if (ofn.Flags &OFN_EXTENSIONDIFFERENT)
			if (error("Please save file as a text file, with a .txt extension."))
				return std::to_string(ABORT);
		
	} while (newFile == "" || ofn.Flags&OFN_EXTENSIONDIFFERENT);
	return newFile;
}

bool isValidFile(string filePath) {
	// file to read from and verify
	ifstream file(filePath);

	// temp file to copy to without hash data
	ofstream temp("temp.txt");

	string line;
	string tempStr;
	string hash;

	while (getline(file, line)) {
		stringstream buffer(line);
		buffer >> tempStr;
		
		// Continues while the hash flag is not read in
		if(tempStr!="Hash:")
			temp << line << endl;
		else {
			// Stores the hash
			buffer >> hash;
			break;
		}
	}
	//temp.txt is a replica of the original file before hash flag
	string newHash = shaFile("temp.txt");

	// Deletes the temp file
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

	// File cannot be read or opened
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
	// Append keeps the existing data
	ofstream file(filePath, std::ios_base::app | std::ios_base::out);
	
	file << line << endl;

}

void getFileProperties(string filename, bool& hasPassword, string & key, string& message) {
	ifstream file(filename);
	string tempString;
	getline(file, tempString);

	// Defaults to yes since a user could modify and hash the file themselves
	if (tempString == "No")
		hasPassword = false;
	else hasPassword = true;
	
	// File is read line by line
	getline(file, key);
	getline(file, message);

}

