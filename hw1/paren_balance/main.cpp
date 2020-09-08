#include <iostream>
#include <string>

using namespace std;

// Implement below
bool are_paren_balanced(const string& expression);

// We have suggested a helper method, but feel free to write whatever you see fit
//bool are_paren_balanced(const string& expression, size_t& i, char expected_closing);
bool are_paren_balanced(const string& expression, int& i, int& start_p, int& end_p, int& start_b, int& end_b);

// Do not change this method
int main(int argc, char* argv[]) {

    // Check if an expression has been passed to the program
    if (argc != 2) {
        cerr << "error: expected expression to check!" << endl;
        return -1;
    }

    // The second argument is the expression string in the format specified and
    // promised in the assignment page. You do not need to do any error checking
    // except for checking the parentheses.
    string expression(argv[1]);
    if (are_paren_balanced(expression)) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }

    return 0;
}

// Some notes:
// - This method must be implemented recursively.
// - When debugging, make sure to output to cerr rather than cout. This will
//   prevent any leftover debug statements from confusing the automated
//   grading and will make sure output is guaranteed to be written to the
//   terminal in case your program crashes.
bool are_paren_balanced(const string& expression) {
    // TODO: your code here
    int i=0;
    int start_p=0;
    int end_p=0;
    int start_b=0; 
    int end_b=0;
    //count(expression);
    
    //helper function
    return are_paren_balanced(expression, i, start_p, end_p, start_b, end_b);

  /*  if ((are_paren_balanced(expression, i, start_p, end_p, start_b, end_b)) == false)
    {
        return false;
    }

    if ((are_paren_balanced(expression, i, start_p, end_p, start_b, end_b)) == true)
    {
        return true;
    }

    return false; */
}

// Add any additional function implementations here.
//
// If you want to use the suggested helper method, you'll have to write its
// definition here.

bool are_paren_balanced(const string& expression, int& i, int& start_p, int& end_p, int& start_b, int& end_b)
{
    //When we hit null pointer, we are done checking the array
    if (expression[i] == '\0') // base case, should be at the end of the array
    {
        if ( (start_p == end_p) && (start_b == end_b) && i>0)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    //Start counting the parentheses
    if (expression[i] == '(')
    {
        start_p++;
    }

    if (expression[i] == ')')
    {
        end_p++;
    }

    if (expression[i] == '[')
    {
        start_b++;
    }

    if (expression[i] == ']')
    {
        end_b++;
    }

    // for when the expression start with ) or ] 
    if((end_p > start_p) || (end_b > start_b))
    {
        return false;
    }

    i++;

    //cout << i << " " << start_p << " " << end_p << " " << start_b << " " << end_b << endl;
    return are_paren_balanced(expression, i, start_p, end_p, start_b, end_b);  
    //return false; 
}