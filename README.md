# Wii U Plugin Loader GUI
This is the GUI for the [WiiUPluginSystem](https://github.com/Maschell/WiiUPluginSystem). Check out the readme for more information about the Plugin System.

## Usage

Load the RPX file using the [Homebrew Launcher](https://github.com/wiiu-env/homebrew_launcher) and control which plugins should be enabled.

Requires the [WiiUPluginSystemBackend](https://github.com/wiiu-env/WiiUPluginLoaderBackend) to be run in the background.

## Building
Make sure you have [wut](https://github.com/devkitPro/wut/) installed.

In addition you need: 
- [libgui](https://github.com/wiiu-env/libgui) for the gui elements.
- The ppc-portlibs `pacman -Syu ppc-portlibs`


# Credits
Some files are based on brainslug by Chadderz:  
https://github.com/Chadderz121/brainslug-wii  
Much stuff also wouldn't be possible without dimok789. He made many great tools and homebrew this stuff in based on (Makefiles, Mocha, homebrew channel, udp logger, dynamic_libs etc.)  
Also thanks to everyone who made actual exploits.  