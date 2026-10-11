# MusicPlaylistManager
A menu-driven Music Playlist Manager developed in C++ using a Doubly Linked List. Supports adding and deleting songs, forward/reverse traversal, current song selection, next/previous navigation, complete playlist playback, and Repeat All.

# MusicPlaylistManager
A menu-driven Music Playlist Manager developed in C++ using a Doubly Linked List. Supports adding and deleting songs, forward/reverse traversal, current song selection, next/previous navigation, complete playlist playback, and Repeat All.

# Music Playlist Manager Using Doubly Linked List in C++

## 1. Project Overview

The **Music Playlist Manager** is a menu-driven C++ application developed using a Doubly Linked List. It allows users to manage a collection of songs by adding and deleting songs, displaying the playlist in forward and reverse order, selecting the current song, navigating between songs, playing the complete playlist, and repeating playback for a specified number of repetitions.

This project demonstrates the practical implementation of fundamental Data Structures and Algorithms concepts, including dynamic memory allocation, node insertion and deletion, pointer manipulation, bidirectional traversal, and current-node management.

**Academic Details**

* **College:** Amrutvahini College of Engineering, Sangamner
* **Course:** S.Y. B.Tech, Electronics and Computer Engineering
* **Subject:** Data Structures and Algorithms
* **Course Code:** R25-EC-PCC-202
* **Semester:** III
* **Academic Activity:** CCE Case Study, October 2026
* **Project Title:** Music Playlist Manager
* **Programming Language:** C++

## 2. Objectives

* To understand the structure and operation of a doubly linked list.
* To implement insertion and deletion of nodes dynamically.
* To demonstrate forward and reverse traversal.
* To implement next and previous song navigation using pointers.
* To maintain and update the currently selected song.
* To handle empty playlists and boundary conditions safely.
* To test the application and maintain the source code in a GitHub repository.

## 3. Technologies Used

| Technology         | Purpose                                       |
| ------------------ | --------------------------------------------- |
| C++                | Implementation of the application             |
| Doubly Linked List | Storage and management of songs               |
| Visual Studio Code | Writing, compiling, and testing the program   |
| GCC / MinGW-w64    | Compilation of the C++ source code            |
| Git                | Version control and tracking project progress |
| GitHub             | Hosting the source code and documentation     |

## 4. Data Structure Used

A **Doubly Linked List** is a linear data structure in which each node contains data and two pointers. The `prev` pointer refers to the previous node, while the `next` pointer refers to the next node.

Each node in this project represents a song and stores its title, artist name, and links to neighbouring songs.

### Node Structure

Conceptually, each song node contains:

* `title`: Name of the song.
* `artist`: Name of the artist.
* `prev`: Pointer to the previous song.
* `next`: Pointer to the next song.

### Important Pointers

| Pointer   | Purpose                                                    |
| --------- | ---------------------------------------------------------- |
| `head`    | Points to the first song in the playlist                   |
| `current` | Points to the currently selected song                      |
| `p`       | Points to a newly allocated node or the node being deleted |
| `q`       | Used to traverse the linked list                           |
| `prev`    | Connects a node to its previous song                       |
| `next`    | Connects a node to its next song                           |

### Example Playlist

`NULL <- Believer <-> Faded <-> Perfect -> NULL`

In this example, `head` points to Believer. If Faded is selected, `current` points to the Faded node.

## 5. Features and Menu Options

The application provides the following operations:

| Option | Operation                   | Description                                                 |
| -----: | --------------------------- | ----------------------------------------------------------- |
|      1 | Add Song                    | Adds a new song to the end of the playlist                  |
|      2 | Delete Song                 | Deletes a song by its title                                 |
|      3 | Display Playlist            | Displays songs from first to last                           |
|      4 | Display Playlist in Reverse | Displays songs from last to first                           |
|      5 | Play Current Song           | Displays the currently selected song                        |
|      6 | Play Next Song              | Moves to the next song                                      |
|      7 | Play Previous Song          | Moves to the previous song                                  |
|      8 | Play Complete Playlist      | Traverses and displays every song in order                  |
|      9 | Repeat All                  | Repeats the complete playlist the specified number of times |
|     10 | Show Current Song           | Displays the currently selected song                        |
|     11 | Exit                        | Terminates the application                                  |
|     12 | Select Current Song         | Selects a song by its title                                 |

