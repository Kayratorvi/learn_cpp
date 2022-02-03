#include <iostream>
#include "Playlist.h"

Playlist::Playlist() {
    name = "no name";
}

Playlist::Playlist(std::string name) {
    this->name = name;
}

void Playlist::AddSong(Song *newSong) {
    playlist.push_back(newSong);
}

void Playlist::PlaySongs() const {
    std::cout << "Playing songs from playlist: " << name << std::endl;
    for (unsigned int i = 0; i < playlist.size(); ++i) {
        std::cout << playlist.at(i)->PlaySong() << std::endl;
        playlist.at(i)->IncrementPlayCount();
    }
}

void Playlist::RemoveSong() {
    int indexNum;

    for (unsigned int i = 0; i < playlist.size(); ++i) {
        std::cout << i << ": " << playlist.at(i)->GetName() << std::endl;
    }

    std::cout << "Pick a song index number to remove: ";
    std::cin >> indexNum;
    std::cin.ignore();

    playlist.erase(playlist.begin() + indexNum);

    std::cout << std::endl;
}

void Playlist::RemoveSong(int indexNum) {
    playlist.erase(playlist.begin() + indexNum);
}

std::string Playlist::GetName() const {
    return name;
}

std::string Playlist::GetSongName(int indexNum) {
    return playlist.at(indexNum)->GetName();
}

int Playlist::GetPlaylistSize() {
    return playlist.size();
}

