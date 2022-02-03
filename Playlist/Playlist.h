#ifndef LAB8PLAYLIST_PLAYLIST_H
#define LAB8PLAYLIST_PLAYLIST_H

#include <string>
#include <vector>
#include "Song.h"
class Playlist {
    public:
        Playlist();
        Playlist(std::string name = "no name");
        void AddSong(Song *newSong);
        void PlaySongs() const ;
        void RemoveSong();
        void RemoveSong(int indexNum);
        std::string GetName() const;
        std::string GetSongName(int indexNum);
        int GetPlaylistSize();
    private:
        std::string name;
        std::vector<Song*> playlist;
};

#endif //LAB8PLAYLIST_PLAYLIST_H
