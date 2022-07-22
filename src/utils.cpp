#include "utils.hpp"


char get_input(string prompt){
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
    bool valid_input{};

    do {
        valid_input = false;
        cout << prompt << " : ";
        cin >> input;
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
            cin.clear();
            break;
        }
    }

    return num;
}


void log_info(string the_info){
    BOOST_LOG_TRIVIAL(info) << the_info;
}


