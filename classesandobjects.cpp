// Use class to create an object (or instance)
// Data member: encapsulated data (or properties) - private by default.
// Function member: method
// Mutable function or method: non const - can only be called by non const object.
// Immutable method can only be called by const object.
#include <cstdio>
#include <string>
using namespace std;

class classSample
{
private:
    int m_value = 0;
public:
    void setValue(int value) {m_value = value;}
    int getValue() { return m_value; }
};

// Separating interface from implementation
class anotherClassExample
{
private:
    string m_playerName = " ";
public:
    void addName(string lastName);
    void getName();
};

void anotherClassExample::addName(string lastName)
{
    m_playerName += lastName;
}

void anotherClassExample::getName()
{
    printf("Name is: %s\n", m_playerName.c_str());
}

class moreClassExample {
private:
    int m_age = 0;
    string m_playerName = "";
    int m_score = 0;
public:
    // Constructor
    moreClassExample(const int age, const string &name, const int score);

    void setAge(const int age);
    void setPlayerName(const string &name);
    void setPlayerScore(const int score);

    int getPlayerAge();
    const string& getPlayerName();
    const char *getPlayer();
    // Immutable method
    int getPlayerScore() const;
    // Mutable version
    int getPlayerScore();
};

// Constructor implementation
moreClassExample::moreClassExample(const int age, const string &name, const int score) 
    : m_age(age), 
    m_playerName(name),
    m_score(score)
{

}

void moreClassExample::setAge(const int age){
    m_age = age;
}

void moreClassExample::setPlayerName(const string &name){
    m_playerName = name;
}

void moreClassExample::setPlayerScore(const int score){
    m_score = score;
}

int moreClassExample::getPlayerAge(){
    return m_age;
}

const string& moreClassExample::getPlayerName(){
    return m_playerName;
}

const char *moreClassExample::getPlayer(){
    return m_playerName.c_str();
}

// Immutable method
int moreClassExample::getPlayerScore() const{
    return m_score;
}

// Mutable method
int moreClassExample::getPlayerScore()
{
    return m_score *= 5;
}

// Classes can be created using class keyword or struct.
// classes default to private members while struct defaults to public members.
struct classStruct{
    int aVal;
    int bVal;
    int cVal;
};

int main ()
{
    int kval = 40;
    classSample myClass;
    myClass.setValue(kval);
    printf("Value: %d\n", myClass.getValue());

    anotherClassExample classExample;
    string name = "Phil";
    string lastname = " Oni";
    classExample.addName(name);
    classExample.addName(lastname);
    classExample.getName();

    classStruct cstruct = {1, 2, 3};
    printf("Numbers are: %d, %d, %d\n", cstruct.aVal, cstruct.bVal, cstruct.cVal);

    moreClassExample mclass(14, "Beaver", 4);
    printf("Player characteristics: %d, %s, %d\n", mclass.getPlayerAge(), mclass.getPlayerName().c_str(), mclass.getPlayerScore());

    // Const safe object
    const moreClassExample imclass(14, "Beaver", 4);
    printf("Player characteristics: %d\n", imclass.getPlayerScore());


    return 0;
}