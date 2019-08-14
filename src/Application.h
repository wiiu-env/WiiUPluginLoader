/****************************************************************************
 * Copyright (C) 2015 Dimok
 * Modified by Maschell, 2018 for Wii U Plugin System loader
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "menu/MainWindow.h"
#include <functional>
#include <gui/video/CVideo.h>
#include <system/CThread.h>
#include "utils/logger.h"
#include <language/gettext.h>

#define APPLICATION_CLOSE_APPLY             1
#define APPLICATION_CLOSE_APPLY_MEMORY      3
#define APPLICATION_CLOSE_MIIMAKER          2

class Application : public CThread {
public:
    static Application * instance() {
        if(!applicationInstance)
            applicationInstance = new Application();
        return applicationInstance;
    }
    static void destroyInstance() {
        if(applicationInstance) {
            delete applicationInstance;
            applicationInstance = NULL;
        }
    }

    CVideo *getVideo(void) const {
        return video;
    }
    MainWindow *getMainWindow(void) const {
        return mainWindow;
    }

    GuiSound *getBgMusic(void) const {
        return bgMusic;
    }

    int32_t exec(void);
    void fadeOut(void);

    void reloadUI(void);

    void quit(int32_t code) {
        exitCode = code;
        exitApplication = true;
        quitRequest = true;
    }

    void setLinkPluginsCallback(std::function<bool(void)> fun) {
        linkPluginsCallback = fun;
        DEBUG_FUNCTION_LINE("Set callback to %08X \n",linkPluginsCallback);
    }
private:
    Application();
    virtual ~Application();

    bool procUI(void);

    static Application *applicationInstance;
    static bool exitApplication;
    static bool quitRequest;

    void executeThread(void);

    void loadLanguageFromConfig();

    GuiSound *bgMusic;
    CVideo *video;
    MainWindow *mainWindow;
    FreeTypeGX *fontSystem;
    GuiController *controller[5];
    int exitCode;
    std::function<bool(void)> linkPluginsCallback = NULL;
};

#endif //_APPLICATION_H
