#ifndef LAB8PLAYLIST_SONG_H
#define LAB8PLAYLIST_SONG_H

#include <string>

class Song {
    public:
        Song();
        Song(std::string name = "none", std:: string firstLine = "none");
        std::string GetName() const;
        std::string PlaySong() const;
        int GetPlayCount() const;
        void IncrementPlayCount();
    private:
        std::string name;
        std::string firstLine;
        int playCount = 0;
};

#endif //LAB8PLAYLIST_SONG_H
