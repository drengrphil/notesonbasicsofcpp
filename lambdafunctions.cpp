// Lambda function demo
// C++11 provides ability to create lambda functions (or closures).
// A lambda function is a function that you can write inline in code.
// it is usually pass into another function similar function pointer or function.
/*
 * Example: Implement an address book class with search function.
 * Take a string and return all addresses that match the string.
 */
#include <string>
#include <vector>

using namespace std;

class AddressBook
{
public:
    // Using template to ignore differences betwen functors, function pointers
    // and lambda.
    // Any function can be passed into findMatchingAddresses that contains
    // logic for finding a particular function.
    // This means that func must have been defined somewhere else to be used
    // in findMatchingAddresses. Thats why lambda comes in.
    template<typename Func>
    vector<string> findMatchingAddresses (Func func)
    {
        vector<string> results;
        for (auto it = m_storedAddresses.begin(); it != m_storedAddresses.end(); ++it)
        {
            // Call the function passed into findMatchingAddresses
            if (func(*it)){
                results.push_back(*it);
            }
        }
        return results;
    }
private:
    vector<string> m_storedAddresses;
};

/*
 *
 * Basic lambda syntax is given as follows:
 *     auto func = [] () { cout << "Hello world"; };
 *     lambda starts with [] called the capture specification,
 *         telling the compiler we are creating a lambda function.
 *         (): takes list of argument
 *     func(); // Call the function.
 */
// To solve the address book problem using lambda
AddressBook globalAddressBook;

vector<string> findAddressFromOrgs()
{
    return globalAddressBook.findMatchingAddresses(
        // Declare a lambda function with [] as the start
        [] (const string& addr){return addr.find(".org") != string::npos;}
    );
}

// Find email address longer than a specific length
int minLen = 15;
vector<string> emailAddressLengthFinder()
{
    return globalAddressBook.findMatchingAddresses(
        [&] (const string& addr) { return addr.length() >= minLen; }
    );
}