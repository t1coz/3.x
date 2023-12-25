#include "media.h"
#include "menuCommands.h"
#include "exceptions.h"
void Title :: setTitle(){
    cout << "Enter the title: ";
    char* tString;
    getStr(&tString);
    if(strlen(tString)>TITLE_SIZE){
        throw Exp(104, "Bad size");
    }
    strcpy(title, tString);
}
const char* Title :: getTitle() const{
    return title;
}

void Movie :: setLength(){
    int aLength;
    cout << "Enter a length in minutes: ";
    while (true) {
        if (cin >> aLength && aLength > 0) {
            length = aLength;
            break;
        } else {
            cin.clear();
            while (cin.get() != '\n');
            throw ExpInput(101,"Invalid length Input!");
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
            cin.clear();
            while (cin.get() != '\n');
            throw ExpInput(101,"Invalid nummber of volumes Input!");
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
            cin.clear();
            while (cin.get() != '\n');
            throw ExpInput(101,"Invalid number of pages in volume Input!");
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
            cin.clear();
            while (cin.get() != '\n');
            throw ExpInput(101, "Invalid input number of episodes in show");
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
            cin.clear();
            while (cin.get() != '\n');
            throw ExpInput(101,"Invalid input number of seasons in the show");

        }
    }
}
int MultiSeasonShow :: getSeasons() const{
    return seasons;
}

void functionsSelection(int choice, Movie *movie, Comic *comic, Show *show, MultiSeasonShow *multiSeasonShow){
    try {
        switch (choice) {
            case 1:{
                movie->setTitle();
                movie->setLength();
                break;
            }
            case 2:{
                movie->printMovie();
                break;
            }
            case 3:{
                comic->setTitle();
                comic->setVolumes();
                comic->setPages();
                break;
            }
            case 4:{
                comic->printComic();
                break;
            }
            case 5:{
                show->setTitle();
                show->setLength();
                show->setEpisodes();
                break;
            }
            case 6:{
                show->printShow();
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
                multiSeasonShow->printMShow();
                break;
            }
            case 9:{
                cout <<"\nChoose the comparison:\n"
                       "1. Movie and a Show;\n"
                       "2. Show and multiSeason show;\n"
                       "Choice: ";
                int answer = methodOfInputRange(2);
                if(answer == 1){
                    cout << "Is it a multiSeason show? ";
                    char decision = yesOrNo();
                    if (decision == 'y'){
                        multiSComparison(*movie, *multiSeasonShow);
                    }else{
                        singleSComparison(*movie, *show);
                    }
                }else{
                    showsComparison(*show, *multiSeasonShow);
                }
            }
            case 10:{
                episodesComparison(*show, *multiSeasonShow);
            }
            default: break;
        }
    } catch (Exp error) {
        error.show();
    }

}
void Title :: printTitle() const{
    cout << "Title: " << this->getTitle() << endl;
}
void Movie :: printMovie() const{
    this->printTitle();
    cout << "Length: " << this->getLength() << endl;
}
void Comic :: printComic() const {
    this->printTitle();
    cout << "Number of volumes: " << this->getVolumes() << endl;
    cout << "Number of pages in volume: " << this->getPages() << endl;
}
void Show :: printShow() const{
    //this->printTitle();
    this->printMovie();
    cout << "Number of episodes: " << this->getEpisodes() << endl;
}
void MultiSeasonShow :: printMShow() const{
    this->printShow();
    cout << "Number of seasons: " << this->getSeasons() << endl;
}
void multiSComparison(const Movie movie, const MultiSeasonShow show){
    if(movie.getLength() > show.getLength()){
        cout << GREEN <<  "Movie length is " << movie.getLength() - show.getLength()
             << " minutes longer.\n";

    }else if(movie.getLength() < show.getLength()){
        cout << GREEN <<  "Show length is " << show.getLength() - movie.getLength()
             << " minutes longer.\n";
    }else{
        cout << GREEN <<  "Movie and the show are identical in length.\n";
    }
}
void singleSComparison(const Movie movie, const Show show){
    if(movie.getLength() > show.getLength()){
        cout << GREEN <<  "Movie length is " << movie.getLength() - show.getLength()
             << " minutes longer.\n";

    }else if(movie.getLength() < show.getLength()){
        cout << GREEN <<  "Show length is " << show.getLength() - movie.getLength()
             << " minutes longer.\n";
    }else{
        cout << GREEN <<  "Movie and the show are identical in length.\n";
    }
}
void showsComparison(const Show sShow, const MultiSeasonShow mShow){
    if(sShow.getLength() > mShow.getLength()){
        cout << GREEN <<  "Single season show length is " << sShow.getLength() - mShow.getLength()
             << " minutes longer.\n";

    }else if(sShow.getLength() < mShow.getLength()){
        cout << GREEN << "MultiSeason show length is " << mShow.getLength() - sShow.getLength()
             << " minutes longer.\n";
    }else{
        cout << GREEN <<  "Shows are identical in length.\n";
    }
}
void episodesComparison(Show show, MultiSeasonShow mShow){
    if(show.getEpisodes() > mShow.getEpisodes()){
        cout << GREEN <<  "Single season has " << show.getEpisodes() - mShow.getEpisodes()
             << " more episodes.\n";

    }else if(show.getEpisodes() < mShow.getEpisodes()){
        cout << GREEN << "MultiSeason show has " << mShow.getEpisodes() - show.getEpisodes()
             << " more episodes.\n";
    }else{
        cout << GREEN <<  "Shows have the same number of episodes.\n";
    }
}