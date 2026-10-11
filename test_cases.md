
# Music Playlist Manager — Test Cases

## 1. Project Information

- **Project:** Music Playlist Manager Using Doubly Linked List
- **Language:** C++17
- **Subject:** Data Structures and Algorithms
- **Course Code:** R25-EC-PCC-202
- **College:** Amrutvahini College of Engineering, Sangamner
- **Testing environment:** Visual Studio Code terminal with GCC/MinGW-w64
- **Source file:** `main.cpp`

## 2. Objective

To verify that the Music Playlist Manager correctly handles song insertion, deletion, forward and reverse traversal, current-song management, next/previous navigation, complete playlist playback, Repeat All, boundary conditions, and menu exit.

## 3. Sample Songs for Testing

Use these 15 songs instead of the previous Believer, Faded, and Perfect examples. Enter the title exactly as written because the program searches for song titles using exact text matching. The artist names below are included to make data entry easier; the program itself does not validate artist identity.

| No. | Song Title | Artist Name to Enter |
|---:|---|---|
| 1 | Softcore | The Neighbourhood |
| 2 | Dracula | Tame Impala |
| 3 | Self Aware | Temper City |
| 4 | Co2 | Prateek Kuhad |
| 5 | Mockingbird | Eminem |
| 6 | Popular | The Weeknd, Playboi Carti & Madonna |
| 7 | As It Was | Harry Styles |
| 8 | Die With A Smile | Lady Gaga & Bruno Mars |
| 9 | The Nights | Avicii |
| 10 | Sailor Song | Gigi Perez |
| 11 | All The Stars | Kendrick Lamar & SZA |
| 12 | Golden Hour | JVKE |
| 13 | Starboy | The Weeknd ft. Daft Punk |
| 14 | Mr.Forgettable | David Kushner |
| 15 | Blinding Lights | The Weeknd |

**How to enter a song:** Select menu option `1`, type its title, press Enter, type the artist name, and press Enter. Repeat for the songs needed by each test. The program starts with an empty playlist each time it is launched; the songs are not loaded automatically.

## 4. Compile and Run

