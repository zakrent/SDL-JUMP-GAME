//
// Created by zakrent on 2/19/18.
//

#include "SettingsManager.h"

SettingsManager::SettingsManager() {
    setSetting("resx", 600);
    setSetting("resy", 400);
}

bool SettingsManager::checkIfSettingExists(std::string key) {
    return  settings.find(key) != settings.end();
}

int SettingsManager::getSetting(std::string key) {
    return settings.find(key)->second;
}

void SettingsManager::setSetting(std::string key, int value) {
    settings[key] = value;
}

