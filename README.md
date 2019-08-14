# Wii U Plugin Loader
This is the GUI for the [WiiUPluginSystem](https://github.com/Maschell/WiiUPluginSystem).

## Usage

Use the "Wii U Plugin Loader" to load plugins from the sd card. It is built to be loaded through the homebrew launcher, which can be either loaded with the browser exploit or haxchi.
Plugins needs to be placed into the following folder:

```
sd:/wiiu/plugins
```

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