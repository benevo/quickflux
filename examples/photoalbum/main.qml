import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.3
import QuickFlux 1.0
import "./views"
import "./scripts"
import "./actions"

Window {
    visible: true
    title: "Photo Album"
    width: 640
    height: 480

    StackView {
        anchors.fill: parent
    }

    ImagePickerScript {
    }

    Component.onCompleted: {
        var errorTypes = {
            0: "Unknown error",
            1: "Permission denied by user",
            2: "Position is not available",
            3: "Request timed out"
        };

        var errorMsg = errorTypes[2]
        console.log(errorMsg)
    }

}

