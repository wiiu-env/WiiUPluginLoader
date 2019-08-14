/* based on module.c
 *   by Alex Chadwick
 *
 * Copyright (C) 2014, Alex Chadwick
 * Modified 2018, Maschell
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _PLUGIN_INFORMATION_H_
#define _PLUGIN_INFORMATION_H_

#include <string>
#include <vector>
#include "utils/logger.h"
#include "utils/ipcclient.h"

class PluginInformation {
public:
    PluginInformation(plugin_information_handle handle, const char * path,  const char * name,  const char * author) {
        this->handle = handle;
        this->path = path;
        this->name = name;
        this->author = author;
    }

    ~PluginInformation() {
        IPC_Delete_Plugin_Information(this->handle);
    }

    std::string getName() {
        return this->name;
    }

    std::string getAuthor() {
        return this->author;
    }

    std::string getVersion() {
        return this->version;
    }

    std::string getLicense() {
        return this->license;
    }

    std::string getBuildTimestamp() {
        return this->buildtimestamp;
    }

    std::string getDescription() {
        return this->description;
    }

    std::string getPath() {
        return path;
    }

    size_t getSize() {
        return this->size;
    }

    plugin_information_handle getHandle() {
        return this->handle;
    }
private:
    void setVersion(const char * version) {
        this->version = version;
    }

    void setLicense(const char * license) {
        this->license = license;
    }

    void setBuildTimestamp(const char * buildtimestamp) {
        this->buildtimestamp = buildtimestamp;
    }

    void setDescription(const char * description) {
        this->description = description;
    }

    void setSize(size_t size) {
        this->size = size;
    }

    plugin_information_handle handle;

    std::string path;
    std::string name;
    std::string author;
    std::string version;
    std::string license;
    std::string buildtimestamp;
    std::string description;

    size_t size = 0;
};


#endif
