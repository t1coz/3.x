#include "media.h"
#include "menuCommands.h"
void Title :: setTitle(){
    cout << "Enter the title: ";
    char* tString;
    getStr(&tString);
    if(strlen(tString)>TITLE_SIZE){
        cout << "Title name should be < 200 characters!";
        return;
    }
    strcpy(title, tString);
}
const char* Title :: getTitle() const{
    return title;
}

void Movie :: setLength(){
    int aLength;
    cout << "Enter a length of the movie in minutes: ";
    while (true) {
        if (cin >> aLength && aLength > 0) {
            length = aLength;
            break;
        } else {
            cout << "Invalid Input! Please input CORRECT value." << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}
int Movie :: getLength() const{
    return length;
}

void Comic :: setVolumes(){
    int aVolumes;
    cout << "Enter the number of volumes: ";
    while (true) {
        if (cin >> aVolumes && aVolumes > 0) {
            volumes = aVolumes;
            break;
        } else {
            cout << "Invalid Input! Please input CORRECT value." << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}
int Comic :: getVolumes() const{
    return volumes;
}
void Comic :: setPages(){
    int aPages;
    cout << "Enter the number of pages in volume: ";
    while (true) {
        if (cin >> aPages && aPages > 0) {
            pagesInVolume = aPages;
            break;
        } else {
            cout << "Invalid Input! Please input CORRECT value." << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}
int Comic :: getPages() const{
    return pagesInVolume;
}

void Show :: setEpisodes(){
    int aEpisodes;
    cout << "Enter the number of episodes in show: ";
    while (true) {
        if (cin >> aEpisodes && aEpisodes > 0) {
            episodes = aEpisodes;
            break;
        } else {
            cout << "Invalid Input! Please input CORRECT value." << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}
int Show :: getEpisodes() const{
    return episodes;
}

void MultiSeasonShow :: setSeasons(){
    int aSeasons;
    cout << "Enter the number of seasons in the show: ";
    while (true) {
        if (cin >> aSeasons && aSeasons > 0) {
            seasons = aSeasons;
            break;
        } else {
            cout << "Invalid Input! Please input CORRECT value." << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}
int MultiSeasonShow :: getSeasons() const{
    return seasons;
}

void functionsSelection(int choice, Movie *movie, Comic *comic, Show *show, MultiSeasonShow *multiSeasonShow){
    char* userString = nullptr;
    int localChoice;
    switch (choice) {
        case 1:{
            movie->setTitle();
            movie->setLength();
            break;
        }
        case 2:{
            cout << "Title: " << movie->getTitle() << endl;
            cout << "Length: " << movie->getLength() << endl;
            break;
        }
        case 3:{
            comic->setTitle();
            comic->setVolumes();
            comic->setPages();
            break;
        }
        case 4:{
            cout << "Title: " << comic->getTitle() << endl;
            cout << "Number of volumes: " << comic->getVolumes() << endl;
            cout << "Number of pages in volume: " << comic->getPages() << endl;
            break;
        }
        case 5:{
            show->setTitle();
            show->setLength();
            show->setEpisodes();
            break;
        }
        case 6:{
            cout << "Title: " << show->getTitle() << endl;
            cout << "Length: " << show->getLength() << endl;
            cout << "Number of episodes: " << show->getEpisodes() << endl;
            break;
        }
        case 7:{
            multiSeasonShow->setTitle();
            multiSeasonShow->setLength();
            multiSeasonShow->setEpisodes();
            multiSeasonShow->setSeasons();
            break;
        }
        case 8:{
            cout << "Title: " << multiSeasonShow->getTitle() << endl;
            cout << "Length: " << multiSeasonShow->getLength() << endl;
            cout << "Number of episodes: " << multiSeasonShow->getEpisodes() << endl;
            cout << "Number of seasons: " << multiSeasonShow->getSeasons() << endl;
            break;
        }
        default: break;
    }
}