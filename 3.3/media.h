#ifndef INC_3_3_MEDIA_H
#define INC_3_3_MEDIA_H
#define TITLE_SIZE 100
#include <iostream>
#include <cmath>
using namespace std;

class Title{
    char title[TITLE_SIZE];
public:
    Title(): title(""){}
    virtual ~Title(){cout<<"Title destructor\n";};
    void setTitle();
    [[nodiscard]] const char* getTitle() const;
    void printTitle() const;
};
class Movie : public virtual Title{
    int length;
public:
    Movie(){length = 0;}
    ~Movie() override{cout<<"Movie destructor\n";};

    void setLength();
    [[nodiscard]] int getLength() const;
    void printMovie() const;
};
class Comic : public virtual Title{
    int volumes;
    int pagesInVolume;
public:
    Comic(){
        volumes = 0;
        pagesInVolume = 0;
    }
    ~Comic() override{cout<<"Comic destructor\n";};

    void setVolumes();
    [[nodiscard]] int getVolumes() const;
    void setPages();
    [[nodiscard]] int getPages() const;
    void printComic() const;
};
class Show : public Movie{
    int episodes;
public:
    Show(){episodes = 0;}
    ~Show() override{cout<<"Show destructor\n";};
    void setEpisodes();
    [[nodiscard]] int getEpisodes() const;
    void printShow() const;
};
class MultiSeasonShow : public Show{
    int seasons;
public:
    MultiSeasonShow(){seasons = 0;}
    ~MultiSeasonShow() override{cout<<"MultiSeasonShow destructor\n";};
    void setSeasons();
    [[nodiscard]] int getSeasons() const;
    void printMShow() const;
};
#endif
