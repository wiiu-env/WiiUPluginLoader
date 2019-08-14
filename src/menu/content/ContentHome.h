/****************************************************************************
 * Copyright (C) 2016-2018 Maschell
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
#ifndef _CONTENT_HOME_H
#define _CONTENT_HOME_H

#include "gui/Gui.h"
#include "ContentTemplate.h"
#include "language/gettext.h"
#include "custom/gui/DefaultGuiSwitch.h"
#include "plugin/PluginInformation.h"
#include "plugin/PluginLoader.h"


class ContentHome : public ContentTemplate {
public:
    ContentHome();
    virtual ~ContentHome();

private:

    GuiText welcomeHeadLineLabel;

    GuiImageData *twitterLogoImageData;
    GuiImage twitterLogoImage;

    GuiImageData *githubLogoImageData;
    GuiImage githubLogoImage;

    GuiText twitterLabel;

    GuiText URLLabel;

    GuiImageData * homebutton_imgdata;
    GuiImage homebutton_img;

    GuiText exitHome;
    GuiFrame exitHomeFrame;

    GuiImageData * plusbutton_imgdata;
    GuiImage plusbutton_img;

    GuiText exitPlus;
    GuiFrame exitPlusFrame;

    GuiTrigger touchTrigger;
    GuiTrigger wpadTouchTrigger;

    GuiSound *buttonClickSound;

    GuiTrigger buttonATrigger;
    GuiTrigger buttonUpTrigger;
    GuiTrigger buttonDownTrigger;

    GuiButton DPADButtons;

    GuiFrame pluginsFrame;
    PluginLoader * loader = NULL;

    std::vector<GuiElement*> toDelete;
    void OnDPADClick(GuiButton *button, const GuiController *controller, GuiTrigger *trigger);
    void OnValueChanged(GuiToggle * toggle,bool value);
    bool linkPlugins();
    std::map<GuiToggle *, PluginInformation *> pluginMapping;
    std::map<int, GuiToggle *> selectionMapping;
    int selectionMappingMin = 0;
    int selectionMappingMax = 0;
    int selectionMappingCur = -1;

    bool updateButtons = true;

    virtual void update(GuiController * c);
};

#endif //_CONTENT_HOME_H
