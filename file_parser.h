/*	Travis Barre, Michael Reese, Ehsan Eshragh, Julius Inocencio
	Spring 2014
*/

#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include "file_parse_exception.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define MAX_LABEL_SIZE 8

using namespace std;

class file_parser {
	public:
		// ctor, filename is the parameter.  A driver program will read
		// the filename from the command line, and pass the filename to
		// the file_parser constructor.  Filenames must not be hard-coded.
		file_parser(string);

		// dtor
		~file_parser();
		
		// reads the source file, storing the information is some
		// auxiliary data structure you define in the private section. 
		// Throws a file_parse_exception if an error occurs.
		// if the source code file fails to conform to the above
		// specification, this is an error condition.     
		void read_file();    
		
		// returns the token found at (row, column).  Rows and columns
		// are zero based.  Returns the empty string "" if there is no 
		// token at that location. column refers to the four fields
		// identified above.
		string get_token(unsigned int, unsigned int);
		
		// prints the source code file to stdout.  Should not repeat 
		// the exact formatting of the original, but uses tabs to align
		// similar tokens in a column. The fields should match the 
		// order of token fields given above (label/opcode/operands/comments)
		void print_file();
		
		// returns the number of lines in the source code file
		int size();
		
	private:
		struct line {
			string label;
			string opcode;
			string operand;
			string comments;

			line() {
				label = "";
				opcode = "";
				operand = "";
				comments = "";
			}

			void put_word(string &w, int c, int i) {
				switch (c) {
					case 0:
						label = w.substr(0, MAX_LABEL_SIZE);
						break;
					case 1:
						opcode = w;
						break;
					case 2:
						operand = w;
						break;
					case 3:
						comments = w;
						break;
				}
				w.clear();
			}
		};

		string build_exception(string, int);
		bool build_comment(char*, line&,string&, unsigned int&, unsigned int);
		bool skip_quote(char*, bool, string&, bool&);	
		bool check_space(char*, line&, bool, bool, bool,string&, unsigned int&, unsigned int);
		vector<string> sourcelines;
		vector<line> tokens;	
};
#endif
