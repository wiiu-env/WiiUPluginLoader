#ifndef COMMON_H
#define    COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#define CAFE_OS_SD_PATH             "/vol/external01"
#define WIIU_PATH                   "/wiiu"
#define SD_PATH                     "sd:"
#define USB_PATH                    "usb:"
#define DEFAULT_NAME_PACKAGE        "DEFAULT"
#define NAME_PREFIX_SD              "sd: "
#define NAME_PREFIX_USB             "usb:"

#define DEFAULT_WUPSLOADER_PATH     SD_PATH WIIU_PATH "/apps/wiiupluginsystem"
#define DEFAULT_LANG_PATH           DEFAULT_WUPSLOADER_PATH "/languages"
#define LANGUAGE_FILE_EXT           ".lang"
#define PLUGIN_CONFIG_FILE_EXT      ".cfg"
#define PLUGIN_FILE_EXT             ".mod"

#define WUPS_PLUGIN_PATH            SD_PATH WIIU_PATH "/plugins"
#define WUPS_TEMP_PLUGIN_PATH       SD_PATH WIIU_PATH "/plugins/temp"
#define WUPS_TEMP_PLUGIN_FILE       WUPS_TEMP_PLUGIN_PATH "/temp" PLUGIN_FILE_EXT

#define WUPS_SDUSB_MOUNTED_NONE     0
#define WUPS_SDUSB_MOUNTED_FAKE          (1<<0)
#define WUPS_SDUSB_MOUNTED_OS_SD         (1<<1)
#define WUPS_SDUSB_LIBIOSU_LOADED        (1<<2)
#define WUPS_SD_MOUNTED_LIBFAT           (1<<3)
#define WUPS_USB_MOUNTED_LIBFAT          (1<<4)
#define WUPS_USB_MOUNTED_LIBNTFS         (1<<5)

#define WUPS_SD_MOUNTED                  (WUPS_SDUSB_MOUNTED_OS_SD | WUPS_SD_MOUNTED_LIBFAT)
#define WUPS_USB_MOUNTED                 (WUPS_USB_MOUNTED_LIBFAT)

#ifdef __cplusplus
}
#endif

#endif    /* COMMON_H */