Option 12 is an additional feature for demonstrating current-node management. The original 11 required options are retained.

**Note:** Playback is simulated through console output. The application demonstrates playlist navigation and data structure operations; it does not play actual audio files.

## 6. Implementation Details

### Insertion

A new node is dynamically allocated using `new`. If the playlist is empty, the new node becomes `head` and `current`. Otherwise, `q` traverses the list to the last node, and the `next` and `prev` pointers are updated.

### Deletion

The required song is located by traversing the list. The node to be deleted is stored in `p`. The previous and next nodes are reconnected before the node is released using `delete`.

Special cases include deleting the first song, a middle song, the last song, the only song, or a song that does not exist. If the currently selected song is deleted, the program updates `current` to a suitable remaining song.

### Next and Previous Navigation

Next navigation uses `current = current->next`. Previous navigation uses `current = current->prev`.

The program checks the relevant pointer before moving to prevent navigation beyond the first or last song.

### Forward and Reverse Traversal

Forward traversal begins at `head` and follows the `next` pointers until `nullptr`.

Reverse traversal first finds the last node, then follows the `prev` pointers until `nullptr`.

### Repeat All

The Repeat All operation accepts a repetition count and restarts traversal from `head` for each repetition. Each song is displayed in playlist order during every repetition.

### Memory Management

The destructor releases dynamically allocated nodes when the playlist manager is destroyed, helping prevent memory leaks.

## 7. Algorithms and Time Complexity

Let `n` be the number of songs in the playlist.

| Operation              | Time Complexity | Explanation                              |
| ---------------------- | --------------- | ---------------------------------------- |
| Add Song               | O(n)            | Traverses the list to find the last node |
| Delete Song            | O(n)            | Searches for the song by title           |
| Select Current Song    | O(n)            | Searches for the specified title         |
| Display Forward        | O(n)            | Visits every node                        |
| Display Reverse        | O(n)            | Finds the tail and traverses backward    |
| Play Next              | O(1)            | Moves through one pointer                |
| Play Previous          | O(1)            | Moves through one pointer                |
| Play Complete Playlist | O(n)            | Visits every song                        |
| Repeat All             | O(r × n)        | Traverses all songs for `r` repetitions  |

The playlist uses O(n) space to store `n` song nodes.

## 8. Software Setup and Execution

### Prerequisites

* Visual Studio Code
* A compatible C++ compiler, such as GCC through MinGW-w64
* The Microsoft C/C++ extension for VS Code (recommended)

### Compilation

Open the project folder in VS Code and create a terminal using **Terminal → New Terminal**.

Compile the program with:

`g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o playlist.exe`

Run the application in PowerShell with:

`.\playlist.exe`

If the program is stored under a different source filename, replace `main.cpp` with the actual filename.

## 9. Testing and Validation

The program should be tested against all 17 situations specified in the case study.

