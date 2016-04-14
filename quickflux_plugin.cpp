/*
 * box2dplugin.cpp
 * Copyright (c) 2010-2011 Thorbjørn Lindeijer <thorbjorn@lindeijer.nl>
 * Copyright (c) 2011 Daker Fernandes Pinheiro <daker.pinheiro@openbossa.org>
 * Copyright (c) 2011 Joonas Erkinheimo <joonas.erkinheimo@nokia.com>
 *
 * This file is part of the Box2D QML plugin.
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

#include "quickflux_plugin.h"

#include "qfappdispatcher.h"
#include "qfapplistener.h"
#include "qfappscript.h"
#include "qfapplistenergroup.h"
#include "qfappscriptgroup.h"
#include "priv/qfappscriptrunnable.h"
#include "qffilter.h"
#include "qfkeytable.h"
#include "qfactioncreator.h"

static QObject *appDispatcherProvider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    QFAppDispatcher* object = new QFAppDispatcher();
    object->setEngine(engine);

    return object;
}

const int verMajor = 1;
const int verMinor = 0;

QuickFluxPlugin::QuickFluxPlugin(QObject *parent) :
    QQmlExtensionPlugin(parent)
{
}

void QuickFluxPlugin::registerTypes(const char *uri)
{
#if !defined(STATIC_PLUGIN_QUICKFLUX)
    Q_ASSERT(QLatin1String(uri) == QLatin1String("QuickFlux"));
#endif

    qmlRegisterSingletonType<QFAppDispatcher>(uri, verMajor, verMinor, "AppDispatcher", appDispatcherProvider);
    qmlRegisterType<QFAppListener>(uri, verMajor, verMinor, "AppListener");
    qmlRegisterType<QFAppScript>(uri, verMajor, verMinor, "AppScript");
    qmlRegisterType<QFAppListenerGroup>(uri, verMajor, verMinor, "AppListenerGroup");
    qmlRegisterType<QFAppScriptGroup>(uri, verMajor, verMinor, "AppScriptGroup");
    qmlRegisterType<QFAppScriptRunnable>();
    qmlRegisterType<QFFilter>(uri, verMajor, verMinor, "Filter");
    qmlRegisterType<QFKeyTable>(uri, verMajor, verMinor, "KeyTable");
    qmlRegisterType<QFActionCreator>(uri, verMajor, verMinor, "ActionCreator");
}

