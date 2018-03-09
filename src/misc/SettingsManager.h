//
// Created by zakrent on 2/19/18.
//

#ifndef SDL_JUMP_SETTINGSMANAGER_H
#define SDL_JUMP_SETTINGSMANAGER_H


#include <map>

class SettingsManager {
    std::map<std::string, int> settings;
public:
    void loadFromFile();
    bool checkIfSettingExists(std::string key);
    int getSetting(std::string key);
    void setSetting(std::string key, int value);

    SettingsManager();
};


#endif //SDL_JUMP_SETTINGSMANAGER_H
