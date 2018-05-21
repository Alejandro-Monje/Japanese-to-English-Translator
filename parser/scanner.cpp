#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: 8
//=====================================================

// ** MYTOKEN DFA to be replaced by the WORD DFA
// ** Done by: Stefan Retief
// ** RE:
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
        else if (state == 5 && (s[charpos] == 's'))
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


// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, etc.
enum tokentype {
    ERROR,
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

// ** string tokenName[30] = { }; for the display names of tokens

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

// ** Need the reservedwords table to be set up here. English will be
// ** used in Part C but it should be stored now.
// ** Do not require any file input for this.
// ** a.out should work without any additional files.

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

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// ** Done by:
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



// The temporary test driver to just call the scanner repeatedly
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!!
// Done by:  Rika
int main() {
    tokentype thetype;
    string theword;
    string filename;


    cout << "Enter the input file name: ";
    cin >> filename;

    fin.open(filename.c_str());

    while (scanner(thetype, theword)) {
        // call the scanner

        cout << "Type is:" << tokenName[thetype] << endl;
        cout << "Word is:" << theword << endl << endl;

    }

    fin.close();

}// end
