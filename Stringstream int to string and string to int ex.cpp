//number to string

int Number = 123;       // number to be converted to a string

string Result;          // string which will contain the result

ostringstream convert;   // stream used for the conversion

convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

Result = convert.str(); // set 'Result' to the contents of the stream

//string to number
string Text = "456"; // string containing the number

int Result;          //number which will contain the result

istringstream convert(Text); // stringstream used for the conversion constructed with the contents of 'Text' 
                             // ie: the stream will start containing the characters of 'Text'

if ( !(convert >> Result) ) //give the value to 'Result' using the characters in the stream
    Result = 0;             //if that fails set 'Result' to 0