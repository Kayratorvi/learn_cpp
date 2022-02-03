#include "Song.h"

Song::Song() {
    name = "no name";
    firstLine = "none";
}

Song::Song(std::string name, std::string firstLine) {
    this->name = name;
    this->firstLine = firstLine;
}

std::string Song::GetName() const {
    return name;
}

std::string Song::PlaySong() const {
    return firstLine;
}

int Song::GetPlayCount() const {
    return playCount;
}

void Song::IncrementPlayCount() {
    ++playCount;
}



