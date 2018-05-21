#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=================================================                                                                                                                                 
// File parser.cpp written by Group Number: 8                                    
//=================================================  
enum tokentype{ ERROR,
		WORD1,
		WORD2,
		PERIOD,
		VERB,
		VERBPAST,
		VERBNEG,
		VERBPASTNEG,
		IS,
		WAS,
		OBJECT,
		SUBJECT,
		DESTINATION,
		PRONOUN,
		CONNECTOR,
		EOFM
};


string reservedWords[30][2] = {
  {"masu",         ""},
  {"masen",        ""},
  {"mashita",      ""},
  {"masendeshita", ""},
  {"desu",         ""},
  {"deshita",      ""},
  {"o",            ""},
  {"wa",           ""},
  {"ni",           ""},
  {"watashi",      "I/me"},
  {"anata",        "you"},
  {"kare",         "he/him"},
  {"kanojo",       "she/her"},
  {"sore",         "it"},
  {"mata",         "Also"},
  {"soshite",      "Then"},
  {"shikashi",     "However"},
  {"dakara",       "Therefore"},
  {"eofm",         ""}  
};


tokentype reservedWordsType[30] = {
  VERB,
  VERBNEG,
  VERBPAST,
  VERBPASTNEG,
  IS,
  WAS,
  OBJECT,
  SUBJECT,
  DESTINATION,
  PRONOUN,
  PRONOUN,
  PRONOUN,
  PRONOUN,
  PRONOUN,
  CONNECTOR,
  CONNECTOR,
  CONNECTOR,
  CONNECTOR,
  EOFM
};


string tokenName[30] = {
  "ERROR",
  "WORD1",
  "WORD2",
  "PERIOD",
  "VERB",
  "VERBPAST",
  "VERBNEG",
  "VERBPASTNEG",
  "IS",
  "WAS",
  "OBJECT",
  "SUBJECT",
  "DESTINATION",
  "PRONOUN",
  "CONNECTOR",
        "EOFM"
};

tokentype next_token();
bool word(string s);
bool period(string s);
int scanner(tokentype &a, string &w);
bool match(tokentype expected);
void Story();
void S();
void AfterSubject();
void AfterNoun();
void AfterObject();
void Noun();
void Verb();
void Be();
void Tense();
void Syntax_Error1(tokentype);
void Syntax_Error2(string);
tokentype  saved_token;     // global buffer for the scanner token
bool   token_available;          // global flag indicating whether
string lexeme;
// we have saved a token to eat up or not
// ** Be sure to put the name of the programmer above each function
// i.e. Done by:

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)

// ** Need the updated match and next_token (with 2 global vars)


ifstream fin;


// The test driver to start the parser
// Done by:  **
int main()
{
  
  //- opens the input file
  tokentype thetype;
  string theword;
  string filename;
  
  cout << "Enter the input file name: ";
  cin >> filename;
 
  fin.open(filename.c_str());
  //- calls the <story> to start parsing
  Story();
  //- closes the input file 
  fin.close();
  return 0;
}// end
//** should require no other input files!

// ** Be sure to put the name of the programmer above each function                                                                                                                
// i.e. Done by:                                                                                                                                                                   
// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)                                                                                                             
// ** Need the updated match and next_token (with 2 global vars)                                                                                                                   

tokentype next_token()
{  
  if (!token_available)   // if there is no saved token from previous lookahead                                                                                                    
    {
      scanner(saved_token, lexeme);  // call scanner to grab a new token                                                                 
      cout << "Scanner called using word: " << lexeme << endl;
      token_available = true;  // mark that fact that you have saved it                                                                                           
    }
  return saved_token;    // return the saved token                                                                                                                                 
}

// i.e. Done by:Antonio Monje                                                                                                                                                      
bool match(tokentype expected)
{
 
  if (next_token() != expected)  // mismatch has occurred with the next token                                                                                                      
    {
      Syntax_Error1(expected); // generate a syntax error message here                                                                                                                   
      scanner(saved_token, lexeme);
      match(saved_token);
      // do error handling here if any                                                                                                                                             
    }
  else  // match has occurred                                                                                                                                                      
    {
      token_available = false;  // eat up the token                                                                                                                               
      return true;              // say there was a match                                                                                                                           
    }
}

// ** Make each non-terminal into a function here                                                                                                

