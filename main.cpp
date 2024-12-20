#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <random>
#include <ctime>

using namespace std;

mt19937 gen(static_cast<unsigned int>(time(0)));

class Character {
    protected:
        string Name;
        int Health;
        int Strength;
        string Weapon;
        string CharacterClass;
        Character* weapon1 = nullptr;

    public:
        void setName(string name) {
            Name = name;
        }
        string getName() {
            return Name;
        }
        void setClass(string characterClass) {
            CharacterClass = characterClass;
        }
        string getClass() {
            return CharacterClass;
        }
        void setWeapon(string weapon) {
            Weapon = weapon;
        }
        string getWeapon() {
            return Weapon;
        }
        int getHealth() {
            return Health;
        }
        Character(string name, string weapon, int health) {
            Name = name;
            Weapon = weapon;
            Health = health;
        }

        virtual void Attack() = 0;

        virtual void displayClass() = 0;

        virtual string selectWeapon() = 0;
};

class Mage: public Character {
    private:
        string CharacterClass = "Mage";
        string Element;

    public:
        void setElement(string element) {
            Element = element;
        }
        string getElement() {
            return Element;
        }

        Mage(string name, string weapon, int health, string element)
            :Character(name, weapon, 50)
        {
            Element = element;
        }

        void Attack() override {
            cout << "You cast a(n) " << Element << " ball" << endl;
        }

        void displayClass() override {
            cout << "Success! You are now greatest force of " << Element << " magic in the world!" << endl;
        }
        string selectWeapon() override {
            string Bplayer2Weapon;
            string weapon1 = "";
            string weapon2 = "";
            string weapon3 = "";

            uniform_int_distribution<> distr(1, 6);
            int randomNumber = distr(gen);
            switch (randomNumber){
                case 1:
                    Bplayer2Weapon = weapon1;
                    break;
                case 2:
                    Bplayer2Weapon = weapon2;
                    break;
                case 3:
                    Bplayer2Weapon = weapon3;
                    break;
                }
            return Bplayer2Weapon;
        }

};

class Barbarian: public Character {
    private:
        string CharacterClass = "Barbarian";

    public:
        Barbarian(string name, string weapon, int health)
            :Character(name, weapon, 100)
        {

        }

        void Attack() override {
            cout << "You smack the shit out their head" << endl;
        }
        void displayClass() override {
            cout << "Success! You are the strongest warrior in the land and wield the mighty " << Weapon << "!" << endl;
        }

};

class Archer: public Character {
    private:
        string CharacterClass = "Archer";

    public:
        Archer(string name, string weapon, int health)
            :Character(name, weapon, 75)
        {

        }

        void Attack() override {
            cout << "You sling an arrow through their dome" << endl;
        }
        void displayClass() override {
            cout << "Success! You are the quickest shot to grace the lands!" << endl;
        }

};

class Assassin: public Character {
    private:
        string CharacterClass = "Assassin";

    public:
        Assassin(string name, string weapon, int health)
            :Character(name, weapon, 75)
        {

        }

        void Attack() override {
            cout << "You stab them in the back" << endl;
        }
        void displayClass() override {
            cout << "Success! You are the master stealth, feared by all!" << endl;
        }


};

class Peasant: public Character {
    private:
        string CharacterClass = "Peasant";

    public:
        Peasant(string name, string weapon, int health)
            :Character(name, weapon, 30)
        {

        }

        void Attack() override {
            cout << "You throw a rock" << endl;
        }
        void displayClass() override {
            cout << "Success! You are a huge sack of shit!" << endl;
        }



};

class oPeasant: public Character { //Try and make two different presets for each class.
    private:                                                //One is for the player and one is a robot that auto attacks and has one/two attacks.
        string CharacterClass = "Peasant";

    public:
        oPeasant(string name, string weapon, int health)
            :Character(name, weapon, 30)
        {

        }

        void Attack() override {
            cout << "Peasant throws a rock at you" << endl;
        }
        void displayClass() override {
            cout << "Success! You are a huge sack of shit!" << endl;
        }

};

string selectName(){
    string Bplayer2Name;
    string name1 = "Bob";
    string name2 = "Jerry";
    string name3 = "Larry";
    string name4 = "Kevin";
    string name5 = "Steve";

    uniform_int_distribution<> distr(1, 5); // 1 archer g g archer
    int randomNumber = distr(gen);
    switch (randomNumber){
        case 1:
            Bplayer2Name = name1;
            break;
        case 2:
            Bplayer2Name = name2;
            break;
        case 3:
            Bplayer2Name = name3;
            break;
        case 4:
            Bplayer2Name = name4;
            break;
        case 5:
            Bplayer2Name = name5;
            break;
        }
    return Bplayer2Name;
}