Compile from the VS Code terminal:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o playlist.exe
```

Run in PowerShell:

```powershell
.\playlist.exe
```

## 5. Test Cases

For each test, record the actual output and change the status only after running it. For independent deletion tests, restart the program and add the indicated songs again so each test starts from the stated playlist.

| ID | Requirement | Steps / input | Expected result | Actual result | Status |
|---|---|---|---|---|---|
| TC01 | Empty playlist | Before adding any song, choose options `3`, `4`, `5`, `6`, `7`, `8`, `9` (enter `2`), and `10`. | Display/reverse/play-complete/repeat operations report `Playlist is empty.`; Play Current reports `Playlist is empty; no current song.`; Show Current reports `No song is currently selected.` No crash occurs. |  | Pending |
| TC02 | One song | Add `Softcore` by `The Neighbourhood`; choose `3`, `4`, `5`, and `10`. | Forward and reverse displays contain only Softcore. Current-song operations identify Softcore. Its `prev` and `next` pointers are `nullptr`. |  | Pending |
| TC03 | Multiple songs | Add all 15 songs from the sample-song table in the listed order; choose `3`. | All 15 titles appear once and in the order listed in Section 3. |  | Pending |
| TC04 | Add songs at different stages | Start empty. Add `Softcore`; display. Add `Dracula`; display. Add `Self Aware`; display. Add `Co2`; display again. | Every new song is appended to the end. Existing song order is unchanged. |  | Pending |
| TC05 | Delete the first song | Add `Softcore`, `Dracula`, `Self Aware`; choose `2`, enter `Softcore`, then choose `3`. | Softcore is removed. Playlist order becomes `Dracula`, `Self Aware`. Dracula is the new head and its `prev` is `nullptr`. |  | Pending |
| TC06 | Delete a middle song | Add `Softcore`, `Dracula`, `Self Aware`; choose `2`, enter `Dracula`, then choose `3`. | Dracula is removed. Playlist order becomes `Softcore`, `Self Aware`. The two remaining nodes link to each other in both directions. |  | Pending |
| TC07 | Delete the last song | Add `Softcore`, `Dracula`, `Self Aware`; choose `2`, enter `Self Aware`, then choose `3`. | Self Aware is removed. Playlist order becomes `Softcore`, `Dracula`; Dracula's `next` is `nullptr`. |  | Pending |
| TC08 | Delete a song that does not exist | Add `Softcore` and `Dracula`; choose `2` and enter `Unknown Song`; then choose `3`. | Program displays `Song not found: Unknown Song`. Playlist remains unchanged. |  | Pending |
| TC09 | Play current song | Add `Softcore`, `Dracula`, `Self Aware`; choose `5`, then `10`. Do not navigate or select another song first. | The initial current song is Softcore and is displayed with its artist. |  | Pending |
| TC10 | Move to the next song | Add `Softcore`, `Dracula`, `Self Aware`; with current at Softcore, choose `6` twice. | First move selects Dracula; second move selects Self Aware. |  | Pending |
| TC11 | Move to the previous song | Add `Softcore`, `Dracula`, `Self Aware`; choose `12`, enter `Self Aware`; choose `7` twice. | First move selects Dracula; second move selects Softcore. |  | Pending |
| TC12 | Attempt to move next from the last song | Add all 15 songs; choose `12`, enter `Blinding Lights`; then choose `6`. | Program displays `Already at the last song.` The current song remains Blinding Lights. |  | Pending |
| TC13 | Attempt to move previous from the first song | Add all 15 songs; choose `12`, enter `Softcore`; then choose `7`. | Program displays `Already at the first song.` The current song remains Softcore. |  | Pending |
| TC14 | Display playlist in forward direction | Add all 15 songs in the sample-song order; choose `3`. | Titles appear from Softcore through Blinding Lights in the exact order listed in Section 3. The current song is marked `[CURRENT]`. |  | Pending |
| TC15 | Display playlist in reverse direction | Add all 15 songs in the sample-song order; choose `4`. | Titles appear in reverse order, from Blinding Lights back to Softcore. |  | Pending |
| TC16 | Repeat the complete playlist | Add all 15 songs in the sample-song order; choose `9`; enter `2`. | Two repetitions are displayed. Each repetition starts with Softcore, follows the sample order, and ends with Blinding Lights. |  | Pending |
| TC17 | Exit the menu properly | Choose `11` from the menu. | Program displays `Exiting Music Playlist Manager.` and terminates without showing the menu again. |  | Pending |

## 6. Additional Recommended Tests

These tests extend the 17 required cases and check current-node handling around deletion.

| ID | Requirement | Steps / input | Expected result | Actual result | Status |
|---|---|---|---|---|---|
| AT01 | Select a song as current | Add `Softcore`, `Dracula`, and `Self Aware`; choose `12`, enter `Dracula`; then choose `10`. | Current song changes to Dracula and is displayed correctly. |  | Pending |
| AT02 | Delete the current song | Add `Softcore`, `Dracula`, `Self Aware`; choose `12`, enter `Dracula`; choose `2`, enter `Dracula`; then choose `10`. | Dracula is deleted and current moves to its successor, Self Aware. |  | Pending |
| AT03 | Delete the only song | Start fresh, add only `Softcore`, delete `Softcore`, then choose `3` and `10`. | Playlist becomes empty and no current song remains selected. No crash occurs. |  | Pending |
| AT04 | Repeat with an invalid repetition count | Add `Softcore`; choose `9`; enter `0`. | Program displays `Enter a positive number of repetitions.` and does not start playback. |  | Pending |

## 7. Test Summary

Complete this summary after running the tests.

- Required test cases: **17**
- Additional recommended tests: **4**
- Required tests passed: ____ / 17
- Required tests failed: ____ / 17
- Required tests not run: ____ / 17
- Additional tests passed: ____ / 4

## 8. Conclusion

These tests verify the Music Playlist Manager's doubly linked list operations: node creation, insertion, deletion, forward and reverse traversal, bidirectional navigation, and current-node management. The final test results should be based on actual program execution in Visual Studio Code. Any failed test should be investigated and the program retested before submission.

=======
# Music Playlist Manager — Test Cases

## 1. Project Information

- **Project:** Music Playlist Manager Using Doubly Linked List
- **Language:** C++17
- **Subject:** Data Structures and Algorithms
- **Course Code:** R25-EC-PCC-202
- **College:** Amrutvahini College of Engineering, Sangamner
- **Testing environment:** Visual Studio Code terminal with GCC/MinGW-w64
- **Source file:** `main.cpp`

## 2. Objective

To verify that the Music Playlist Manager correctly handles song insertion, deletion, forward and reverse traversal, current-song management, next/previous navigation, complete playlist playback, Repeat All, boundary conditions, and menu exit.

## 3. Sample Songs for Testing

Use these 15 songs instead of the previous Believer, Faded, and Perfect examples. Enter the title exactly as written because the program searches for song titles using exact text matching. The artist names below are included to make data entry easier; the program itself does not validate artist identity.

| No. | Song Title | Artist Name to Enter |
|---:|---|---|
| 1 | Softcore | The Neighbourhood |
| 2 | Dracula | Tame Impala |
| 3 | Self Aware | Temper City |
| 4 | Co2 | Prateek Kuhad |
| 5 | Mockingbird | Eminem |
| 6 | Popular | The Weeknd, Playboi Carti & Madonna |
| 7 | As It Was | Harry Styles |
| 8 | Die With A Smile | Lady Gaga & Bruno Mars |
| 9 | The Nights | Avicii |
| 10 | Sailor Song | Gigi Perez |
| 11 | All The Stars | Kendrick Lamar & SZA |
| 12 | Golden Hour | JVKE |
| 13 | Starboy | The Weeknd ft. Daft Punk |
| 14 | Mr.Forgettable | David Kushner |
| 15 | Blinding Lights | The Weeknd |

**How to enter a song:** Select menu option `1`, type its title, press Enter, type the artist name, and press Enter. Repeat for the songs needed by each test. The program starts with an empty playlist each time it is launched; the songs are not loaded automatically.

## 4. Compile and Run

Compile from the VS Code terminal:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o playlist.exe
```

