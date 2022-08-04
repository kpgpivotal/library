#include "utils.hpp"


char get_input_char(string prompt){
    char input;
    bool valid_input{};

    do {
        cout << prompt << " : ";
        cin >> input;
        if ( isalpha(input) == 0 ) {
            valid_input = false;
            cout << "\nNon character input. Please enter valid character" << endl;
        }

        
    }
    while (valid_input == false);

    return  toupper(input);

}

char getCharValidInput(string prompt, char validValue1, char validValue2){
   char input;
   string str_input{};
    bool valid_input{};

    do {
        valid_input = false;
        cout << prompt << " : ";
        //cin >> input;
        getline(std::cin, str_input);
        input = str_input.at(0);
        if ( isalpha(input) == 0 ) {
            valid_input = false;
            cout << "\nNon character input. Please enter valid character" << endl;
        }
        else {
            input = toupper(input);
            if ( ( input ==  toupper(validValue1)) || (input ==  toupper(validValue2))){
                valid_input = true;
            }
            else {
                cout << "\nInvalid input. Please enter valid characters" << endl;
            }

        }

        
    }
    while (valid_input == false);

    return  input;
}


void showError(string errorMessage){
    cout << endl << "*** Error : " << errorMessage << endl;
}

void info(string infoMessage){
    cout << endl << "Info : " << infoMessage << endl;
}

void info(string infoMessage, int num) {
    cout << endl << "Info : " << infoMessage <<  " : " << num << endl;
}

int case_insensitive_match(string s1, string s2) {
   //convert s1 and s2 into lower case strings
   transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
   transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
   if(s1.compare(s2) == 0)
      return 1; //The strings are same
   return 0; //not matched
}

string capitalizeFirstLetter(string text) {

	for (int x = 0; x < text.length(); x++)
	{
		if (x == 0)
		{
			text[x] = toupper(text[x]);
		}
		else if (text[x - 1] == ' ')
		{
			text[x] = toupper(text[x]);
		}
	}

	return text;
}

void message(string message){
    cout <<  message << endl;
}


void print_line() {
    cout << "\n-----------------------------------------" << endl;
}


int read_numeric_input(){
    int num{};

    while (true)
    {
        cin >> num;
        if (!cin)
        {
            cout << "Invalid value. Enter again " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else  {
            cin.clear();
            break;
        }
    }

    return num;
}

int read_numeric_input(string message){
    int num{};

    while (true)
    {
        cin >> num;
        if (!cin)
        {
            cout << message << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else  {
            //cin.clear();
            break;
        }
    }

     
    return num;
}

string get_input_string(string prompt){
    string input{};

    cout <<  prompt << " : " ;
    std::getline(std::cin, input);
    
    return input;
}

string get_input_email(string prompt){
    string email{};
    int retry{0};

    while (retry++ < INPUT_RETRY_COUNT) {
        cout <<  prompt << " : " ;
        std::getline(std::cin, email);
        if ( is_valid_email(email) ) {
            break;
        }
        
        message("Invalid email. Please try again.");
    }

    if (INPUT_RETRY_COUNT == retry  ) {
        message("You have reached the limit of number of retires.");
        return "";
    }
        
    return email;
}

long get_input_long(string prompt){
    string input{};
    long long_val{};
  
    cout <<  prompt << " : " ;
    std::getline(std::cin, input);
    long_val = stol(input);

    return long_val;
}

int get_input_number(string prompt){
    string input{};
    int num_val{};
  
    cout <<  prompt << " : " ;
    std::getline(std::cin, input);
    num_val = stoi(input);

    return num_val;
}

bool is_starts_with(string theString, string prefix){

    std::for_each(theString.begin(), theString.end(), [](char & c) {
        c = ::tolower(c);
    });

    std::for_each(prefix.begin(), prefix.end(), [](char & c) {
        c = ::tolower(c);
    });

    //message(" String : " + theString);
    //message(" prefix : " + prefix);

    bool isPrefix = prefix.size() <= theString.size() &&
    std::mismatch(prefix.begin(), prefix.end(),
        theString.begin(), theString.end()).first == prefix.end();

    return isPrefix;
}

// Function to check the character
// is an alphabet or not
bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}
  
// Function to check the character
// is an digit or not
bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}
  
// Function to check email id is
// valid or not
bool is_valid_email(string email)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(email[0])) {
  
        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    int At = -1, Dot = -1;
  
    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;
         i < email.length(); i++) {
  
        // If the character is '@'
        if (email[i] == '@') {
  
            At = i;
        }
  
        // If character is '.'
        else if (email[i] == '.') {
  
            Dot = i;
        }
    }
  
    // If At or Dot is not present
    if (At == -1 || Dot == -1)
        return 0;
  
    // If Dot is present before At
    if (At > Dot)
        return 0;
  
    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
}