string selectElement(){
    string Bplayer2Element;
    string element1 = "ice";
    string element2 = "water";
    string element3 = "fire";
    string element4 = "lightning";
    string element5 = "fire";
    string element6 = "wind";

    uniform_int_distribution<> distr(1, 6);
    int randomNumber = distr(gen);
    switch (randomNumber){
        case 1:
            Bplayer2Element = element1;
            break;
        case 2:
            Bplayer2Element = element2;
            break;
        case 3:
            Bplayer2Element = element3;
            break;
        case 4:
            Bplayer2Element = element4;
            break;
        case 5:
            Bplayer2Element = element5;
            break;
        case 6:
            Bplayer2Element = element6;
            break;
        }
    return Bplayer2Element;
}

string selectWeapon(){
    string Bplayer2Weapon;
    string weapon1 = "";
    string weapon2 = "";
    string weapon3 = "";

    uniform_int_distribution<> distr(1, 6);
    int randomNumber = distr(gen);
    switch (randomNumber){
        case 1:
            Bplayer2Weapon = weapon1;
            break;
        case 2:
            Bplayer2Weapon = weapon2;
            break;
        case 3:
            Bplayer2Weapon = weapon3;
            break;
        }
    return Bplayer2Weapon;
}

int main()
{
string player1;
string player2;
string player1Name;
string player2Name; //this will have a default when fighting a bot.
string player1Weapon;
string player2Weapon;//this will have a default when fighting a bot.
string player1Element;
string player2Element;//this will be a random element when fighting a bot.
int numPlayer;
Character* chosenCharacter1 = nullptr;
Character* chosenCharacter2 = nullptr;
bool running = true;
set<string> validCharacters = {"mage", "archer", "barbarian", "assassin", "peasant"};
set<string> validElements = {"ice", "fire", "lightning", "earth", "water", "wind"};

while(running == true){
    cout << "One-player or Two-player? (Input '1' or '2')" << endl;
    cin >> numPlayer;
    cin.ignore();

    if(cin.fail()){                         //Checks if input is an int
        cout << "Invalid Input" << endl;
        cin.clear();                        // Clear the error flag
        cin.ignore(1000, '\n');         // Discards invalid input from the buffer
    }else{
         running = false;
    }
}

running = true;

if(numPlayer == 1){

    while(running == true){
        cout << "What character do you want to play as? [Mage][Archer][Barbarian][Assassin][Peasant]" << endl;
        getline(cin, player1);
        transform(player1.begin(), player1.end(), player1.begin(), ::tolower);

        if(validCharacters.find(player1) != validCharacters.end()){ //.find() function checks if a value player1 exists in the the array. if not the find function will point to validCharacters.end() so when it is not equal to this, a valid character has been input
            running = false;
        }else {
            cout << "Invalid selection, try again." << endl;
        }
    }

    cout << "What will the name of your " << player1 << "?" << endl;
    getline(cin, player1Name);

    cout << "What will be the name of the weapon you will wield?" << endl;
    getline(cin, player1Weapon);

    if(player1 == "mage"){
        running = true;
        while(running == true){
            cout << "What element will your Mage harness? [Ice][Fire][Wind][Earth][Lightning][Water]" << endl;
            getline(cin, player1Element);
            transform(player1Element.begin(), player1Element.end(), player1Element.begin(), ::tolower);

            if(validElements.find(player1Element) != validElements.end()){ //.find() function checks if a value player1 exists in the the array. if not the find function will point to validCharacters.end() so when it is not equal to this, a valid character has been input
                running = false;
            }else {
                cout << "Invalid selection, try again." << endl;
            }
        }
        chosenCharacter1 = new Mage(player1Name, player1Weapon, 50, player1Element);
        chosenCharacter1->displayClass();
    }else if(player1 == "archer"){
        chosenCharacter1 = new Archer(player1Name, player1Weapon, 75);
        chosenCharacter1->displayClass();
    }else if(player1 == "barbarian"){
        chosenCharacter1 = new Barbarian(player1Name, player1Weapon, 100);
        chosenCharacter1->displayClass();
    }else if(player1 == "assassin"){
        chosenCharacter1 = new Assassin(player1Name, player1Weapon, 75);
        chosenCharacter1->displayClass();
    }else if(player1 == "peasant"){
        chosenCharacter1 = new Peasant(player1Name, player1Weapon, 30);
        chosenCharacter1->displayClass();
    }

    running = true;
    while(running == true){
        cout << "What character do you want to play against? [Mage][Archer][Barbarian][Assassin][Peasant]" << endl;
        getline(cin, player2);
        transform(player2.begin(), player2.end(), player2.begin(), ::tolower);

        if(validCharacters.find(player2) != validCharacters.end()){ //.find() function checks if a value player1 exists in the the array. if not the find function will point to validCharacters.end() so when it is not equal to this, a valid character has been input
            running = false;
        }else {
            cout << "Invalid selection, try again." << endl;
        }
    }

    player2Name = selectName();

    if(player2 == "mage"){
        player2Element = selectElement();
        chosenCharacter2 = new Mage(player2Name, player2Weapon, 50, player2Element);
        chosenCharacter2->displayClass();
    }else if(player2 == "archer"){
        chosenCharacter2 = new Archer(player2Name, player2Weapon, 75);
        chosenCharacter2->displayClass();
    }else if(player2 == "barbarian"){
        chosenCharacter2 = new Barbarian(player2Name, player2Weapon, 100);
        chosenCharacter2->displayClass();
    }else if(player2 == "assassin"){
        chosenCharacter2 = new Assassin(player2Name, player2Weapon, 75);
        chosenCharacter2->displayClass();
    }else if(player2 == "peasant"){
        chosenCharacter2 = new Peasant(player2Name, player2Weapon, 30);
        chosenCharacter2->displayClass();
    }

}else if(numPlayer == 2){

    while(running == true){
        cout << "Player 1, select your character: [Mage][Archer][Barbarian][Assassin][Peasant]" << endl;
        getline(cin, player1);
        transform(player1.begin(), player1.end(), player1.begin(), ::tolower);

        if(validCharacters.find(player1) != validCharacters.end()){ //.find() function checks if a value player1 exists in the the array. if not the find function will point to validCharacters.end() so when it is not equal to this, a valid character has been input
            running = false;
        }else {
            cout << "Invalid selection, try again." << endl;
        }
    }

    cout << "What will the name of your " << player1 << " be?" << endl;
    getline(cin, player1Name);

    cout << "What will be the name of the weapon you will wield?" << endl;
    getline(cin, player1Weapon);


    if(player1 == "mage"){
        running = true;
        while(running == true){
            cout << "What element will your Mage harness? [Ice][Fire][Wind][Earth][Lightning][Water]" << endl;
            getline(cin, player1Element);
            transform(player1Element.begin(), player1Element.end(), player1Element.begin(), ::tolower);

            if(validElements.find(player1Element) != validElements.end()){ //.find() function checks if a value player1 exists in the the array. if not the find function will point to validCharacters.end() so when it is not equal to this, a valid character has been input
                running = false;
            }else {
                cout << "Invalid selection, try again." << endl;
            }
        }
        chosenCharacter1 = new Mage(player1Name, player1Weapon, 50, player1Element);
        chosenCharacter1->displayClass();
    }else if(player1 == "archer"){
        chosenCharacter1 = new Archer(player1Name, player1Weapon, 75);
        chosenCharacter1->displayClass();
    }else if(player1 == "barbarian"){
        chosenCharacter1 = new Barbarian(player1Name, player1Weapon, 100);
        chosenCharacter1->displayClass();
    }else if(player1 == "assassin"){
        chosenCharacter1 = new Assassin(player1Name, player1Weapon, 75);
        chosenCharacter1->displayClass();
    }else if(player1 == "peasant"){
        chosenCharacter1 = new Peasant(player1Name, player1Weapon, 30);
        chosenCharacter1->displayClass();
    }

    running = true;
    while(running == true){
        cout << "Player 2, select your character: [Mage][Archer][Barbarian][Assassin][Peasant]" << endl;
        getline(cin, player2);
        transform(player2.begin(), player2.end(), player2.begin(), ::tolower);

        if(validCharacters.find(player2) != validCharacters.end()){ //.find() function checks if a value player1 exists in the the array. if not the find function will point to validCharacters.end() so when it is not equal to this, a valid character has been input
            running = false;
        }else {
            cout << "Invalid selection, try again." << endl;
        }
    }

    cout << "What will the name of your " << player2 << "?" << endl;
    getline(cin, player2Name);

    cout << "What will be the name of the weapon you will wield?" << endl;
    getline(cin, player2Weapon);


    if(player2 == "mage"){
        running = true;
        while(running == true){
            cout << "What element will your Mage harness? [Ice][Fire][Wind][Earth][Lightning][Water]" << endl;
            getline(cin, player2Element);
            transform(player2Element.begin(), player2Element.end(), player2Element.begin(), ::tolower);

            if(validElements.find(player2Element) != validElements.end()){ //.find() function checks if a value player1 exists in the the array. if not the find function will point to validCharacters.end() so when it is not equal to this, a valid character has been input
                running = false;
            }else {
                cout << "Invalid selection, try again." << endl;
            }
        }
        chosenCharacter2 = new Mage(player2Name, player2Weapon, 50, player2Element);
        chosenCharacter2->displayClass();
    }else if(player2 == "archer"){
        chosenCharacter2 = new Archer(player2Name, player2Weapon, 75);
        chosenCharacter2->displayClass();
    }else if(player2 == "barbarian"){
        chosenCharacter2 = new Barbarian(player2Name, player2Weapon, 100);
        chosenCharacter2->displayClass();
    }else if(player2 == "assassin"){
        chosenCharacter2 = new Assassin(player2Name, player2Weapon, 75);
        chosenCharacter2->displayClass();
    }else if(player2 == "peasant"){
        chosenCharacter2 = new Peasant(player2Name, player2Weapon, 30);
        chosenCharacter2->displayClass();
    }
}else {
    cout << "Invalid Input." << endl;
}



    return 0;
}