Run in PowerShell:

```powershell
.\playlist.exe
```

## 5. Test Cases

For each test, record the actual output and change the status only after running it. For independent deletion tests, restart the program and add the indicated songs again so each test starts from the stated playlist.

| ID | Requirement | Steps / input | Expected result | Actual result | Status |
|---|---|---|---|---|---|
| TC01 | Empty playlist | Before adding any song, choose options `3`, `4`, `5`, `6`, `7`, `8`, `9` (enter `2`), and `10`. | Display/reverse/play-complete/repeat operations report `Playlist is empty.`; Play Current reports `Playlist is empty; no current song.`; Show Current reports `No song is currently selected.` No crash occurs. |  | Pending |
| TC02 | One song | Add `Softcore` by `The Neighbourhood`; choose `3`, `4`, `5`, and `10`. | Forward and reverse displays contain only Softcore. Current-song operations identify Softcore. Its `prev` and `next` pointers are `nullptr`. |  | Pending |
| TC03 | Multiple songs | Add all 15 songs from the sample-song table in the listed order; choose `3`. | All 15 titles appear once and in the order listed in Section 3. |  | Pending |
| TC04 | Add songs at different stages | Start empty. Add `Softcore`; display. Add `Dracula`; display. Add `Self Aware`; display. Add `Co2`; display again. | Every new song is appended to the end. Existing song order is unchanged. |  | Pending |
| TC05 | Delete the first song | Add `Softcore`, `Dracula`, `Self Aware`; choose `2`, enter `Softcore`, then choose `3`. | Softcore is removed. Playlist order becomes `Dracula`, `Self Aware`. Dracula is the new head and its `prev` is `nullptr`. |  | Pending |
| TC06 | Delete a middle song | Add `Softcore`, `Dracula`, `Self Aware`; choose `2`, enter `Dracula`, then choose `3`. | Dracula is removed. Playlist order becomes `Softcore`, `Self Aware`. The two remaining nodes link to each other in both directions. |  | Pending |
| TC07 | Delete the last song | Add `Softcore`, `Dracula`, `Self Aware`; choose `2`, enter `Self Aware`, then choose `3`. | Self Aware is removed. Playlist order becomes `Softcore`, `Dracula`; Dracula's `next` is `nullptr`. |  | Pending |
| TC08 | Delete a song that does not exist | Add `Softcore` and `Dracula`; choose `2` and enter `Unknown Song`; then choose `3`. | Program displays `Song not found: Unknown Song`. Playlist remains unchanged. |  | Pending |
| TC09 | Play current song | Add `Softcore`, `Dracula`, `Self Aware`; choose `5`, then `10`. Do not navigate or select another song first. | The initial current song is Softcore and is displayed with its artist. |  | Pending |
| TC10 | Move to the next song | Add `Softcore`, `Dracula`, `Self Aware`; with current at Softcore, choose `6` twice. | First move selects Dracula; second move selects Self Aware. |  | Pending |
| TC11 | Move to the previous song | Add `Softcore`, `Dracula`, `Self Aware`; choose `12`, enter `Self Aware`; choose `7` twice. | First move selects Dracula; second move selects Softcore. |  | Pending |
| TC12 | Attempt to move next from the last song | Add all 15 songs; choose `12`, enter `Blinding Lights`; then choose `6`. | Program displays `Already at the last song.` The current song remains Blinding Lights. |  | Pending |
| TC13 | Attempt to move previous from the first song | Add all 15 songs; choose `12`, enter `Softcore`; then choose `7`. | Program displays `Already at the first song.` The current song remains Softcore. |  | Pending |
| TC14 | Display playlist in forward direction | Add all 15 songs in the sample-song order; choose `3`. | Titles appear from Softcore through Blinding Lights in the exact order listed in Section 3. The current song is marked `[CURRENT]`. |  | Pending |
| TC15 | Display playlist in reverse direction | Add all 15 songs in the sample-song order; choose `4`. | Titles appear in reverse order, from Blinding Lights back to Softcore. |  | Pending |
| TC16 | Repeat the complete playlist | Add all 15 songs in the sample-song order; choose `9`; enter `2`. | Two repetitions are displayed. Each repetition starts with Softcore, follows the sample order, and ends with Blinding Lights. |  | Pending |
| TC17 | Exit the menu properly | Choose `11` from the menu. | Program displays `Exiting Music Playlist Manager.` and terminates without showing the menu again. |  | Pending |

