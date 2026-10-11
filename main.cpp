#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Each node stores a song and links to the previous and next songs.
class Node {
public:
    string title, artist;
    Node* prev;
    Node* next;

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = next = nullptr;
    }
};

class MusicPlaylistManager {
private:
    Node* head;       // First song in the playlist
    Node* current;    // Currently selected song

public:
    MusicPlaylistManager() {
        head = current = nullptr;
    }

    // Add a song at the end. p is the new node; q traverses the list.
    void addSong(string title, string artist) {
        Node* p = new Node(title, artist);

        if (head == nullptr) {
            head = current = p;
        } else {
            Node* q = head;
            while (q->next != nullptr)
                q = q->next;

            q->next = p;
            p->prev = q;
        }
        cout << "Song added: " << title << " - " << artist << '\n';
    }

    // Delete the first song with the given title.
    void deleteSong(string title) {
        Node* q = head; // q searches for the song
        while (q != nullptr && q->title != title)
            q = q->next;

        if (q == nullptr) {
            cout << "Song not found: " << title << '\n';
            return;
        }

        Node* p = q; // p is the node to delete

        if (current == p)
            current = (p->next != nullptr) ? p->next : p->prev;

        if (p->prev != nullptr)
            p->prev->next = p->next;
        else
            head = p->next;

        if (p->next != nullptr)
            p->next->prev = p->prev;

        delete p;
        cout << "Song deleted: " << title << '\n';
    }

    // Select any song as current.
    void selectCurrentSong(string title) {
        Node* q = head;
        while (q != nullptr && q->title != title)
            q = q->next;

        if (q == nullptr) {
            cout << "Song not found: " << title << '\n';
            return;
        }
        current = q;
        playCurrent();
    }

    void displayForward() {
        Node* q = head;
        if (q == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "Forward playlist:\n";
        while (q != nullptr) {
            cout << q->title << " - " << q->artist;
            if (q == current) cout << "  [CURRENT]";
            cout << '\n';
            q = q->next;
        }
    }

    void displayBackward() {
        Node* q = head;
        if (q == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        while (q->next != nullptr)
            q = q->next;

        cout << "Reverse playlist:\n";
        while (q != nullptr) {
            cout << q->title << " - " << q->artist;
            if (q == current) cout << "  [CURRENT]";
            cout << '\n';
            q = q->prev;
        }
    }

    void playCurrent() {
        if (current == nullptr)
            cout << "Playlist is empty; no current song.\n";
        else
            cout << "Now playing: " << current->title
                 << " by " << current->artist << '\n';
    }

    void playNext() {
        if (current == nullptr)
            cout << "Playlist is empty.\n";
        else if (current->next == nullptr)
            cout << "Already at the last song.\n";
        else {
            current = current->next;
            playCurrent();
        }
    }

    void playPrevious() {
        if (current == nullptr)
            cout << "Playlist is empty.\n";
        else if (current->prev == nullptr)
            cout << "Already at the first song.\n";
        else {
            current = current->prev;
            playCurrent();
        }
    }

    void playCompletePlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* q = head;
        while (q != nullptr) {
            current = q;
            playCurrent();
            q = q->next;
        }
    }

    // Each repetition begins again at head.
    void repeatAll(int repetitions) {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        if (repetitions <= 0) {
            cout << "Enter a positive number of repetitions.\n";
            return;
        }

        for (int i = 1; i <= repetitions; ++i) {
            cout << "Repetition " << i << ":\n";
            Node* q = head;
            while (q != nullptr) {
                current = q;
                playCurrent();
                q = q->next;
            }
        }
    }

    void showCurrentSong() {
        if (current == nullptr)
            cout << "No song is currently selected.\n";
        else
            cout << "Current song: " << current->title
                 << " - " << current->artist << '\n';
    }

    // Release all dynamically allocated nodes.
    ~MusicPlaylistManager() {
        Node* q = head;
        while (q != nullptr) {
            Node* p = q;
            q = q->next;
            delete p;
        }
    }
};

int main() {
    MusicPlaylistManager playlist;
    int choice, repetitions;
    string title, artist;

    do {
        cout << "\n [ MUSIC PLAYLIST MANAGER ]\n"
             << "1. Add Song\n"
             << "2. Delete Song\n"
             << "3. Display Playlist\n"
             << "4. Display Playlist in Reverse\n"
             << "5. Play Current Song\n"
             << "6. Play Next Song\n"
             << "7. Play Previous Song\n"
             << "8. Play Complete Playlist\n"
             << "9. Repeat All\n"
             << "10. Show Current Song\n"
             << "11. Exit\n"
             << "12. Select Current Song\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            cout << "Enter song title: ";
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            playlist.addSong(title, artist);
            break;
        case 2:
            cout << "Enter title to delete: ";
            getline(cin, title);
            playlist.deleteSong(title);
            break;
        case 3: playlist.displayForward(); break;
        case 4: playlist.displayBackward(); break;
        case 5: playlist.playCurrent(); break;
        case 6: playlist.playNext(); break;
        case 7: playlist.playPrevious(); break;
        case 8: playlist.playCompletePlaylist(); break;
        case 9:
            cout << "Number of repetitions: ";
            if (cin >> repetitions) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                playlist.repeatAll(repetitions);
            } else {
                cout << "Invalid repetition count.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        case 10: playlist.showCurrentSong(); break;
        case 11: cout << "Exiting Music Playlist Manager.\n"; break;
        case 12:
            cout << "Enter title to select: ";
            getline(cin, title);
            playlist.selectCurrentSong(title);
            break;
        default: cout << "Invalid choice. Enter 1-12.\n";
        }
    } while (choice != 11);

    return 0;
}
