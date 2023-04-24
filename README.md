## Bug Board
this project was developed during the C++ course in the Software Development Bachelor in Dundalk's Institute of Technology.
This was, in fact, a Continous Assessement (CA) for this module.

## Controls :
- up arrow (↑) ⇒ move the Superbug up
- right arrow(→) ⇒ move the Superbug right
- down arrow(↓) ⇒move the Superbug down
- left arrow(←) ⇒move the Superbug left

- left click on a cell : place a flag on it that will highlight on the bug listing on the right the bugs that are in this cell
- R : play music
- S : pause music

If you are on windows, replace lines 7 to 10 of the CmakeLists.txt file by :

```
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.5.1/include)
target_link_libraries(JOAO_Ethan_CA3 sfml-system sfml-window sfml-graphics sfml-audio)
```

You may have to replace the directories in the set(SFML_DIR) and include_directories by the directory your SFML library is located at

