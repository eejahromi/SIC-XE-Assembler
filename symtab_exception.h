/*	Travis Barre, Ehsan Eshragh, Julius Inocencio, Michael Reese
	Spring 2014
*/

#ifndef SYMTAB_EXCEPTION_H
#define SYMTAB_EXCEPTION_H
#include <string>

using namespace std;

class symtab_exception {

public:
	symtab_exception(string s) {
		message = s;        
	}
        
	symtab_exception() {
		message = "An error has occurred";
	}
        
	string getMessage() {
		return message;
	}
    
private:
	string message;
};

#endif
