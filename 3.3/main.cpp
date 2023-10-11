#include "menuCommands.h"
#include "media.h"
int main() {
    cout << "Media manipulation." << endl;
    Movie movie;
    Comic comic;
    Show show;
    MultiSeasonShow multiSeasonShow;
    interface(&movie, &comic, &show, &multiSeasonShow);
    return 0;
}