// i.e. Done by:Antonio Monje                                                                                                                   
void Story()
{
  cout << "Processing <Story> " << endl;
  cout << endl;
  S();
  while(next_token() != EOFM)
    {
      switch(next_token())
        {
        case CONNECTOR:
        case WORD1:
        case PRONOUN: S();
          break;
        default: return;
        }
    }
}

// i.e. Done by:Antonio Monje                                                                                                                  
void S()
{
  cout << "Processing <S>" << endl;
  if(next_token() == CONNECTOR)
    {
    match(CONNECTOR);
    cout << "Matched CONNECTOR" << endl;
    }
  Noun();
  match(SUBJECT);
  cout << "Matched SUBJECT" << endl;
  AfterSubject();
}

// i.e. Done by:Antonio Monje                                                                                                                   
void AfterSubject()
{
  cout << "Processing <After-Subject>" << endl;
  switch(next_token())
    {
    case WORD2: Verb(); Tense(); match(PERIOD); cout << "Matched PERIOD" << endl;
      break;
    case WORD1: Noun(); AfterNoun();
      break;
    case PRONOUN: Noun(); AfterNoun();
      break;
    default: Syntax_Error2("<After-Subject");
    }
}

// i.e. Done by:Antonio Monje                                                                                                                   
void AfterNoun()
{
  cout << "Processing <After-Noun>" << endl;
  switch (next_token())
    {
    case IS :
    case WAS : Be(); match(PERIOD); cout << "Matched PERIOD" << endl; 
      break;
    case DESTINATION : match(DESTINATION); cout << "Matched DESTINATION" << endl; Verb(); Tense(); match(PERIOD); cout << "Matched PERIOD" << endl; 
      break;
    case OBJECT : match(OBJECT); cout << "Matched OBJECT" << endl; AfterObject(); 
      break;
    default : Syntax_Error2("After-Noun");
    }
}

// i.e. Done by:Antonio Monje                                                                                                                  
void AfterObject()
{
  cout << "Processing <After-Object>" << endl;
  switch(next_token())
    {
    case WORD2: Verb(); Tense(); match(PERIOD); cout << "Matched PERIOD" << endl;
      break;
    case WORD1:
    case PRONOUN: Noun(); match(DESTINATION); cout << "Matched DESTINATION" << endl; Verb(); Tense(); match(PERIOD); cout << "Matched PERIOD" << endl; 
      break;
    default: Syntax_Error2("After-Object");
    }
  
}


// i.e. Done by:Antonio Monje                                                                                                       
void Noun()
{
  cout << "Processing <Noun>" << endl;
  switch(next_token())
    {
    case WORD1: match(WORD1); cout << "Matched WORD1" << endl;
      break;
    case PRONOUN: match(PRONOUN); cout << "Matched PRONOUN" << endl;
      break;
    default: Syntax_Error2("Noun");
    }
}

// i.e. Done by:Antonio Monje                                                                                                                    
void Verb()
{
  cout << "Processing <Verb>" << endl;
  match(WORD2);
  cout << "Matched WORD2" << endl;
}

// i.e. Done by:Antonio Monje                                                                                                                   
void Be()
{
  cout << "Processing <Be>" << endl;
  switch(next_token())
    {
    case IS: match(IS); cout << "Matched IS" << endl;
      break;
    case WAS: match(WAS); cout << "Matched WAS" << endl;
      break;
    default: Syntax_Error2("BE");
    }
  
}

// i.e. Done by:Antonio Monje                                                                                                                    
void Tense()
{
  cout << "Processing <Tense>" << endl;
  switch(next_token())
    {
    case VERBPAST: match(VERBPAST); cout << "Matched VERBPAST" << endl;
      break;
    case VERBPASTNEG: match(VERBPASTNEG); cout << "Matched VERBPASTNEG" << endl;
      break;
    case VERB: match(VERB); cout << "Matched VERB" << endl;
      break;
    case VERBNEG: match(VERBNEG); cout << "Matched VERBNEG" << endl;
      break;
    default: Syntax_Error2("TENSE");
    }
}
// ** Be sure to put the corresponding grammar rule above each function                                                                                                             

void Syntax_Error1(tokentype thetoken)
{
  cout << "LEXICAL ERROR: " << thetoken << " but found " << endl;
}

