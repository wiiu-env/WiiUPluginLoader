#include <string>
#include "PluginLoader.h"
#include "utils/ipcclient.h"

PluginLoader * PluginLoader::createInstance(uint32_t startAddress, uint32_t endAddress) {
    plugin_loader_handle handle = IPC_Open_Plugin_Loader(startAddress, endAddress);

    if(handle != 0) {
        return new PluginLoader(handle, startAddress,endAddress);
    }
    return NULL;
}

void PluginLoader::destroyInstance(PluginLoader * loader) {
    if(loader != NULL) {
        delete loader;
    }
}


PluginLoader::PluginLoader(plugin_information_handle handle,uint32_t startAddress, uint32_t endAddress) {
    this->handle = handle;
    this->startAddress = startAddress;
    this->endAddress = endAddress;
}

PluginLoader::~PluginLoader() {
    IPC_Close_Plugin_Loader(this->handle);
}

std::vector<PluginInformation *> PluginLoader::getPluginsByPath(const char * path) {
    std::vector<PluginInformation *> result;
    plugin_information_handle * handleList = NULL;
    uint32_t  handleListSize = 0;

    uint32_t res = IPC_Get_Plugin_Information(this->handle, path, &handleList, &handleListSize);
    if(res == 0) {
        DEBUG_FUNCTION_LINE("SUCCESS reading plugins from %s. handleListSize %d, handlelist %08X \n",path, handleListSize, handleList);
        result = getPluginInformationByStruct(handleList, handleListSize);
    }

    if(handleList != NULL) {
        free(handleList);
    }
    return result;
}

std::vector<PluginInformation *> PluginLoader::getPluginsLoadedInMemory() {
    std::vector<PluginInformation *> result;
    plugin_information_handle * handleList = NULL;
    uint32_t  handleListSize = 0;

    uint32_t res = IPC_Get_Plugin_Information_Loaded(this->handle, &handleList, &handleListSize);
    if(res == 0) {
        result = getPluginInformationByStruct(handleList, handleListSize);
    }

    if(handleList != NULL) {
        free(handleList);
    }
    return result;
}

bool PluginLoader::loadAndLinkPlugins(std::vector<PluginInformation *> pluginInformation) {
    uint32_t  handleListSize = pluginInformation.size();

    DEBUG_FUNCTION_LINE("Convert PluginInformation* to plugin_information_handle *\n");

    plugin_information_handle * handleList = (plugin_information_handle *) malloc(handleListSize * sizeof(plugin_information_handle));
    if(handleList == NULL) {
        return false;
    }

    DEBUG_FUNCTION_LINE("Allocation was okay %08X\n", handleList);


    uint32_t cur = 0;
    for (std::vector<PluginInformation *>::iterator it = pluginInformation.begin() ; it != pluginInformation.end(); ++it) {
        PluginInformation * curPlugin = *it;
        handleList[cur] = curPlugin->getHandle();
        DEBUG_FUNCTION_LINE("Adding to List %08X\n", handleList[cur]);
        cur++;
    }
    bool result = false;
    int32_t  res = IPC_Link_Plugin_Information(this->handle, handleList, handleListSize);

    if(res >= 0) {
        DEBUG_FUNCTION_LINE("result was %d\n", res);
        result = true;
    }

    free(handleList);
    return result;
}

std::vector<PluginInformation *> PluginLoader::getPluginInformationByStruct(plugin_information_handle * handleList, uint32_t  handleListSize) {
    std::vector<PluginInformation *> result;

    if(handleListSize > 0) {
        DEBUG_FUNCTION_LINE("Getting details for handles\n");
        plugin_information * informationList = NULL;
        uint32_t informationListSize = 0;
        uint32_t res =  IPC_Get_Plugin_Information_Details(this->handle, handleList, handleListSize, &informationList, &informationListSize);
        if(res == 0) {
            for(uint32_t i = 0; i<informationListSize; i++) {
                DEBUG_FUNCTION_LINE("Adding %08X %s\n", informationList[i].handle, informationList[i].path);
                result.push_back(new PluginInformation(informationList[i].handle,informationList[i].path,informationList[i].name,informationList[i].author));
            }
        } else {
            DEBUG_FUNCTION_LINE("IPC_Get_Plugin_Information_Details failed\n");
        }
        if(informationList != NULL) {
            free(informationList);
        }
    } else {
        DEBUG_FUNCTION_LINE("List is empty.\n");
    }

    return result;
}


void PluginLoader::clearPluginInformation(std::vector<PluginInformation *> pluginInformation) {
    for(size_t i = 0; i < pluginInformation.size(); i++) {
        PluginInformation * curPluginInformation = pluginInformation[i];
        if(curPluginInformation != NULL) {
            delete curPluginInformation;
        }
    }
}
