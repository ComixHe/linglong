/*
 * Copyright (c) 2022. Uniontech Software Ltd. All rights reserved.
 *
 * Author:     yuanqiliang@uniontech.com
 *
 * Maintainer: yuanqiliang@uniontech.com
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

#include <QDBusArgument>

namespace linglong {
namespace service {
class ParamOption
{
public:
    QString appId;
    QString version;
    QString arch;
};

inline QDBusArgument &operator<<(QDBusArgument &argument, const ParamOption &paramOption)
{
    argument.beginStructure();
    argument << paramOption.appId << paramOption.version << paramOption.arch;
    argument.endStructure();
    return argument;
}

inline const QDBusArgument &operator>>(const QDBusArgument &argument, ParamOption &paramOption)
{
    argument.beginStructure();
    argument >> paramOption.appId >> paramOption.version >> paramOption.arch;
    argument.endStructure();
    return argument;
}

class DownloadParamOption : public ParamOption
{
public:
    QString savePath;
};

inline QDBusArgument &operator<<(QDBusArgument &argument, const DownloadParamOption &downloadParamOption)
{
    argument.beginStructure();
    argument << downloadParamOption.appId << downloadParamOption.version << downloadParamOption.arch
             << downloadParamOption.savePath;
    argument.endStructure();
    return argument;
}

inline const QDBusArgument &operator>>(const QDBusArgument &argument, DownloadParamOption &downloadParamOption)
{
    argument.beginStructure();
    argument >> downloadParamOption.appId >> downloadParamOption.version >> downloadParamOption.arch
        >> downloadParamOption.savePath;
    argument.endStructure();
    return argument;
}

class InstallParamOption : public ParamOption
{
public:
    bool nodbus = false;
    QString repoPoint;
};

inline QDBusArgument &operator<<(QDBusArgument &argument, const InstallParamOption &installParamOption)
{
    argument.beginStructure();
    argument << installParamOption.appId << installParamOption.version << installParamOption.arch
             << installParamOption.nodbus << installParamOption.repoPoint;
    argument.endStructure();
    return argument;
}

inline const QDBusArgument &operator>>(const QDBusArgument &argument, InstallParamOption &installParamOption)
{
    argument.beginStructure();
    argument >> installParamOption.appId >> installParamOption.version >> installParamOption.arch
        >> installParamOption.nodbus >> installParamOption.repoPoint;
    argument.endStructure();
    return argument;
}

} // namespace service
} // namespace linglong

Q_DECLARE_METATYPE(linglong::service::ParamOption)
Q_DECLARE_METATYPE(linglong::service::DownloadParamOption)
Q_DECLARE_METATYPE(linglong::service::InstallParamOption)