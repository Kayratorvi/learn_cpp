#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"
#include "Playlist.cpp"
#include "Song.cpp"


// TODO: clean up memory when it is no longer used
//  (you need to find the appropriate places in the code to do this)

std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(std::vector<Song*>& songs);
void ListSongsMenuOption(const std::vector<Song*>& songs);
void AddPlaylistMenuOption(std::vector<Playlist>& playlists);
void AddSongToPlaylistMenuOption(std::vector<Playlist>& playlists, std::vector<Song*> songs);
void ListPlaylistsMenuOption(std::vector<Playlist> playlists);
void PlayPlaylistMenuOption(std::vector<Playlist> playlists);
void RemovePlaylistMenuOption(std::vector<Playlist>& playlists);
void RemoveSongFromPlaylistMenuOption(std::vector<Playlist>& playlists);
void RemoveSongFromLibraryMenuOption(std::vector<Song*>& songs, std::vector<Playlist>& playlists);
void OptionsMenuOption();
void QuitMenuOption(std::vector<Song*>& songs, std::vector<Playlist>& playlists);

int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    std::vector<Song*> songs;
    std::vector<Playlist> playlists;

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(songs);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(songs);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(playlists, songs);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(playlists);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(playlists);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(songs, playlists);
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption(songs, playlists);
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }

        std::cout << std::endl;
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(std::vector<Song*>& songs) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";

    songName = GetUserString("Song Name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        songs.push_back(new Song(songName, firstLine));

        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(const std::vector<Song*>& songs) {
    for (unsigned int i = 0; i < songs.size(); ++i) {
        std::cout << songs.at(i)->GetName() << ": \"" << songs.at(i)->PlaySong() << "\", " << songs.at(i)->GetPlayCount();
        std::cout << " play(s)." << std::endl;
    }
}

void AddPlaylistMenuOption(std::vector<Playlist>& playlists) {
    playlists.push_back(Playlist(GetUserString("Playlist name: ")));
}

void AddSongToPlaylistMenuOption(std::vector<Playlist>& playlists, std::vector<Song*> songs) {
    int playlistIndexNum;
    int songIndexNum;

    ListPlaylistsMenuOption(playlists);

    playlistIndexNum = GetUserInt("Pick a playlist index number: ");

    for (unsigned int i = 0; i < songs.size(); ++i) {
        std::cout << i << ": " << songs.at(i)->GetName() << std::endl;
    }

    songIndexNum = GetUserInt("Pick a song index number: ");

    playlists.at(playlistIndexNum).AddSong(songs.at(songIndexNum));
}

void ListPlaylistsMenuOption(std::vector<Playlist> playlists) {
    for (unsigned int i = 0; i < playlists.size(); ++i) {
        std::cout << i << ": " << playlists.at(i).GetName() << std::endl;
    }
}

void PlayPlaylistMenuOption(std::vector<Playlist> playlists) {
    int userInt;

    ListPlaylistsMenuOption(playlists);
    userInt = GetUserInt("Pick a playlist index number: ");
    std::cout << std::endl;

    playlists.at(userInt).PlaySongs();
}

void RemovePlaylistMenuOption(std::vector<Playlist>& playlists) {
    int userInt;

    ListPlaylistsMenuOption(playlists);
    userInt = GetUserInt("Pick a playlist index number to remove: ");

    playlists.erase(playlists.begin() + userInt);
}

void RemoveSongFromPlaylistMenuOption(std::vector<Playlist>& playlists) {
    int playlistIndex;

    ListPlaylistsMenuOption(playlists);
    playlistIndex = GetUserInt("Pick a playlist index number: ");

    playlists.at(playlistIndex).RemoveSong();
}

void RemoveSongFromLibraryMenuOption(std::vector<Song*>& songs, std::vector<Playlist>& playlists) {
    int userInt;
    std::string songName;

    for (unsigned int i = 0; i < songs.size(); ++i) {
        std::cout << i << ": " << songs.at(i)->GetName() << std::endl;
    }

    userInt = GetUserInt("Pick a song index number to remove: ");
    songName = songs.at(userInt)->GetName();

    for (unsigned int i = 0; i < playlists.size(); ++i) {
        for (int j = 0; j < playlists.at(i).GetPlaylistSize(); ++j) {
            if (songName == playlists.at(i).GetSongName(j)) {
                playlists.at(i).RemoveSong(j);
            }
        }
    }
    delete songs.at(userInt); // Freeing memory from the song pointer
    songs.erase(songs.begin() + userInt); // Deleting the song from the vector
}

void OptionsMenuOption() {
    std::cout << "add      Adds a list of songs to the library" << std::endl
              << "list     Lists all the songs in the library" << std::endl
              << "addp     Adds a new playlist" << std::endl
              << "addsp    Adds a song to a playlist" << std::endl
              << "listp    Lists all the playlists" << std::endl
              << "play     Plays a playlist" << std::endl
              << "remp     Removes a playlist" << std::endl
              << "remsp    Removes a song from a playlist" << std::endl
              << "remsl    Removes a song from the library (and all playlists)" << std::endl
              << "options  Prints this options menu" << std::endl
              << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption(std::vector<Song*>& songs, std::vector<Playlist>& playlists) {
    int vectorSize;
    int i;

    std::cout << "Goodbye!" << std::endl;

    vectorSize = playlists.size();

    for (i = 0; i < vectorSize; ++i) {
        playlists.erase(playlists.begin()); // Freeing memory from playlists vector
    }

    vectorSize = songs.size();

    for (i = 0; i < vectorSize; ++i) {
        delete songs.at(0); // Freeing memory from songs pointers
        songs.erase(songs.begin()); // Freeing memory from songs vector
    }
}