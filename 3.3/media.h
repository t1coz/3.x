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
    void setTitle();
    const char* getTitle() const;

};
class Movie : public virtual Title{
    int length;
public:
    Movie(){length = 0;}
    void setLength();
    int getLength() const;
};
class Comic : public virtual Title{
    int volumes;
    int pagesInVolume;
public:
    Comic(){
        volumes = 0;
        pagesInVolume = 0;
    }
    void setVolumes();
    int getVolumes() const;
    void setPages();
    int getPages() const;
};
class Show : public Movie{
    int episodes;
public:
    Show(){episodes = 0;}
    void setEpisodes();
    int getEpisodes() const;
};
class MultiSeasonShow : public Show{
    int seasons;
public:
    MultiSeasonShow(){seasons = 0;}
    void setSeasons();
    int getSeasons() const;
};
#endif
