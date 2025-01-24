#include <iostream>
#include <list>
#include <string>

using namespace std;
void showAnimals(list<string> &animals);
void showMenu(){
    cout << "Welcome to the list of animals" << endl;
    cout << "The list of animals currently contains the following animals: " << endl;
    cout << endl;
}
void showOptions(){
    cout << "Please choose one of the following options: (input numbers)" << endl;
    cout << "1. Delete an animal." << endl;
    cout << "2. Add an animal." << endl;
    cout << "3. Delete and add an animal to the end of the list." << endl;
    cout << "4. Replace an animal" << endl;
    cout << "0. exit." << endl;
    cout << "... ";
}
void showAnimals(list<string> &animals){
    int i = 1;
    for (list<string>::iterator it = animals.begin(); it != animals.end();it++, i++) {
        cout << i  << ". "<< *it << endl;
    }
}
int inputValidation(int a){
    while(a > 4 || a < 0){
        cout << "Please input a value between 0 and 4... ";
        cin >> a;
    }
    return a;
}
void deleteWord(list<string> &animals){
    int quantity = animals.size();
    int deleteIndex = 0;
    showAnimals(animals);
    cout << "Please write the number for the animal you would like to delete. " << endl;
    cin >> deleteIndex;
    while(deleteIndex > quantity || deleteIndex < 0){
        cout << "Please write the number for the animal you would like to delete. " << endl;
        cin >> deleteIndex;
    }
    list<string>::iterator it =  animals.begin();
    advance(it,(deleteIndex-1));
    animals.erase(it);
}
void addAnimal(list<string> &animals){
    cout << "Please write the name of the animal you would like to add." << endl;
    string animalName;
    cin >> animalName;
    animals.push_back(animalName);
}
void deleteAddAnimal(list<string> &animals){
    deleteWord(animals);
    addAnimal(animals);
}
void replaceAnimal(list<string> &animals){
    int quantity = animals.size();
    int deleteIndex = 0;
    showAnimals(animals);
    cout << "Please write the number for the animal you would like to replace. " << endl;
    cin >> deleteIndex;
    while(deleteIndex > quantity || deleteIndex < 0){
        cout << "Please write the number for the animal you would like to replace. " << endl;
        cin >> deleteIndex;
    }
    string newAnimal;
    cout << "Please type the new animal name... ";
    cin >> newAnimal;
    auto it =  animals.begin();

        advance(it,(deleteIndex-1));
        it = animals.erase(it);
        animals.insert(it,newAnimal);
}

int main() {
    list<string> animals = {"Dog", "Cat", "Horse", "Lion", "Tiger", "Human", "Snake", "Bear","Capybara"};
    showMenu();
    showAnimals(animals);
    showOptions();
    int input;
    cin >> input;
    while (input != 0){
        switch (input) {
            case 1:
                deleteWord(animals);
                cout << "New list is: " << endl;
                showAnimals(animals);
                break;
            case 2:
                addAnimal(animals);
                cout << "New list is: " << endl;
                showAnimals(animals);
                break;
            case 3:
                deleteAddAnimal(animals);
                cout << "New list is: " << endl;
                showAnimals(animals);
                break;

            case 4:
                replaceAnimal(animals);
                cout << "New list is: " << endl;
                showAnimals(animals);
                break;
            default:
                input = 0;
        }
        showOptions();
        cin >> input;

    }
    return 0;
}