void Syntax_Error2(string saved_lexeme)
{
  cout << "SYNTAX ERROR: unexpected " << saved_lexeme << " found in parser function" << endl;
}

///////////////////////////Scanner-Functions///////////////////////////////
///////////////////////////
////////////////
/////////
/////
//
//

bool word(string s) {
  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0') {

    /************************/
    /*    State 0 block     */
    /************************/
    if (state == 0 &&
	(s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
	 s[charpos] == 'u'))
      state = 1;
    else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' ||
			    s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
      state = 2;
    else if (state == 0 && (s[charpos] == 'c'))
      state = 3;
    else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' ||
			    s[charpos] == 'z'))
      state = 4;
    else if (state == 0 && (s[charpos] == 's'))
      state = 5;
    else if (state == 0 && (s[charpos] == 't'))
      state = 6;

    /************************/
    /*    State 1 block     */
    /************************/
    else if (state == 1 &&
	     (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
	      s[charpos] == 'u'))
      state = 1;
    else if (state == 1 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' ||
			    s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r'))
      state = 2;
    else if (state == 1 && (s[charpos] == 'c'))
      state = 3;
    else if (state == 1 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' ||
			    s[charpos] == 'z'))
      state = 4;
    else if (state == 1 && (s[charpos] == 's'))
      state = 5;
    else if (state == 1 && (s[charpos] == 't'))
      state = 6;
    else if (state == 1 && (s[charpos] == 'n'))
      state = 7;

    /************************/
    /*    State 2 block     */
    /************************/
    else if (state == 2 && (s[charpos] == 'y'))
      state = 4;
    else if (state == 2 &&
	     (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
	      s[charpos] == 'u'))
      state = 1;

    /************************/
    /*    State 3 block     */
    /************************/
    else if (state == 3 && (s[charpos] == 'h'))
      state = 4;

    /************************/
    /*    State 4 block     */
    /************************/
    else if (state == 4 &&
	     (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
	      s[charpos] == 'u'))
      state = 1;

    /************************/
    /*    State 5 block     */
    /************************/
    else if (state == 5 &&
	     (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
	      s[charpos] == 'u'))
      state = 1;
    else if (state == 5 && (s[charpos] == 'h'))
      state = 4;

    /************************/
    /*    State 6 block     */
    /************************/
    else if (state == 6 &&
	     (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
	      s[charpos] == 'u'))
      state = 1;
    else if (state == 6 && (s[charpos] == 's'))
      state = 5;

    /************************/
    /*    State 7 block     */
    /************************/
    else if (state == 7 &&
	     (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
	      s[charpos] == 'u'))
      state = 1;
    else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' ||
			    s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
      state = 2;
    else if (state == 7 && (s[charpos] == 'c'))
      state = 3;
    else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' ||
			    s[charpos] == 'z'))
      state = 4;
    else if (state == 7 && (s[charpos] == 's'))
      state = 5;
    else if (state == 7 && (s[charpos] == 't'))
      state = 6;
    else
      return (false);
    charpos++;
  }//end of while

  // where did I end up????
  if (state == 1 || state == 7) return (true);  // end in a final state
  else return (false);
}

// ** Add the PERIOD DFA here
// ** Done by:

bool period(string s) {
  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0') {
    if (state == 0 && (s[charpos] == '.'))
      state = 1;
    else
      return (false);
    charpos++;
  }

  if (state == 1) return (true);
  else return (false);
}

int scanner(tokentype &a, string &w) {

  // ** Grab the next word from the file via fin
  bool reserved = false;

  fin >> w;
  if (w == "eofm")
    return 0;
  if (period(w))
    a = PERIOD;
  else if (word(w)) {
    for (int i = 0; i < 30; i++) {
      if (w == reservedWords[i][0]) {
	a = reservedWordsType[i];
	reserved = true;
	break;
      }
    }
    if (!reserved) {
      if (w[w.length() - 1] == 'I' || w[w.length() - 1] == 'E')
	a = WORD2;
      else
	a = WORD1;
    }
  } else a = ERROR;
  return 1;

  /*
    2. Call the token functions one after another (if-then-else)
       And generate a lexical error message if both DFAs failed.
       Let the token_type be ERROR in that case.
    3. Make sure WORDs are checked against the reservedwords list
						      If not reserved, token_type is WORD1 or WORD2.
						      4. Return the token type & string  (pass by reference)
    */

}//the end