| No. | Test Case                           | Expected Result                                                 |
| --: | ----------------------------------- | --------------------------------------------------------------- |
|   1 | Empty playlist                      | Appropriate empty-playlist messages; no invalid pointer access  |
|   2 | One song                            | The song becomes the first and current song                     |
|   3 | Multiple songs                      | All songs appear in insertion order                             |
|   4 | Adding songs at different stages    | New songs are linked correctly                                  |
|   5 | Deleting the first song             | `head` moves to the next node                                   |
|   6 | Deleting a middle song              | Neighbouring nodes reconnect correctly                          |
|   7 | Deleting the last song              | The previous node's `next` becomes `nullptr`                    |
|   8 | Deleting a nonexistent song         | An appropriate message is displayed                             |
|   9 | Playing the current song            | The selected song is displayed                                  |
|  10 | Moving to the next song             | `current` moves to the next node                                |
|  11 | Moving to the previous song         | `current` moves to the previous node                            |
|  12 | Moving next from the last song      | Navigation is prevented and a boundary message is shown         |
|  13 | Moving previous from the first song | Navigation is prevented and a boundary message is shown         |
|  14 | Forward playlist display            | Songs are displayed from first to last                          |
|  15 | Reverse playlist display            | Songs are displayed from last to first                          |
|  16 | Repeating the complete playlist     | All songs are displayed for the requested number of repetitions |
|  17 | Exiting the menu                    | The application terminates properly                             |

**Testing record:** Execute each case in VS Code, record the actual result, mark it Pass or Fail, and capture relevant screenshots. Test results should reflect actual execution rather than assumed outcomes.

## 10. Linked-List Diagrams

The case study requires diagrams illustrating the structure and pointer operations. The following seven topics should be included in the `diagrams/` directory.

1. **Initial Playlist:** Show multiple songs with `head`, `current`, `prev`, and `next` pointers.
2. **Insertion:** Show the list before and after adding a song and updating links.
3. **Deletion:** Show the removal of a node and reconnection of its neighbours.
4. **Next Navigation:** Show `current = current->next`.
5. **Previous Navigation:** Show `current = current->prev`.
6. **Reverse Traversal:** Show traversal from the last node using `prev`.
7. **Special Cases:** Show `current` at the first and last songs, or deletion of the first or last node.

Use clearly labelled nodes, directional arrows, and `NULL` labels. Each diagram should match the pointer operations implemented in the source code.

## 11. Repository Structure

The repository can be organized as follows:

```
MusicPlaylistManager/
├── main.cpp
├── .gitignore
├── README.md
├── test_cases.md
├── diagrams/
│   ├── 01_initial_playlist.png
│   ├── 02_insertion.png
│   ├── 03_deletion.png
│   ├── 04_next_navigation.png
│   ├── 05_previous_navigation.png
│   ├── 06_reverse_traversal.png
│   └── 07_special_cases.png
└── screenshots/
    ├── empty_playlist.png
    ├── forward_playlist.png
    ├── reverse_playlist.png
    ├── navigation.png
    └── repeat_all.png
```

The diagram and screenshot filenames are examples. Add these files as you complete the project. The `.gitignore` file should exclude compiled executable files, such as `*.exe`.

## 12. Git and GitHub

Git is used to track changes during development, while GitHub hosts the project repository.

Common commands used to update the repository are:

* `git status` to check working-tree changes.
* `git add .` to stage changes.
* `git commit -m "Describe the change"` to record a commit.
* `git push` to upload commits to GitHub.

Make regular commits for meaningful implementation changes, testing documentation, diagrams, and other project deliverables.

**Repository:** https://github.com/tylerbyrnes7/MusicPlaylistManager

## 13. Team Contributions

This case study is intended for a group of four to five students. Each member should understand the implementation and be prepared for individual evaluation.

Add the actual team information below:

| No. | Student Name                  | Roll Number   |
| --: | ----------------------------- | ------------- |
|   1 | Anshuman Sarve                |     242       |
|   2 | Tejas Patil                   |     229       |
|   3 | Gayatri Darade                |     016       |
|   4 | Radhika Gaikwad               |     015       | 

## 14. Conclusion

The Music Playlist Manager demonstrates the use of a doubly linked list to manage songs dynamically. It applies insertion, deletion, forward and reverse traversal, bidirectional navigation, and current-node management in a menu-driven C++ application.

The project reinforces the relationship between node pointers and data structure operations. Testing boundary cases and maintaining clear documentation helps verify the implementation and prepare students to explain their work during demonstration and viva.

