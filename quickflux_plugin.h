/*
 * quickfluxplugin.h
 * Copyright (c) 2010 Thorbjørn Lindeijer <thorbjorn@lindeijer.nl>
 *
 * This file is part of the QuickFlux QML plugin.
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software in
 *    a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef QUICKFLUX_PLUGIN_H
#define QUICKFLUX_PLUGIN_H

#include <QQmlExtensionPlugin>

/**
 * A plugin that exposes QuickFlux to QML in the form of declarative items.
 */
class Q_DECL_EXPORT QuickFluxPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
#if !defined(STATIC_PLUGIN_QUICKFLUX)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
#endif
    Q_PROPERTY(QString objectName1 READ objectName1 WRITE setObjectName1 NOTIFY objectName1Changed)

public:
    explicit QuickFluxPlugin(QObject *parent = 0);

    void registerTypes(const char *uri);

    QString objectName1() const;
    void setObjectName1(const QString &name);

};

#endif // QUICKFLUX_PLUGIN_H
