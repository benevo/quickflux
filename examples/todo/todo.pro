TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp

#RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD

# If you install QuickFlux by qpm.pri, change it to include(vendor/vendor.pri)
include(../../quickflux.pri)


# Q_USE_QML_RC ----------------------------------------------------------------
# ![1] search directories.

searchlist += \
    *.qml \
    *.js \
    *.png \
    *.jpg \
    *.gif \
    *.svg \
    *qmldir

for (searchvar, searchlist) {
    qrclist += $$files($$searchvar, true)
}

# ![2] 创建 qml.qrc 文件： 包含qrclist内所有的文件

RESOURCE_CONTENT = \
    "<RCC>" \
    "    <qresource prefix=\"/\"> "

for (qrcvar, qrclist) {
        resourcefileabsolutepath = $$absolute_path($$qrcvar)
        relativepath_in = $$relative_path($$resourcefileabsolutepath, $$PWD)
        RESOURCE_CONTENT += "<file alias=\"$$relativepath_in\">$$relativepath_in</file>"
}

RESOURCE_CONTENT += \
    '    </qresource>' \
    </RCC>

GENERATED_RESOURCE_FILE = $$PWD/qml.qrc
QMAKE_CLEAN += $$GENERATED_RESOURCE_FILE
write_file($$GENERATED_RESOURCE_FILE, RESOURCE_CONTENT)

# ![3] 是否将qml.qrc文件编译到exe
contains(DEFINES,Q_USE_QML_RC){
    message("qml FILES will complied to a .qrc FILE !")
    RESOURCES += $$GENERATED_RESOURCE_FILE  # qml文件编译到qrc文件
    #QMAKE_PRE_LINK += $(DEL_FILE) $$GENERATED_RESOURCE_FILE
} else {
}

OTHER_FILES += $$qrclist

# \end Q_USE_QML_RC----------------------------------------------------------------

