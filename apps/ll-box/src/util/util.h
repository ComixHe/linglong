/*
 * SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.
 *
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef LINGLONG_BOX_SRC_UTIL_UTIL_H_
#define LINGLONG_BOX_SRC_UTIL_UTIL_H_

#include "common.h"
#include "filesystem.h"
#include "json.h"
#include "macro.h"
#include "semaphore.h"

#include <fstream>

namespace linglong {
namespace util {
namespace json {

inline nlohmann::json fromByteArray(const std::string &content)
{
    return nlohmann::json::parse(content);
}

inline nlohmann::json fromFile(const std::string &filepath)
{
    std::ifstream f(filepath);
    std::string str((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    auto j = fromByteArray(str);
    return j;
}

} // namespace json
} // namespace util
} // namespace linglong

#endif /* LINGLONG_BOX_SRC_UTIL_UTIL_H_ */
