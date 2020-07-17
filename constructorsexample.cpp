// Constructors and destructors examples
#include <cstdio>
#include <string>
using namespace std;

const string unk = "unknow";
const string clonePrefix = "clone-";

class Animal
{
private:
    string m_type = unk;
    string m_name = unk;
    string m_sound = unk;
public:
    Animal(); // Default Constructor
    Animal(const string &type, const string &name, const string &sound); // Parameterized constructor.
    Animal(const Animal&); // Copy constructor use to initialize
    ~Animal(); // Destructor
    void printStuff() const;
};

Animal::Animal(){
    puts("Default Constructor");
}

Animal::Animal(const string &type, const string &name, const string &sound)
: m_type(type),
m_name(name),
m_sound(sound)
{
    puts("Constructor with arguments");
}

// Copy Constructor
Animal::Animal(const Animal& anim)
{
    puts("Copy Constructor");
    m_name = clonePrefix + anim.m_name;
    m_type = anim.m_type;
    m_sound = anim.m_sound;
}

// Destructor
Animal::~Animal()
{
    puts("Destroy object");
}

void Animal::printStuff() const {
    printf("%s the %s says %s\n", m_name.c_str(), m_type.c_str(), m_sound.c_str());
}

int main()
{
    Animal anim;
    anim.printStuff();

    const Animal animB("goat", "bob", "baah");
    animB.printStuff();

    const Animal animC = animB;
    animC.printStuff();

    return 0;
}