## 6. Additional Recommended Tests

These tests extend the 17 required cases and check current-node handling around deletion.

| ID | Requirement | Steps / input | Expected result | Actual result | Status |
|---|---|---|---|---|---|
| AT01 | Select a song as current | Add `Softcore`, `Dracula`, and `Self Aware`; choose `12`, enter `Dracula`; then choose `10`. | Current song changes to Dracula and is displayed correctly. |  | Pending |
| AT02 | Delete the current song | Add `Softcore`, `Dracula`, `Self Aware`; choose `12`, enter `Dracula`; choose `2`, enter `Dracula`; then choose `10`. | Dracula is deleted and current moves to its successor, Self Aware. |  | Pending |
| AT03 | Delete the only song | Start fresh, add only `Softcore`, delete `Softcore`, then choose `3` and `10`. | Playlist becomes empty and no current song remains selected. No crash occurs. |  | Pending |
| AT04 | Repeat with an invalid repetition count | Add `Softcore`; choose `9`; enter `0`. | Program displays `Enter a positive number of repetitions.` and does not start playback. |  | Pending |

## 7. Test Summary

Complete this summary after running the tests.

- Required test cases: **17**
- Additional recommended tests: **4**
- Required tests passed: ____ / 17
- Required tests failed: ____ / 17
- Required tests not run: ____ / 17
- Additional tests passed: ____ / 4

## 8. Conclusion

These tests verify the Music Playlist Manager's doubly linked list operations: node creation, insertion, deletion, forward and reverse traversal, bidirectional navigation, and current-node management. The final test results should be based on actual program execution in Visual Studio Code. Any failed test should be investigated and the program retested before submission.

>>>>>>> db18c92 (Update README and add test cases)
