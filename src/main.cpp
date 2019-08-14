#include <nsysnet/socket.h>
#include <coreinit/ios.h>
#include <sysapp/launch.h>
#include "Application.h"
#include "system/memory.h"
#include "utils/logger.h"
#include "utils/utils.h"
#include "utils/ipcclient.h"
#include "plugin/PluginLoader.h"
#include "plugin/PluginInformation.h"

/* Entry point */
extern "C" int Menu_Main(int32_t argc, char **argv) {
    //!*******************************************************************
    //!                   Initialize function pointers                   *
    //!*******************************************************************
    socket_lib_init();
    //! do OS (for acquire) and sockets first so we got logging
    log_init();

    log_print("Initialize memory management\n");
    memoryInitialize();

    /*PluginLoader * loader = PluginLoader::createInstance(0x00A00000, 0x01000000);
    if(loader != NULL) {
        std::vector<PluginInformation*> plugins = loader->getPluginsByPath("sd:/wiiu/plugins3/");
        uint32_t counter = 0;
        for (std::vector<PluginInformation *>::iterator it = plugins.begin() ; it != plugins.end(); ++it) {
            PluginInformation * curPlugin = *it;
            DEBUG_FUNCTION_LINE("Found plugin %d: %s\n",counter, curPlugin->getPath().c_str());
            counter++;
        }
        loader->loadAndLinkPlugins(plugins);
        loader->clearPluginInformation(plugins);
        plugins.clear();

        std::vector<PluginInformation*> pluginsInMemory = loader->getPluginsLoadedInMemory();
        counter = 0;
        for (std::vector<PluginInformation *>::iterator it = pluginsInMemory.begin() ; it != pluginsInMemory.end(); ++it) {
            PluginInformation * curPlugin = *it;
            DEBUG_FUNCTION_LINE("Is loaded %d: %s\n",counter, curPlugin->getPath().c_str());
            counter++;
        }

        loader->clearPluginInformation(pluginsInMemory);

        delete loader;
    }*/

    //!*******************************************************************
    //!                    Initialize heap memory                        *
    //!*******************************************************************

    log_printf("Start main application\n");
    Application::instance()->exec();

    Application::destroyInstance();

    return 0;
}
